#include "std_lib_facilities.h"

class Date {
	int year, month, day;
public:
	Date(int y, int m, int d);
	void add_day(int n);
	int get_year() const { return year; }
	int get_month() const { return month; }
	int get_day() const { return day; }
};

Date::Date(int y, int m, int d)
{
	if (y > 0)
		year = y;
	else
		error("Invalid year");
	if (m < 13 && m > 0)
		month = m;
	else
		error("Invalid month");
	if (d > 0 && d < 32)
		day = d;
	else
		error("Invalid day");
}

void Date::add_day(int n)
{
	day += n;
	if (day > 31) 
	{
		month++;
		day -= 31;
		if (month > 12)
		{
			year++;
			month -= 12;
		}
	}
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.get_year()
              << ',' << d.get_month()
              << ',' << d.get_day() << ')';
}

int main()
try {

	Date today{1978,6,25};
	cout << "Today: " << today << '\n';
	Date tomorrow{1978,6,25};
	tomorrow.add_day(1);
	cout << "Tomorrow: " << tomorrow << '\n';
	Date test{2004, 13, -5};
	 cout << "Test: " << test << '\n';

	//Date today {2020, 8, 31};

	//Date some_day {12, 24, 2018}; //Runtime error
	//Date my_birthday;
/*   Date my_birthday {2020,12,31};

	cout << "Date: " << today.get_year() << ". " << today.get_month() << ". " << today.get_day() << ".\n";

	today.add_day(1);

	cout << "Date: " << today.get_year() << ". " << today.get_month() << ". " << today.get_day() << ".\n";
*/
	return 0;

} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
}