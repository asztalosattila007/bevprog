#include "std_lib_facilities.h"

void swap_v(int a,int b){
 int temp; temp = a, a=b; b=temp;
}

void swap_r(int& a,int& b){
 int temp; temp = a, a=b; b=temp;
}

void swap_cr(const int& a, const int& b){
 int temp; temp = a, a=b; b=temp;
}
int main (){

	int x = 7;
	int y = 9;
	swap_v(x,y);     //lefordítódik,azonban nincs csere                         //     replace ? by v, r, or cr
	 swap_r(x,y);     //  lefordítódik és csere                       //     replace ? by v, r, or cr
	swap_cr(x,y);                           //     replace ? by v, r, or cr
	swap_v(7,9);      //lefordítódik,de nem csinál semmit
	swap_r(7,9);      // nem fordítódik le
	swap_cr(7,9);
	 cout << "x értéke:" << x << " y értéke:" << y << '\n';
	const int cx = 7;
	const int cy = 9;
	swap_v(cx,cy);
	swap_r(cx,cy);
	swap_cr(cx,cy);
	swap_v(7.7,9.9);  //lefordítódik de nem csinál semmit
	swap_r(7.7,9.9);  //nem fordítódik le
	swap_cr(7.7,9.9);
	cout << "cx értéke: " << cx << " cy értéke: " << cy << '\n';
	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx,dy);    //lefordítódik,de nem csinál semmit
	swap_v(7.7,9.9);
		cout << "dx értéke: " << dx << " dy értéke: " << dy << '\n';

}