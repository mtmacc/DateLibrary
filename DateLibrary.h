#pragma warning(disable : 4996)
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"MyOwnStringLib.h"
using namespace std;
class DateLibrary
{
private:
	short _Day;
	short _Month;
	short _Year;
public:
	DateLibrary()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}
	DateLibrary(short day,short month,short year):_Day(day),_Month(month),_Year(year)
	{

	}
	DateLibrary(string date)
	{
		vector<string> SplitDate;
		SplitDate = MyOwnStringLib::split(date, "/");
		_Day = stoi (SplitDate.at(0));
		_Month = stoi(SplitDate.at(1));
		_Year = stoi(SplitDate.at(2));

	}
	void setDay(short day)
	{
		_Day = day;
	}
	short getDay()
	{
		return _Day;
	}
	__declspec(property(get = getDay, put = setDay)) short Day;

	void setMonth(short month)
	{
		_Month = month;
	}
	short getMonth()
	{
		return _Month;
	}
	__declspec(property(get = getMonth, put = setMonth)) short Month;
	void setYear(short year)
	{
		_Year = year;
	}
	short getYear()
	{
		return _Year;
	}
	__declspec(property(get = getyear, put = setyear)) short Year;

	static bool isLeapYear(short year)
	{
		return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	}
	bool isLeapYear()
	{
		return isLeapYear(this->_Year);
	}
	static int DaysInMonth(short year, short month) {
		if (month < 1 || month > 12) {
			cout << "Invalid month! Please enter a month between 1 and 12." << endl;
			return -1;
		}

		if (month == 2) {
			return isLeapYear(year) ? 29 : 28;
		}
		return (month <= 7 && month % 2 != 0) || (month > 7 && month % 2 == 0) ? 31 : 30;
	}
	short DaysInMonth()
	{
		return DaysInMonth(this->_Year,this->_Month);
	}
	static int DaysInYear(short year)
	{
		return isLeapYear(year) ? 366 : 365;
	}
	int DaysInYear()
	{
		return DaysInYear(this->_Year);
	}
	 bool ValidDate(DateLibrary date)
	{
		if (date._Year <= 0) return false;
		if (date._Month <= 0 || date._Month > 12) return false;
		if (date._Day <= 0 || date._Day > DaysInMonth(date._Year,date._Month)) return false;
		return true;
	}	 
	bool ValidDate()
	{
		return ValidDate(*this);
	}
	 bool IsLastDayOfMonth(DateLibrary sdate)
	{
		return (sdate._Day == DaysInMonth(sdate._Year,sdate._Month));
	}
	bool IsLastDayOfMonth()
	{
		return IsLastDayOfMonth(*this);
	}

	static void SwapFunc(DateLibrary& Date1, DateLibrary& Date2)
	{
		DateLibrary temp = Date1;
		Date1 = Date2;
		Date2 = temp;
	}

	static bool isLastMonthOfYear(short month)
	{
		return (month == 12);
	}
	bool isLastMonthOfYear()
	{
		return isLastMonthOfYear(this->_Year);
	}


	static bool isDate1Older(DateLibrary Date1, DateLibrary Date2)
	{
		return (Date1._Year < Date2._Year) ? true : (Date1._Year == Date2._Year && Date1._Month < Date2._Month) ? true : (Date1._Year == Date2._Year && Date1._Month == Date2._Month && Date1._Day < Date2._Day) ? true : false;
	}
	bool isDate1Older(DateLibrary Date2)
	{
		return isDate1Older(*this, Date2);
	}
	void IncresseDayBy1()
	{
		if (IsLastDayOfMonth(*this))
		{
			_Day = 1;
			if (isLastMonthOfYear(_Month))
			{
				_Year++;
				_Month = 1;
			}
			else {
				_Month++;
			}
		}
		else
		{
			_Day++;
		}
		
	}
	int CalcDaysFromYearStart(DateLibrary sdate)
	  {
		  int result = 0;
		  for (short i = 1; i < sdate._Month; i++)
		  {
			  result += DaysInMonth(sdate._Year, i);
		  }

		  result += sdate._Day;
		  return result;
	  }
	int CalcDaysFromYearStart()
	  {
		  return CalcDaysFromYearStart(*this);
	  }


	   int Deffranece(DateLibrary data1, DateLibrary data2, bool addToday = false)
	  {
		  int result = 0;
		  bool isSwap = false;
		  if (data1._Year == data2._Year)
		  {
			  result = CalcDaysFromYearStart(data2) - CalcDaysFromYearStart(data1);
		  }
		  if (data1._Year != data2._Year)
		  {
			  if (!isDate1Older(data1, data2))
			  {
				  SwapFunc(data1, data2);
				  isSwap = true;
			  }
			  result = CalcDaysFromYearStart(data2) + (DaysInYear(data1._Year) - CalcDaysFromYearStart(data1));
			  data1._Year++;
			  while (data1._Year < data2._Year)
			  {
				  result += DaysInYear(data1._Year);
				  data1._Year++;
			  }
		  }
		  if (addToday)
		  {
			  result++;
		  }
		  return isSwap ? -result : result;
	  }
	int Deffranece(DateLibrary data2, bool addToday = false)
	{
		return Deffranece(*this, data2, addToday);
	}


	 int Deffranece2(DateLibrary data1, DateLibrary data2, bool addToday = false)
	{
		int result = 0;
		bool swap = false;
		if (!isDate1Older(data1, data2))
		{
			SwapFunc(data1, data2);
			swap = true;
		}

		while (isDate1Older(data1, data2))
		{
			data1.IncresseDayBy1();
			result++;
		}
		if (swap) result = -result;
		return addToday ? ++result : result;
	}

	int Deffranece2(DateLibrary data2, bool addToday = false)
	{
		return Deffranece2(*this, data2, addToday);
	}
	static string MonthName(short month)
	{
		string names[] = { "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec" };
		return names[month - 1];
	}
	static short DayIndex(short month, short year, short day = 1)
	{
		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + 12 * a - 2;
		int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
		return d;
	}
	 void FullCalendar(DateLibrary date,short month)
	{
		string names[] = { "sun", "mon", "tue", "wed", "thu", "fri", "sat" };
		cout << "\n____________" << MonthName(month) << "____________\n";
		for (int i = 0; i < 7; i++)
		{
			cout << setw(4) << names[i];
		}
		cout << endl;

		int startDay = DayIndex(month, date._Year);
		int totalDays = DaysInMonth(date._Year, month);
		int i;
		for (i = 0; i < startDay; i++)
		{
			cout << setw(4) << " ";
		}
		for (int z = 1; z <= totalDays; z++)
		{
			cout << setw(4) << z;
			i++;
			if (i == 7)
			{
				cout << endl;
				i = 0;
			}
		}
	}
	void FullCalendar()
	{
		FullCalendar(*this, this->_Month);
	}
	 void YearCalendar(DateLibrary date)
	{
		cout << "____________" << date._Year << "____________\n";
		for (short i = 1; i <= 12; i++)
		{
			FullCalendar(date,i);
		}
	}
	void YearCalendar()
	{
		YearCalendar(*this);
	}
	void Print()
	{
		if (ValidDate(*this))
		{
			cout << _Day << "-" << _Month << "-" << _Year << endl;
		}
		else {
			cout << "Not Valid Date " << endl;
		}
		
	}
};

