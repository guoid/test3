// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
using namespace std;
class CMyDate {
private:
	int year;
	int month;
	int day;
	int check();
public:
	CMyDate();
	CMyDate(int y, int m, int d);
	int setdate(int y, int m, int d);
	void displayDate();
	void addOneDay();
	int getYear();
	int getMonth();
	int getDay();


};
CMyDate::CMyDate()
{
	year = 2019;
	month = 5;
	day = 6;
}
CMyDate::CMyDate(int y, int m, int d)
{
	year = y;
	month= m;
	day = d;
	if (check() == 1 || check() == -1) {
		month = 1;
		day = 1;
		cout << "error" << endl;
	}
}
int CMyDate::check()
{
	int leapyear[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int flatyear[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		if (month > 12 || month < 1)
			return -1;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapyear[month - 1] < day)
			return 1;
	}
	
	else {
		if (flatyear[month - 1] < day)
			return 1;
	}
	return 0;
}
int CMyDate::getYear()
{
	return year;
}
int CMyDate::getMonth()
{
	return month;
}
int CMyDate::getDay()
{
	return day;
}

int CMyDate::setdate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "error" << endl;
	
	return  -1;}
	return 0;
}
void CMyDate::displayDate()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
}
void CMyDate::addOneDay()
{
	int leapyear[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int flatyear[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; 
		day++;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapyear[month - 1] < day) {
			day = 1;
			month++;
		}
	}
	else {
		if (flatyear[month - 1] < day) {
			day = 1;
			month++;
		}
	}
	if (month > 12) {
		month = 1;
		year++;
	}
}
int main()
{
	CMyDate od;
	int count = 1;

	od.setdate(2000,10,10);

	
	od.displayDate();
	while (!((od.getYear() == 2019) && (od.getMonth() == 5) && (od.getDay()) == 6)) {
		od.addOneDay();
		count++;
	}
	cout << count << endl;
    return 0;
}

