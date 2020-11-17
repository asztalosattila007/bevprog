#include "std_lib_facilities.h"

struct Point {
	double x;
	double y;
};


int main() 
try{
	vector<Point> original_points;
	double x;
	double y;

	cout << "Please enter seven (x,y) pairs.(You can use only numbers.)" << endl;
	for (int i = 1; i <= 7; )
	{
		
		cout << i << ". pár: "<< endl;
		cin >> x >> y;
		if (cin.fail()) { 
			cin.clear();
			cout<<"Error: Not number!"<< '\n';

			cin.ignore(numeric_limits<streamsize>::max(),'\n');  //
			
		}
		else {
			original_points.push_back(Point{x,y});
			i++;
		}

	}
	cout << "original_points vector: " << endl;
	for (const auto& p : original_points)
		cout << p.x << ' ' << p.y << endl;


	ofstream ost {"mydata.txt"};
	for (const auto& p : original_points)
		ost << p.x << ' ' << p.y << "\n";
	ost.close();

	ifstream ist {"mydata.txt"};
	vector<Point> processed_points;

	while(ist >> x >> y){
		processed_points.push_back(Point{x,y});
	}
	cout << "processed_points vector: " << endl;

	for (const auto& p : processed_points){

		cout << p.x << ' ' << p.y << endl;
	}

	if (original_points.size() != processed_points.size() ) 
	{
		cout << "Something's wrong!" << endl;
	}

	for (int i = 0; i < original_points.size(); ++i)
	{
		
		if (original_points[i].x != processed_points[i].x && 
			original_points[i].y != processed_points[i].y)
			cout << "Something is wrong" << endl;
	}
} catch (exception& e){
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "exception\n";
	return 2;
}