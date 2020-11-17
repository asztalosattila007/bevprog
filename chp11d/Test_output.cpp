#include "std_lib_facilities.h"
struct Data 
{
	string first_name;
	string last_name;
	int age;
	string telephone_number;
	string email_address;

};
void input_data(Data& name,string first,string last, int age,string phone,string email){
	name.first_name = first;
	name.last_name = last;
	name.age = age;
	name.telephone_number = phone;
	name.email_address = email;
}
/*ostream& operator<<(ostream& os, Data& d)
{
	return os << "|" << setw(3) << d.first_name << ' ' << d.last_name << setw(3)<<"|"<< d.age << setw(3) <<"|"<< d.telephone_number << setw(3) <<"|" <<setw(3)<< d.email_address << setw(3)<<"|"<< endl;
}*/

int main()
try{

	int birth_year = 2002;
	int my_age = 18;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	Data a1;
	Data b1;
	Data c1;
	Data d1;
	Data e1;
	input_data(a1,"Adam","Jensen",21,"0620123456","jensenadam@gmail.com");
	input_data(b1,"Leeroy","Jenkins",32,"0630342532","lerroyjenkins@gmail.com");
	input_data(c1,"Rick","Astley",54,"0630754532","nevergonnagiveyouup@gmail.com");
	input_data(d1,"Pál","Inka",32,"0640423412","inkapaal@gmail.com");
	input_data(e1,"Lakatos","Tihamér",20,"0640973412","lakatostihameer@gmail.com");

cout << birth_year << "\t(decimal)\n" << hex << birth_year           //without showbase
<< "\t(hexadecimal)\n" << oct << birth_year 
<< "\t(octal)\n" << '\n';

cout << my_age << "\t(decimal)\n" << hex            
<< my_age << "\t(hexadecimal)\n" << oct
<< my_age << "\t(octal)\n"<< '\n';

cout << showbase << dec;
 cout << birth_year << "\t(decimal)\n" << hex << birth_year              //with showbase
 << "\t(hexadecimal)\n" << oct << birth_year 
 << "\t(octal)" << '\n';
 cout << noshowbase << dec << '\n';


cin >> a >>oct >> b >> hex >> c >> d;    //write in code: 1234 1234 1234 1234
cout << a << '\t'<< b << '\t'<< c << '\t'<< d << '\n' << '\n';

cout << 1234567.89 << "\t(defaultfloat)\n" 
<< fixed << 1234567.89 << "\t(fixed)\n" 
<< scientific << 1234567.89 << "\t(scientific )\n" << '\n';
//setprecision()


string my_first_name = "Asztalos";
string my_last_name = "Attila";
//dont forget my_age
string my_telephone_number = "06209112001";
string my_email_address = "asztalosattila@gmail.com";

cout << "|" << my_first_name << ' ' << my_last_name << setw(3)<<"|"<< my_age << setw(3) <<"|"<< my_telephone_number << setw(2) <<"|" <<setw(3)<< my_email_address << setw(8)<<"|"<< endl;
cout << "|" << setw(8) << a1.first_name << ' ' << a1.last_name << setw(3)<<"|"<< a1.age << setw(3) <<"|"<< a1.telephone_number << setw(3) <<"|" <<setw(3)<< a1.email_address << setw(12)<<"|"<< endl;
cout << "|" << setw(7) << b1.first_name << ' ' << b1.last_name << setw(3)<<"|"<< b1.age << setw(3) <<"|"<< b1.telephone_number << setw(3) <<"|" <<setw(3)<< b1.email_address << setw(9)<<"|"<< endl;
cout << "|" << setw(8) << c1.first_name << ' ' << c1.last_name << setw(3)<<"|"<< c1.age << setw(3) <<"|"<< c1.telephone_number << setw(3) <<"|" <<setw(3)<< c1.email_address << setw(3)<<"|"<< endl;
cout << "|" << setw(11) << d1.first_name << ' ' << d1.last_name << setw(3)<<"|"<< d1.age << setw(3) <<"|"<< d1.telephone_number << setw(3) <<"|" <<setw(3)<< d1.email_address << setw(14)<<"|"<< endl;
cout << "|" << e1.first_name << ' ' << e1.last_name << setw(3)<<"|"<< e1.age << setw(3) <<"|"<< e1.telephone_number << setw(3) <<"|" <<setw(3)<< e1.email_address << setw(7)<<"|"<< endl;

} catch (exception& e){
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "exception\n";
	return 2;
}



