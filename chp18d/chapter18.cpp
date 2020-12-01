#include "std_lib_facilities.h"

int ga[10] = {1,2,4,8,16,32,64,128,256,512} ;

void f(int array[],int arg){

	int la[10]= {} ;
	for (int i = 0; i < arg; ++i)
	{
		la[i] = array[i];
	}
	for (int i = 0; i < arg; ++i)
	{
		cout << la[i] << endl;
	}

	int* p = new int[arg] ;
	for (int i = 0; i < arg; ++i)
	{
		p[i] = array[i];
	}
	for (int i = 0; i < arg; ++i)
	{
		cout << p[i] << endl;
	}

	delete[] p;
	

}

int main()
{

	cout<< "content of ga: " << endl;
	f(ga,10);


	int aa[10] = {1,1*2,1*2*3,1*2*3*4,1*2*3*4*5,1*2*3*4*5*6,1*2*3*4*5*6*7,1*2*3*4*5*6*7*8,1*2*3*4*5*6*7*8*9,1*2*3*4*5*6*7*8*9*10};

	cout<< "factorial array: " << endl;

	f(aa,10);



	return 0;
}