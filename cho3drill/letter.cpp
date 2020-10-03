#include "std_lib_facilities.h"

int main()
{
  cout << "Enter the name of the person you want to write to.\n"; //a címzett neve //
	string first_name;
	cin >> first_name;
	cout << "Dear " << first_name << "!\n";
  
  cout << "How are you? I miss you. I hope everything is okay with you.\n"; // barát neve//
    string friend_name;
    cout << "Enter the name of your friend.\n";
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " lately?\n";
char friend_sex = 0;
  
  cout << "Enter the gender of your friend(m/f).";  //barát neme//

  cin >> friend_sex;
  
	if (friend_sex == 'm')
		cout << "If you see " << friend_name << " please ask him to call me.\n";
	if (friend_sex == 'f')
		cout << "If you see " << friend_name << " please ask her to call me.\n";
 int age;

cout << "Enter the age of the recipient.\n"; //a címzett életkora//
 cin >> age;
	if (age < 0 || age > 110) simple_error("you're kidding!");
	if (age > 12) cout << "Next year you will be " << age+1 << ".\n";
	if (age == 17) cout << "Next year you will be able to vote.\n";
	if (age >70) cout << "I hope you are enjoying retirement.\n";
cout << "Enter your name!\n";
string my_name;	
cin >> my_name;	
cout <<"Yours Sincerely, \n\n\n";		
cout << my_name << endl;
return 0;
}
