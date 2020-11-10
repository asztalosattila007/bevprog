#include "std_lib_facilities.h"
class Date
{
	int year,month,day;
public:	
	class Invalid {};
	Date(int y, int m,int d): year(y),month(m),day(d) {if(!is_valid()) throw Invalid{};}
	bool is_valid();
	void add_day(int n);
	int get_year() const { return year;}
	int get_month() const {return month;}
	int get_day() const {return day;}
};

bool Date::is_valid()
{
    if(month < 1 || month > 12 || year < 0|| day < 1|| day > 31) return false;
    return true;
}
/*
Date::Date(int y, int m, int d){
	if (y > 0)
		year=y;
	else
		error("Invalid year");
	if (m <= 12 && m > 0)
		month =m;
	else
		error("Invalid month");
	if (d > 0 && d <= 31)
		day =d;
	else 
		error("Invalid day");

}
*/

void Date::add_day(int n){
	day += n;
	if(day> 31){
		month++;
		day -= 31;
		if (month > 12)
		{
			year++;
			month -=12;
		}
	}
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.get_year()
              << '.' << d.get_month()
              << '.' << d.get_day() << ')';
}


int main()
	try{
   Date today {1978,8,25};
   cout << "Today: " << today << '\n';
   Date tomorrow {1978,8,25};
   tomorrow.add_day(1);
   cout << "Tomorrow: " << tomorrow << '\n';
   Date test{2004, 13, -5};
   cout << "Test: " << test << '\n';
	//Date today {2020,8,31};
	/*cout << "Date: " << today.year << '.'
	    << today.month << '.' << today.day << ".\n";
*/
    //today.add_day(1);

    //today.day++;
	//today.year =-1000; 

    //cout << "Date: " << today.get_year() << '.'
	    //<< today.get_month() << '.' << today.get_day() << ".\n";

	return 0;
} catch(Date::Invalid) {
	cout << "Invalid date\n";
	return 1;

}catch(exception& e) {
	cout << "Error:" << e.what() << endl;
	return 2;
}



	

