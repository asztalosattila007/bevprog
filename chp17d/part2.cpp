#include "std_lib_facilities.h"
void print_array(ostream& os, int* a, int n)  
{
	for (int i= 0 ; i< n ; i++)
		os << a[i] << "\n";
}

int main()
{
	
	int* p1 = new int(7);

	cout<<"content of p1= " << *p1 << endl;
	cout<<"p1= " << p1 << endl;

	int* p2 = new int[7] {1,2,4,8,16,32,64};

	cout<<"p2=  " << p2 << endl;
	cout<<"content of p2=  " << endl;

	print_array(cout,p2,7);




	int* p3 = new int[7] {1,2,4,8,16,32,64};

	*p2 = *p1;
	*p2 = *p3;
	cout<<"p1=  " << p1 <<endl;
	
	cout<<"content of p1= " << *p2 << endl;
//print_array(cout,p1,7);
	cout<<"p2=  " << p2 <<endl;
	cout<<"content of p2=  " << endl;
	print_array(cout,p2,7);
	
	delete p1;
	delete[] p2;
	delete[] p3;

	return 0;
}