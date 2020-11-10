#include "std_lib_facilities.h"
struct Date
{
	int y,m,d;   //year,month in year, dayof  month
};

void init_date(Date& date, int y, int m, int d)
{
	if (y > 0)
		date.y=y;
	else
		error("Invalid year");       //check that(y,m,d) is a valid date, if it is, use it to initialize dd
	if (m <= 12 && m > 0)
		date.m =m;
	else
		error("Invalid month");
	if (d > 0 && d <= 31)
		date.d =d;
	else 
		error("Invalid day");

}
void add_day(Date& date, int n){          //increase dd by n days
     date.d += n;
	if (date.d > 31) 
	{
		date.m++;
		date.d -= 31;
		if (date.m > 12)
		{
			date.y++;
			date.m -= 12;
		}
	}
  }

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y
              << '.' << d.m
              << '.' << d.d << ')';
}

int main()
	try{
	Date today;  // Date variable (a named object)
	init_date(today,1978,6,25);
	 cout << "Today: " << today << '\n';
    Date tomorrow;
    init_date(tomorrow,1978,6,25);   //vagy init_date(today);
     add_day(tomorrow,1);  // vagy tomorrow.add_day(1);
    cout << "Tomorrow: " << tomorrow << '\n';
    Date test;
    init_date(test,2004, 13, -5);  //a hibás évszám
    cout << "Test: " << test << '\n';
	//today.y=1978;
	//today.y=1978;
	//today.m=6;
	//today.d=25;

	//cout << "Date: " << today.y << '.'
	  //  << today.m << '.' << today.d << ".\n";
	//Date x;
	//init_date(x,2020,24,10);
	// x.y=-1000;
	// x.m= 15;
	// x.d=32;
	//cout << "Date: " << x.y << '.'
	  //  << x.m << '.' << x.d << ".\n";

	return 0;
} catch(exception& e) {
	cout << e.what() << endl;
	return 1;
}