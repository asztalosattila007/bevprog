/*
	calculator08buggy.cpp
	Helpful comments removed.
	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "std_lib_facilities.h"

constexpr char number = '8'; //szimbolikus állandó a számhoz
constexpr char let = 'L';
constexpr char quit = 'Q';  //szimbolikus állandó a kilépéshez (szimbolikus állandó előnye hogy csak egy helyen kell módosítani)
constexpr char print = ';';
constexpr char name = 'a';
const string declkey = "let";
constexpr string sqrtkey = "sqrt";
constexpr char square_root = '@';
const char prompt = ">";
const char result = "=";
//const string quitkey = "quit";

double expression();                 //az expression prototípusa (mivel a primary után lett deklarálva)
bool is_declared();

class Token {
public:
	char kind;   //típus
	double value; //érték
	string name;  //név
	Token(): kind(0) {}    //alapértelmezett konstruktor (nem kötelező)
	Token(char ch) :kind(ch), value(0) { }    //konstuktor függvények
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string s) :kind(ch), name(s) { }
};

class Token_stream {
	
public:                                        //publikus rész
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void putback(Token t); //A tokent visszateszi a streambe későbbi használatra

	void ignore(char c); //megadjuk hogy melyik karakterig töröljük a token_stream-ben a kifejezéseket
private:                            //privát rész(implementációhoz kell)
	bool full;  //nyílvántartjuk vele hogy van bufferban valami
	Token buffer;  // buffer :1 tokent bele tudunk tenni
};

Token_stream::Token_stream()
:full(false), buffer(0)    // Token stream definiálása(Token_stream függv Token_stream osztályon belül definiáljuk)
{
}

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer"); //ha a stream tele van: error
    buffer = t;       // copy t to buffer
    full = true;      //jelezzük vele hogy a  buffer megtelt
}


Token Token_stream::get() // Token stream get függvénye
{
	if (full) { full = false; return buffer; }  //ha van a bufferben egy token akkor azt adja vissza. Mielőtt visszadjuk a full-t falsera állítjuk
	char ch;
	cin >> ch;           //itt olvassa be
	switch (ch) {         //esetek beolvasáskor.
	case quit:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case print:
	case '=':
		return Token(ch); //token a ch operátorral : meg fog jelenni a kind-ban és a t.kind-ot így lehet leképezni.
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.putback(ch); //a karaktereket visszatesszük a standard inputba
	double val = 0;  //számok esetén
	cin >> val;
	return Token(number, val);  //szám típusú token az értéket visszaadja (a primary függvénynél kell)
	}
	default:
		if (isalpha(ch)) {     //isalpha igazzal tér vissza ha a kapott paraméter betü
			string s;
			s += ch;         //a string s-hez hozzácsatoljuk a karaktert
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;  //amíg betü vagy szám (nem lehet spéci karakter pl:#)
			cin.putback(ch);
			if (s == declkey) return Token{let};   //Let tipusú tokennel tér vissza amit a statementben vizsgál
			//if (s == quitkey) return Token(quit);
			else if(s == sqrtkey) return Token{square_root};
			else if (is_declared(s))
				return Token(number, get_value(s));
			return Token{name, s};
		}
		error("Bad token");  //egyéb esetben bad token errort ír ki
	}
}

void Token_stream::ignore(char c)  //hiba esetén törli a karaktereket és a buffereket így újra tudunk próbálkozni
{
	if (full && c == buffer.kind) { //ha tele van a buffer és pontosvessző van a bufferban
		full = false;                 // full hamis lesz (buffer nem lesz tele)
		return; 
	}
	full = false;  //buffer ürítés

	char ch;
	while (cin >> ch) //karakterenként olvassa a bemenetet
		if (ch == c) return; //ha az a karakter amit keresünk (a ';') akkor visszatér a calculate()-hez
}

class Variable { //változó
	string name;  //neve
	double value; //értéke
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;   //változókat tároló vektor var_table


double define_name(string var, double val){      //név definiálása (változó név,érték)
    if(is_declared(var)) error("Variable is declared: ", var);       //megnézi hogy ezen a néven van e változó deklarálva, ha van, akkor error
    names.push_back(Variable{var,val});             //ha nincs akkor beleteszi a Variable vektor végébe
    return val;
}

double get_value(string s)   //egy változó értékét kérjük el
{
	for (int i = 0; i < names.size(); ++i)               //for (const auto& v : names -t is lehet használni)
		if (names[i].name == s) return names[i].value;    //if (v.name == s) return v.value
	error("get: undefined name ", s);
}

void set_value(string s, double d) //beállítjuk a változó  értéket,  
{
	for (int i = 0; i <= names.size(); ++i)          //for (auto& v: names)
		if (names[i].name == s) {                     // if (v.name == s){ v.value = d; return;}
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string var)   //változónak átadunk egy nevet
{
	for (int i = 0; i < names.size(); ++i)   //végig megy a vektoron. for(const auto& v: names) is jó.
		if (names[i].name == var) return true;  // ha találunk olyan nevet, ami ugyanaz,amit keresünk, akkor igaz.
	return false;
}


Token_stream ts; // globális változó (ha kell egy token token_stream-től kell bekérni)

double calc_sqrt(){
	char ch;
	if(cin.get(ch) && ch != '(') error (" '(' expected");
	cin.putback(ch);
	double d = expression();
	if(d < 0) error("sqrt: negative value");
	return sqrt(d);
}

double primary()
{
	Token t = ts.get();  //a ts.get olvas be
	switch (t.kind) {    //milyen tipusa van a tokennek
	case '(':                      // '(' kifejezés ')'
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("')' expected");  // ha nem ')'-t írunk errort írki
	return d;
	}
	case '-':                //negatív számok esete: -  jelet írunk a szám elé.
		return - primary();
	case '+':                //ha + jelet írunk a szám elé
	    return primary();
	case number:
		return t.value;
	case square_root: //
	    return calc_sqrt();
	//case name:
		//return get_value(t.name);
	default:
		error("primary expected");
		return 0;
	}
}

double term()                    //szorzás osztás
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		t = ts.get();
		break;
		}
		case '%':   // opcionális 
		{
			double d = primary();
			if (d == 0) error("%: zero divider"); // ha nullát írunk a moduló jel(%) után.
			left = fmod (left, d);  // fmod függvény segítségével lehet törtekkel használni a modulót
			t = ts.get();
		}
		default:
			ts.putback(t); //ha nem szorzás(*) vagy osztás(/) akkor visszateszi a tokent a tokenstream-be
			return left;
		}
	}
}

double expression()              //összeadás és kivonás
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);  //ha nem összeadás(+) vagy kivonás(-) akkor azt a tokent visszateszi a tokenstream-be
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration"); //ha a token típusa nem név (pl:let 2 = 4;)
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();  // Itt ellenőriizzük,hogy egyenlőségjel jön-e utána.
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();    //változó értéke
	define_name(name, d);    //define_name nélkül:  names.push_back(Variable(name, d));    A változó elkészítése(neve,értéke)
	return d;
}

double statement()   //itt döntjük el hogy "let" jön vagy expression
{
	Token t = ts.get();
	switch (t.kind) {
	case let:   //kulcsszó -e a let?
		return declaration(); // let esetén visszatér a declaration fv-hez
	default:
		ts.putback(t); // Vissza teszi a tokent (amit a Token t = ts.get() kivett) ha nem declaration
		return expression(); //expression fv-t hívja
	}
}

void clean_up_mess()
{
	ts.ignore(print);   // ';'-ig ignorálja a kifejezést
}


void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get(); //addig kérjük a következő tokent amíg a printhez nem jutunk.
		if (t.kind == quit) return;  //ha a token kilépés akkor visszatér a main() függvényhez (végzett a calculate-el)
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();  //ez a függvény törli a rossz kifejezéseket amelyeket a token_streamben az ignore() választ ki.
	}
}

int main()                            //eredmény kiíratás

try {

	calculate();  //calculate függvényben a kiíratás és kilépés
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}