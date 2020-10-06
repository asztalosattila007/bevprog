#include "std_lib_facilities.h"

int main()
{
	constexpr double inch_meter = 0.0254;          //---innentől
	constexpr double cm_meter = 0.01;
	constexpr double feet_meter= 0.3048;
	double a = 0, smallst = 0, lrgst = 0 ;   // a= a beírt számmal 
	double entered_v=0;
	double sum_in_meter=0;
	string unit;
	vector<double> values;
	string lrgst_unit;
	string smallst_unit;

	double in_meter = 0;

	

	while(cin >> a >> unit){

		if (unit == "cm")
			in_meter = a * cm_meter ;       //in_meter = a beírt szám méterre átváltott alakja.
			else if (unit == "m")
			in_meter = a;	
			else if (unit == "in")
				in_meter = a * inch_meter ;
			else if (unit == "ft")
				in_meter = a * feet_meter ;

	// switch (unit){
	// 	case 'cm':
 //    in_meter = a * cm_meter ;             
	// 	break;
	// 	case 'm':
 //    in_meter = a;
	// 	break;                              <----A switch csak integerekkel működik
	// 	case 'in':
 //    in_meter = a * inch_meter ;
	// 	break;
	// 	case 'ft':
 //    in_meter = a * feet_meter ;
	// 	break;
			//}
	

		if (unit == "cm" || unit == "m" || unit == "in" || unit == "ft"){
		

		if (smallst == 0) {
                smallst = a;
                
            }
        if(lrgst == 0){
           lrgst = a;


        }    
        if (a < smallst) {
                smallst = a;
                smallst_unit= unit;
                cout << "smallest so far\n";
            } 
            else if (a > lrgst) {
                lrgst = a;
                lrgst_unit= unit;
                cout << "largest so far\n";
            }
        }
        else cout<< "Illegal unit! "<< endl;

            values.push_back(in_meter);
           ++entered_v;
           sum_in_meter += in_meter;

       }
       
       cout << "Results:\n";
       cout << "Smallest value: "<< smallst << " " << smallst_unit << endl;
       cout << "Largest value: "<< lrgst << " " << lrgst_unit <<endl;
       cout << "Number of entered values: "<< entered_v << endl;
       cout << "Sum of values in meter: "<< sum_in_meter << " m\n";
       cout << "Entered numbers in meter:\n";
       sort(values);
       for(double enumbers : values)
       	 cout << enumbers << " m\n";                                   //------idáig  6-11.feladat

	// 
	// 	cout << "a=" << a << "b=" << b << endl;            //1-5.fel.

	// 	if(a < b)
	// 		cout<< "the larger value is:" << b << endl;
	// 	else
	// 		cout<< "the smaller value is:" << b << endl;
	// 	if(b < a)
	// 		cout<< "the larger value is:" << a << endl;
	// 	else
	// 		cout<< "the smaller value is:" << a << endl;
	// 	if(a == b)
	// 		cout<< "the numbers are equal\n";
	// 	if (abs(a - b) <= 0.01) cout << "the numbers are almost equal\n"; 

    return 0;

	}