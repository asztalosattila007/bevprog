#include "std_lib_facilities.h"

int main()
{
	double a = 0, b = 0;
	while(cin >> a >> b)
	{
		cout << "a=" << a << "b=" << b << endl;

		if(a < b)
			cout<< "the larger value is:" << b << endl;
		else
			cout<< "the smaller value is:" << b << endl;
		if(b < a)
			cout<< "the larger value is:" << a << endl;
		else
			cout<< "the smaller value is:" << a << endl;
		if(a == b)
			cout<< "the numbers are equal\n";
		if (abs(a - b) <= 0.01) cout << "the numbers are almost equal\n";
	}	
    return 0;

	}