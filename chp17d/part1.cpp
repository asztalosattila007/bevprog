#include "std_lib_facilities.h"

 void print_array10(ostream& os, int* a)  //4.rész
 {
 	for (int i= 0 ; i< 10; i++)
 		os << a[i] << "\n";
 }
 void print_array(ostream& os, int* a, int n) //7.rész
 {
 	for (int i= 0 ; i< n ; i++)
 		os << a[i] << "\n";
 }

 void print_vector(ostream& os, vector<int>& v ,int n)
 {
 	for (int i= 0 ; i< n; i++)
 		os << v[i] << "\n";
 }

 int main()
 {
 	cout<< "1.tömb:" << endl;
	int* array1 = new int[10] {1,2,3,4,5,6,7,8,9,10};  // tömb[0-9]-ig   //1.rész

	for (int i= 0 ; i < 10; i++) cout << array1[i] << endl;    //2.rész


		delete[] array1;                 //3.rész


	cout<< "2.tömb:" << endl;

 	int* array2 = new int[10] {100,101,102,103,104,105,106,107,108,109};//5.rész


 	print_array10(cout,array2);

 	delete[] array2;

 	cout<< "3.tömb:" << endl;

         int* array3 = new int[11] {100,101,102,103,104,105,106,107,108,109,110};//6.rész

         for (int i= 0 ; i< 11; i++) cout << array3[i] << endl;


         	delete[] array3;

         cout<< "4.tömb:" << endl;

     int* array4 = new int[20]; //{100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119}; //8.rész

     int x = 100;
     for (int i = 0; i < 20; ++i) {
     	array4[i] = x;
     	++x;
     }
    //for(int i= 0 ; i< 20; i++) cout << array4[i] << endl;
     print_array(cout,array4,20);

     delete[] array4;

// //the vector part:
     cout << "1.vektor" << endl;
     vector<int> v1 = {100,101,102,103,104,105,106,107,108,109};
      //for(int i= 0 ; i< 10; i++) cout << v1[i] << endl;
      //vector<int>* v3= new vector<int>();
     print_vector(cout,v1,10);


     cout << "2.vektor" << endl;
     vector<int> v2 = {100,101,102,103,104,105,106,107,108,109,110};
      //for(int i= 0 ; i< 10; i++) cout << v2[i] << endl;
     print_vector(cout,v2,11);

     cout << "3.vektor" << endl;
     vector<int> v3 = {100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119} ;
     print_vector(cout,v3,20);


     return 0;
 }