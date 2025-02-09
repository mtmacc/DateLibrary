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
	DateLibrary(short DateOrderInYear, short Year)
	{
		//This will construct a date by date order in year
		DateLibrary Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
		_Day = Date1._Day;
		_Month = Date1._Month;
		_Year = Date1._Year;
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
	static DateLibrary GetSystemDate()
	{
		//system date
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		return DateLibrary(Day, Month, Year);
	}
	static string DateToString(DateLibrary Date)
	{
		return  to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
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
	static short NumberOfHoursInAMonth(short Month, short Year)
	{
		return  DaysInMonth(Year, Month) * 24;
	}
	short NumberOfHoursInAMonth()
	{
		return  DaysInMonth(_Year,_Month) * 24;
	}

	static int NumberOfMinutesInAMonth(short Month, short Year)
	{
		return  NumberOfHoursInAMonth(Month, Year) * 60;
	}

	int NumberOfMinutesInAMonth()
	{
		return  NumberOfHoursInAMonth(_Month, _Year) * 60;
	}

	static int NumberOfSecondsInAMonth(short Month, short Year)
	{
		return  NumberOfMinutesInAMonth(Month, Year) * 60;
	}

	int NumberOfSecondsInAMonth()
	{
		return  NumberOfMinutesInAMonth(_Month, _Year) * 60;
	}
	static int DaysInYear(short year)
	{
		return isLeapYear(year) ? 366 : 365;
	}
	int DaysInYear()
	{
		return DaysInYear(this->_Year);
	}

	static short NumberOfHoursInAYear(short Year)
	{
		return  DaysInYear(Year) * 24;
	}

	short NumberOfHoursInAYear()
	{
		return  NumberOfHoursInAYear(_Year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return  NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfMinutesInAYear()
	{
		return  NumberOfMinutesInAYear(_Year);
	}

	static int NumberOfSecondsInAYear(short Year)
	{
		return  NumberOfMinutesInAYear(Year) * 60;
	}

	int NumberOfSecondsInAYear()
	{
		return  NumberOfSecondsInAYear(_Year);
	}
	static bool ValidDate(DateLibrary date)
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
	 static bool IsLastDayOfMonth(DateLibrary sdate)
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
		return isLastMonthOfYear(this->_Month);
	}


	static bool isDate1Older(DateLibrary Date1, DateLibrary Date2)
	{
		return (Date1._Year < Date2._Year) ? true : (Date1._Year == Date2._Year && Date1._Month < Date2._Month) ? true : (Date1._Year == Date2._Year && Date1._Month == Date2._Month && Date1._Day < Date2._Day) ? true : false;
	}
	bool isDate1Older(DateLibrary Date2)
	{
		return isDate1Older(*this, Date2);
	}
	static DateLibrary AddOneDay(DateLibrary Date)
	{
		if (IsLastDayOfMonth(Date))
		{
			if (isLastMonthOfYear(Date._Month))
			{
				Date._Month = 1;
				Date._Day = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}

		return Date;
	}

	void AddOneDay()

	{
		*this = AddOneDay(*this);
	}
	int CalcDaysFromYearStart( short day,short month,short year)
	  {
		  int result = 0;
		  for (short i = 1; i < month; i++)
		  {
			  result += DaysInMonth(year, i);
		  }

		  result += day;
		  return result;
	  }
	int CalcDaysFromYearStart()
	  {
		  return CalcDaysFromYearStart(_Day,_Month,_Year);
	  }


	int Deffranece(DateLibrary Date1, DateLibrary Date2, bool addToday = false)
	  {
		  int result = 0;
		  bool isSwap = false;
		  if (Date1._Year == Date2._Year)
		  {
			  result = CalcDaysFromYearStart(Date2._Day,Date2._Month,Date2._Year) - CalcDaysFromYearStart(Date1._Day, Date1._Month, Date1._Year);
		  }
		  if (Date1._Year != Date2._Year)
		  {
			  if (!isDate1Older(Date1, Date2))
			  {
				  SwapFunc(Date1, Date2);
				  isSwap = true;
			  }
			  result = CalcDaysFromYearStart(Date2._Day, Date2._Month, Date2._Year) + (DaysInYear(Date1._Year) - CalcDaysFromYearStart(Date1._Day, Date1._Month, Date1._Year));
			  Date1._Year++;
			  while (Date1._Year < Date2._Year)
			  {
				  result += DaysInYear(Date1._Year);
				  Date1._Year++;
			  }
		  }
		  if (addToday)
		  {
			  result++;
		  }
		  return isSwap ? -result : result;
	  }
	int Deffranece(DateLibrary Date2, bool addToday = false)
	{
		return Deffranece(*this, Date2, addToday);
	}


	 int Deffranece2(DateLibrary Date1, DateLibrary Date2, bool addToday = false)
	{
		int result = 0;
		bool swap = false;
		if (!isDate1Older(Date1, Date2))
		{
			SwapFunc(Date1, Date2);
			swap = true;
		}

		while (isDate1Older(Date1, Date2))
		{
			Date1.AddOneDay();
			result++;
		}
		if (swap) result = -result;
		return addToday ? ++result : result;
	}

	int Deffranece2(DateLibrary Date2, bool addToday = false)
	{
		return Deffranece2(*this, Date2, addToday);
	}
	static string MonthName(short month)
	{
		string names[] = { "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec" };
		return names[month - 1];
	}
	string MonthName()
	{
		return MonthName(_Month);
	}
	static DateLibrary GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{

		DateLibrary Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;

		Date._Year = Year;
		Date._Month = 1;

		while (true)
		{
			MonthDays = DaysInMonth(Year, Date.Month);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}

		}

		return Date;
	}
	static short DayIndex(short month, short year, short day = 1)
	{
		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + 12 * a - 2;
		int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
		return d;
	}
	short DayIndex()
	{
		return DayIndex(_Month, _Year, _Day);
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
	void AddDays(short Days)
	{


		short RemainingDays = Days + CalcDaysFromYearStart(_Day, _Month, _Year);
		short MonthDays = 0;

		_Month = 1;

		while (true)
		{
			MonthDays = DaysInMonth(_Year,_Month);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				_Month++;

				if (_Month > 12)
				{
					_Month = 1;
					_Year++;

				}
			}
			else
			{
				_Day = RemainingDays;
				break;
			}
		}
	}
	static bool IsDate1EqualDate2(DateLibrary Date1, DateLibrary Date2)
	{
		return  (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}

	bool IsDateEqualDate2(DateLibrary Date2)
	{
		return  IsDate1EqualDate2(*this, Date2);
	}
	
	 short CalculateMyAgeInDays(DateLibrary DateOfBirth)
	{
		return Deffranece(DateOfBirth, DateLibrary::GetSystemDate(), true);
	}
	
	 static DateLibrary IncreaseDateByOneWeek(DateLibrary& Date)
	 {

		 for (int i = 1; i <= 7; i++)
		 {
			 Date = AddOneDay(Date);
		 }

		 return Date;
	 }

	 void IncreaseDateByOneWeek()
	 {
		 IncreaseDateByOneWeek(*this);
	 }

	 DateLibrary IncreaseDateByXWeeks(short Weeks, DateLibrary& Date)
	 {

		 for (short i = 1; i <= Weeks; i++)
		 {
			 Date = IncreaseDateByOneWeek(Date);
		 }
		 return Date;
	 }

	 void IncreaseDateByXWeeks(short Weeks)
	 {
		 IncreaseDateByXWeeks(Weeks, *this);
	 }

	 DateLibrary IncreaseDateByOneMonth(DateLibrary& Date)
	 {

		 if (Date._Month == 12)
		 {
			 Date._Month = 1;
			 Date._Year++;
		 }
		 else
		 {
			 Date._Month++;
		 }

		 //last check day in date should not exceed max days in the current month
		 // example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
		 // be 28/2/2022
		 short NumberOfDaysInCurrentMonth = DaysInMonth(Date._Year,Date._Month);
		 if (Date._Day > NumberOfDaysInCurrentMonth)
		 {
			 Date._Day = NumberOfDaysInCurrentMonth;
		 }

		 return Date;
	 }

	 void IncreaseDateByOneMonth()
	 {

		 IncreaseDateByOneMonth(*this);

	 }

	 DateLibrary IncreaseDateByXDays(short Days, DateLibrary& Date)
	 {

		 for (short i = 1; i <= Days; i++)
		 {
			 Date = AddOneDay(Date);
		 }
		 return Date;
	 }

	 void IncreaseDateByXDays(short Days)
	 {

		 IncreaseDateByXDays(Days, *this);
	 }

	 DateLibrary IncreaseDateByXMonths(short Months, DateLibrary& Date)
	 {

		 for (short i = 1; i <= Months; i++)
		 {
			 Date = IncreaseDateByOneMonth(Date);
		 }
		 return Date;
	 }

	 void IncreaseDateByXMonths(short Months)
	 {
		 IncreaseDateByXMonths(Months, *this);
	 }

	 static DateLibrary IncreaseDateByOneYear(DateLibrary& Date)
	 {
		 Date._Year++;
		 return Date;
	 }

	 void IncreaseDateByOneYear()
	 {
		 IncreaseDateByOneYear(*this);
	 }

	 DateLibrary IncreaseDateByXYears(short Years, DateLibrary& Date)
	 {
		 Date._Year += Years;
		 return Date;

	 }

	 void IncreaseDateByXYears(short Years)
	 {
		 IncreaseDateByXYears(Years);
	 }

	 DateLibrary IncreaseDateByOneDecade(DateLibrary& Date)
	 {
		 //Period of 10 years
		 Date._Year += 10;
		 return Date;
	 }

	 void IncreaseDateByOneDecade()
	 {
		 IncreaseDateByOneDecade(*this);
	 }

	 DateLibrary IncreaseDateByXDecades(short Decade, DateLibrary& Date)
	 {
		 Date._Year += Decade * 10;
		 return Date;
	 }

	 void IncreaseDateByXDecades(short Decade)
	 {
		 IncreaseDateByXDecades(Decade, *this);
	 }

	 DateLibrary IncreaseDateByOneCentury(DateLibrary& Date)
	 {
		 //Period of 100 years
		 Date._Year += 100;
		 return Date;
	 }

	 void IncreaseDateByOneCentury()
	 {
		 IncreaseDateByOneCentury(*this);
	 }

	 DateLibrary IncreaseDateByOneMillennium(DateLibrary& Date)
	 {
		 //Period of 1000 years
		 Date._Year += 1000;
		 return Date;
	 }

	 DateLibrary IncreaseDateByOneMillennium()
	 {
		 IncreaseDateByOneMillennium(*this);
	 }

	 static DateLibrary DecreaseDateByOneDay(DateLibrary Date)
	 {
		 if (Date._Day == 1)
		 {
			 if (Date._Month == 1)
			 {
				 Date._Month = 12;
				 Date._Day = 31;
				 Date._Year--;
			 }
			 else
			 {

				 Date._Month--;
				 Date._Day = DaysInMonth( Date._Year,  Date._Month);
			 }
		 }
		 else
		 {
			 Date.Day--;
		 }

		 return Date;
	 }

	 void DecreaseDateByOneDay()
	 {
		 DecreaseDateByOneDay(*this);
	 }

	 static DateLibrary DecreaseDateByOneWeek(DateLibrary& Date)
	 {

		 for (int i = 1; i <= 7; i++)
		 {
			 Date = DecreaseDateByOneDay(Date);
		 }

		 return Date;
	 }

	 void DecreaseDateByOneWeek()
	 {
		 DecreaseDateByOneWeek(*this);
	 }

	 static DateLibrary DecreaseDateByXWeeks(short Weeks, DateLibrary& Date)
	 {

		 for (short i = 1; i <= Weeks; i++)
		 {
			 Date = DecreaseDateByOneWeek(Date);
		 }
		 return Date;
	 }

	 void DecreaseDateByXWeeks(short Weeks)
	 {
		 DecreaseDateByXWeeks(Weeks, *this);
	 }

	 static DateLibrary DecreaseDateByOneMonth(DateLibrary& Date)
	 {

		 if (Date._Month == 1)
		 {
			 Date._Month = 12;
			 Date._Year--;
		 }
		 else
			 Date._Month--;


		 //last check day in date should not exceed max days in the current month
		// example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
		// be 28/2/2022
		 short NumberOfDaysInCurrentMonth = DaysInMonth( Date._Year,Date._Month);
		 if (Date.Day > NumberOfDaysInCurrentMonth)
		 {
			 Date.Day = NumberOfDaysInCurrentMonth;
		 }


		 return Date;
	 }

	 void DecreaseDateByOneMonth()
	 {
		 DecreaseDateByOneMonth(*this);
	 }

	 static DateLibrary DecreaseDateByXDays(short Days, DateLibrary& Date)
	 {

		 for (short i = 1; i <= Days; i++)
		 {
			 Date = DecreaseDateByOneDay(Date);
		 }
		 return Date;
	 }

	 void DecreaseDateByXDays(short Days)
	 {
		 DecreaseDateByXDays(Days, *this);
	 }

	 static DateLibrary DecreaseDateByXMonths(short Months, DateLibrary& Date)
	 {

		 for (short i = 1; i <= Months; i++)
		 {
			 Date = DecreaseDateByOneMonth(Date);
		 }
		 return Date;
	 }

	 void DecreaseDateByXMonths(short Months)
	 {
		 DecreaseDateByXMonths(Months, *this);
	 }

	 static DateLibrary DecreaseDateByOneYear(DateLibrary& Date)
	 {

		 Date._Year--;
		 return Date;
	 }

	 void DecreaseDateByOneYear()
	 {
		 DecreaseDateByOneYear(*this);
	 }

	 static DateLibrary DecreaseDateByXYears(short Years, DateLibrary& Date)
	 {

		 Date._Year -= Years;
		 return Date;
	 }

	 void DecreaseDateByXYears(short Years)
	 {
		 DecreaseDateByXYears(Years, *this);
	 }

	 static DateLibrary DecreaseDateByOneDecade(DateLibrary& Date)
	 {
		 //Period of 10 years
		 Date._Year -= 10;
		 return Date;
	 }

	 void DecreaseDateByOneDecade()
	 {
		 DecreaseDateByOneDecade(*this);
	 }

	 static DateLibrary DecreaseDateByXDecades(short Decades, DateLibrary& Date)
	 {

		 Date._Year -= Decades * 10;
		 return Date;
	 }

	 void DecreaseDateByXDecades(short Decades)
	 {
		 DecreaseDateByXDecades(Decades, *this);
	 }

	 static DateLibrary DecreaseDateByOneCentury(DateLibrary& Date)
	 {
		 //Period of 100 years
		 Date._Year -= 100;
		 return Date;
	 }

	 void DecreaseDateByOneCentury()
	 {
		 DecreaseDateByOneCentury(*this);
	 }

	 static DateLibrary DecreaseDateByOneMillennium(DateLibrary& Date)
	 {
		 //Period of 1000 years
		 Date._Year -= 1000;
		 return Date;
	 }

	 void DecreaseDateByOneMillennium()
	 {
		 DecreaseDateByOneMillennium(*this);
	 }

	 static bool IsEndOfWeek(DateLibrary Date)
	 {
		 return   DayIndex(Date._Month, Date._Year, Date._Day) == 6;
	 }

	 bool IsEndOfWeek()
	 {
		 return IsEndOfWeek(*this);
	 }

	 static bool IsWeekEnd(DateLibrary Date)
	 {
		 //Weekends are Fri and Sat
		 short Index = DayIndex(Date._Month, Date._Year, Date._Day);
		 return  (Index == 5 || Index == 6);
	 }

	 bool IsWeekEnd()
	 {
		 return  IsWeekEnd(*this);
	 }

	 static bool IsBusinessDay(DateLibrary Date)
	 {
		return !IsWeekEnd(Date);
	 }

	 bool IsBusinessDay()
	 {
		 return  IsBusinessDay(*this);
	 }





	 static short DaysUntilTheEndOfWeek(DateLibrary Date)
	 {
		 return 6 - DayIndex(Date._Month, Date._Year, Date._Day);
	 }

	 short DaysUntilTheEndOfWeek()
	 {
		 return  DaysUntilTheEndOfWeek(*this);
	 }

	  short DaysUntilTheEndOfMonth(DateLibrary Date1)
	 {

		 DateLibrary EndOfMontDate;
		 EndOfMontDate._Day = DaysInMonth(Date1._Year, Date1._Month);
		 EndOfMontDate._Month = Date1._Month;
		 EndOfMontDate._Year = Date1._Year;

		 return Deffranece(Date1, EndOfMontDate, true);

	 }

	 short DaysUntilTheEndOfMonth()
	 {
		 return DaysUntilTheEndOfMonth(*this);
	 }

	  short DaysUntilTheEndOfYear(DateLibrary Date1)
	 {

		 DateLibrary EndOfYearDate;
		 EndOfYearDate._Day = 31;
		 EndOfYearDate._Month = 12;
		 EndOfYearDate._Year = Date1._Year;

		 return Deffranece(Date1, EndOfYearDate, true);

	 }

	 short DaysUntilTheEndOfYear()
	 {
		 return  DaysUntilTheEndOfYear(*this);
	 }

	 //i added this method to calculate business days between 2 days
	 static short CalculateBusinessDays(DateLibrary DateFrom, DateLibrary DateTo)
	 {

		 short Days = 0;
		 while (isDate1Older(DateFrom, DateTo))
		 {
			 if (IsBusinessDay(DateFrom))
				 Days++;

			 DateFrom = AddOneDay(DateFrom);
		 }

		 return Days;

	 }

	 static short CalculateVacationDays(DateLibrary DateFrom, DateLibrary DateTo)
	 {
		 /*short Days = 0;
		 while (IsDate1BeforeDate2(DateFrom, DateTo))
		 {
			 if (IsBusinessDay(DateFrom))
				 Days++;

			 DateFrom = AddOneDay(DateFrom);
		 }*/

		 return CalculateBusinessDays(DateFrom, DateTo);

	 }
	 //above method is eough , no need to have method for the object

	 static DateLibrary CalculateVacationReturnDate(DateLibrary DateFrom, short VacationDays)
	 {

		 short WeekEndCounter = 0;

		 for (short i = 1; i <= VacationDays; i++)
		 {

			 if (IsWeekEnd(DateFrom))
				 WeekEndCounter++;

			 DateFrom = AddOneDay(DateFrom);
		 }
		 //to add weekends 
		 for (short i = 1; i <= WeekEndCounter; i++)
			 DateFrom = AddOneDay(DateFrom);

		 return DateFrom;
	 }

	 static bool IsDate1AfterDate2(DateLibrary Date1, DateLibrary Date2)
	 {
		 return (!isDate1Older(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));

	 }

	 bool IsDateAfterDate2(DateLibrary Date2)
	 {
		 return IsDate1AfterDate2(*this, Date2);
	 }

	 enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	 static enDateCompare CompareDates(DateLibrary Date1, DateLibrary Date2)
	 {
		 if (isDate1Older(Date1, Date2))
			 return enDateCompare::Before;

		 if (IsDate1EqualDate2(Date1, Date2))
			 return enDateCompare::Equal;

		 /* if (IsDate1AfterDate2(Date1,Date2))
			  return enDateCompare::After;*/

			  //this is faster
		 return enDateCompare::After;

	 }

	 enDateCompare CompareDates(DateLibrary Date2)
	 {
		 return CompareDates(*this, Date2);
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

