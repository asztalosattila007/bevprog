#include "std_lib_facilities.h"
void print_array(ostream& os, int* a, int n)  
{
	for (int i= 0 ; i< n ; i++)
		os << a[i] << "\n";
}

int main()
{
	
	int init = 7;                   // 1 .fel inicializált változó
	int* p1 = &init;

	cout<<"content of p1= " << *p1 << endl;   //2.
	cout<<"p1= " << p1 << endl;

	int* p2 = new int[7]{1,2,4,8,16,32,64};   //3.
	


	cout<<"p2=  " << p2 << endl;           //4.fel
	cout<<"content of p2=  " << endl;          

	print_array(cout,p2,7);


	int* p3 = p2;                //5.

	p2 = p1;               //6.
	p2 = p3;               //7.
	cout<<" p1=  " << p1 << endl;              //8.
	cout<<"content of p1= " << *p1 << endl;

    //print_array(cout,p1,7);
	cout<<"p2=  " << p2 << endl;
	cout<<"content of p2=  " << endl;
	print_array(cout,p2,7);
	
	
	            //9.   p2= p1 és p2=p3 
	
	delete[] p3;    // p2 = p3 miatt lehet delete[] p2; is
	



	int tomb2[10] = {1,2,4,8,16,32,64,128,256,512};      //10.

	p1 = tomb2;

	//cout << p1 << endl;    //címet írja ki
	//cout << *p1 << endl;    // 0. elemét írja ki a tömbnek

	int tomb3[10] ;                   //11.
	p2 = tomb3;

	cout << "content of p2[10]= " << endl;

	for (int i = 0; i < 10; ++i)    //12
	{
		p2[i]=p1[i];
	}

	print_array(cout,p2,10);

	cout << " content of p2 vector=" << endl;

	vector<int> v1 = {1,2,4,8,16,32,64,128,256,512};
	vector<int> v2 ;
	v2 = v1;

	for (int i= 0 ; i< v2.size(); i++) {
		cout << v2[i] << "\n";
	}


	return 0;
}
