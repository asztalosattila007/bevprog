#include "std_lib_facilities.h"

// void swap_v(int a,int b){
//  int temp; temp = a, a=b; b=temp;
// }

void swap_r(int& a,int& b){
	int temp; temp = a, a=b; b=temp;
}

 //void swap_cr(const int& a, const int& b){
  //int temp; temp = a, a=b; b=temp;
 //}
int main (){

	int x = 7;
	int y = 9;
	//swap_v(x,y);     //Lefordul, Nincs csere                    //     replace ? by v, r, or cr
	  swap_r(x,y);     //  Lefordul,végrehajtódik a csere              //     replace ? by v, r, or cr
	 //swap_cr(x,y);       //Error , nem fordul le             //     replace ? by v, r, or cr
	 //swap_v(7,9);      //Lefordul, Nincs csere 
	// swap_r(7,9);      //Error , nem fordul le  
	// swap_cr(7,9);     //Error , nem fordul le 
	  cout << "x értéke:" << x << " y értéke:" << y << '\n';
	// const int cx = 7;
	// const int cy = 9;
	// swap_v(cx,cy);   //Lefordul,csere nincs
	// swap_r(cx,cy);   //Nem fordul le,error
	// swap_cr(cx,cy);  //Nem fordul le,error
	// swap_v(7.7,9.9);  //Lefordul,csere nincs
	// swap_r(7.7,9.9);  //Nem fordul le,error
	// swap_cr(7.7,9.9);  //Nem fordul le,error
	// cout << "cx értéke: " << cx << " cy értéke: " << cy << '\n';
	// double dx = 7.7;
	// double dy = 9.9;
	// swap_v(dx,dy);    //Lefordul,csere nincs
	 //swap_r(dx,dy);    //Nem fordul le,error
	 //swap_cr(dx,dy);   //Nem fordul le,error
	// swap_v(7.7,9.9);  //Lefordul, de nincs csere
	 // swap_r(7.7,9.9);    //Nem fordul le,error
	 // swap_cr(7.7,9.9);    //Nem fordul le,error
	// 	cout << "dx értéke: " << dx << " dy értéke: " << dy << '\n';

	}
