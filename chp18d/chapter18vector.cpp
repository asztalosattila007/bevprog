#include "std_lib_facilities.h"

vector<int> gv = {1,2,4,8,16,32,64,128,256,512};

void f(vector<int> a) {
	vector<int> lv(10) ;
	lv = a;
	for ( int i = 0; i < lv.size();++i){
		cout << lv[i] << endl;
	}
	vector<int> lv2 = a;
	for ( int i = 0; i < lv2.size();++i){
		cout << lv2[i] << endl;
	}
}


int main()
{
	f(gv);
	vector<int> vv = {1,1*2,1*2*3,1*2*3*4,1*2*3*4*5,1*2*3*4*5*6,1*2*3*4*5*6*7,1*2*3*4*5*6*7*8,1*2*3*4*5*6*7*8*9,1*2*3*4*5*6*7*8*9*10};
	f(vv);

	return 0;
}