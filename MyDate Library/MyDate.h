/*
    Author	=> Hamza Abdulrahman
    Date	=> 2024-2-17
*/
#pragma once
#pragma warning(default : 4996)

#include <iostream>
#include <vector>
#include <string>
#include "MyString.h"

using namespace std;

class MyDate
{
private:

    int _Year;
    int _Month;
    int _Day;

public:
   
    MyDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        _Year = now->tm_year + 1900;
        _Month = now->tm_mon + 1;
        _Day = now->tm_mday;
    }
    MyDate(string strDate)
    {
        vector<string> vDate;
        vDate = MyString::Split(strDate, "/");
        _Day = stoi(vDate.at(0));
        _Month = stoi(vDate.at(1));
        _Year = stoi(vDate.at(2));
    }
    MyDate(int Day, int Month, int Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }
    MyDate(int DaysOrderInYear, int Year)
    {
        MyDate Date = getDateFromDayOrderInYear(DaysOrderInYear, Year);
        _Day = Date._Day;
        _Month = Date._Month;
        _Year = Date._Year;
    }

    void setYear(int Year)
    {
        _Year = Year;
    }
    int getYear() {
        return _Year;
    }
    __declspec(property(get = getYear, put = setYear)) int Year;
    void setMonth(int Month)
    {
        _Month = Month;
    }
    int getMonth()
    {
        return _Month;
    }
    __declspec(property(get = getMonth, put = setMonth)) int Month;
    void setDay(int Day)
    {
        _Day = Day;
    }
    int getDay()
    {
        return Day;
    }
    __declspec(property(get = getDay, put = setDay)) int Day;

    void Print()
    {
        cout << _Day << "/" << _Month << "/" << _Year << endl;
    }


    MyDate ReadFullDate()
    {
        MyDate Date;
        cout << "Enter Day: ";
        cin >> Date._Day;
        cout << "Enter Month: ";
        cin >> Date._Month;
        cout << "Enter Year: ";
        cin >> Date._Year;
        return Date;
    }

    static bool IsLeapYear(int Year)
    {
        return Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0);
    }
    bool IsLeapYear()
    {
        return IsLeapYear(_Year);
    }
    
    static int NumberOfDaysInAMonth(int Year, int Month)
    {
        if (Month < 1 || Month>12)
            return  0;

        int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
       
        return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
        //long way
        /*
        if (Month == 2)
        {
            return  CheakIsLeapYear(Year) ? 29 : 28;
        }
        short arr31Days[7] = { 1,3,5,7,8,10,12 };
        for (short i = 1; i <= 7; i++)
        {
            if (arr31Days[i - 1] == Month) return 31;
        }
        //if you reach here then its 30 days.
        return  30;*/
    }
    int NumberOfDaysInAMonth()
    {
        return NumberOfDaysInAMonth(_Year, _Month);
    }

    static int NumberOfHoursInAMonth(int Year, int Month)
    {
        return NumberOfDaysInAMonth(Year, Month) * 24;
    }
    int NumberOfHoursInAMonth()
    {
        return NumberOfHoursInAMonth(_Year, _Month);
    }

    static int NumberOfMinutesInAMonth(int Year, int Month)
    {
        return NumberOfHoursInAMonth(Year, Month) * 60;
    }
    int NumberOfMinutesInAMonth()
    {
        return NumberOfMinutesInAMonth(_Year, _Month);
    }

    static int NumberOfSecondsInAMonth(int Year, int Month)
    {
        return NumberOfMinutesInAMonth(Year, Month) * 60;
    }
    int NumberOfSecondsInAMonth()
    {
        return NumberOfSecondsInAMonth(_Year, _Month);
    }

    static int NumberOfDayesFromTheBeginingOfTheYear(int Year, int Month, int Day)
    {
        int TotalDays = 0;
        for (int i = 1; i <= Month - 1; i++)
        {
            TotalDays += NumberOfDaysInAMonth(Year, i);
        }
        TotalDays += Day;

        return TotalDays;
    }
    int NumberOfDayesFromTheBeginingOfTheYear()
    {
        return NumberOfDayesFromTheBeginingOfTheYear(_Year, _Month, _Day);
    }

    static string ConvertDateToString(MyDate Date)
    {
        return to_string(Date._Year) + "/" + to_string(Date._Month) + "/" + to_string(Date._Day);
    }
    string ConvertDateToString()
    {
        return ConvertDateToString(*this);
    }

    static int DayOfWeekOrder(int Year, int Month, int Day)
    {
        int a = (14 - Month) / 12;
        int y = Year - a;
        int m = Month + 12 * a - 2;

        //For the Gregorian calendar:
        int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;
        return d;
    }
    static int DayOfWeekOrder(MyDate Date)
    {
        //ovar loading
        return DayOfWeekOrder(Date._Year, Date._Month, Date._Day);
    }
    int DayOfWeekOrder()
    {
        return DayOfWeekOrder(_Year, _Month, _Day);
    }

    static MyDate getDateFromDayOrderInYear(int DaysOrderInYear, int Year)
    {
        MyDate Date;
        int ReminingDays = DaysOrderInYear;
        int MonthDays = 0;

        Date._Year = Year;
        Date._Month = 1;
        while (true)
        {
            MonthDays = NumberOfDaysInAMonth(Year, Date._Month);

            if (ReminingDays > MonthDays)
            {
                ReminingDays -= MonthDays;
                Date._Month++;
            }
            else
            {
                Date._Day = ReminingDays;
                break;
            }
            if (Date._Month > 12)
            {
                Date._Year++;
                Date._Month = 1;
            }
        }

        return Date;
    }
    MyDate getDateFromDayOrderInYear(int DaysOrderInYear)
    {
        return getDateFromDayOrderInYear(DaysOrderInYear, _Year);
    }

    static string getDayName(int Year, int Month, int Day, int DayOrderInWeek)
    {
        string rest[7] = { "Sun","Mon","Tue","Wed","Thur","Fir","Sat" };
        
        return rest[DayOrderInWeek];
    }
    string getDayName(int DayOrderInWeek)
    {
        return getDayName(_Year, _Month, _Day, DayOrderInWeek);
    }

    static string getMonthName(int Month)
    {
        string Months[12] = { "January","February","March","April","May","Junr",
            "July","Audust","September","October","November","December" };
        return Months[Month - 1];
    }
    string getMonthName()
    {
        return getMonthName(_Month);
    }

    static void PrintMonthCalender(int Year, int Month)
    {
        string Days[7] = { "Sun","Mon","Tue","Wed","Thur","Fir","Sat" };

        int current = DayOfWeekOrder(Year, Month, 1);
        printf("\n  ----------- %s ------------\n", getMonthName(Month).c_str());

        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        int i = 0;
        
        for (i = 0; i < current; i++)
        {
            printf("     ");
        }

        int NumberOfDay = NumberOfDaysInAMonth(Year, Month);
        
        for (int j = 1; j <= NumberOfDay; j++)
        {
            printf("%5d", j);

            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }

        printf("\n  ----------------------------------\n");
    }
    void PrintMonthCalender()
    {
        return PrintMonthCalender(_Year, _Month);
    }

    static void PrintYearCalender(int Year)
    {
        int LastMonthOnAYear = 12;
        cout << "  --------------------------------\n";
        cout << "          Calender - " << Year << endl;
        cout << "  --------------------------------\n";
        
        for (int Month = 1; Month <= LastMonthOnAYear; Month++)
        {
            PrintMonthCalender(Year, Month);
            cout << endl;
        }
    }
    void PrintYearCalender()
    {
        PrintYearCalender(_Year);
    }

    static MyDate DateAddDays(int Days, MyDate Date)
    {
        int DaysOrderInYear = NumberOfDayesFromTheBeginingOfTheYear(Date._Year, Date._Month, Date._Day);
        int AfterAddOrder = DaysOrderInYear + Days;
        
        return getDateFromDayOrderInYear(AfterAddOrder, Date._Year);
    }
    MyDate DateAddDays(int HowManyDays)
    {
        return DateAddDays(HowManyDays, *this);
    }

    static bool IsDate1BeforeDate2(MyDate Date1, MyDate Date2)
    {
        return  (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
    }
    bool IsDate1BeforeDate2(MyDate Date2)
    {
        return IsDate1BeforeDate2(*this, Date2);
    }
    
    static bool IsDate1EqualDate2(MyDate Date1, MyDate Date2)
    {
        return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
    }
    bool IsDate1EqualDate2(MyDate Date2)
    {
        return IsDate1EqualDate2(*this, Date2);
    }
    
    static bool IsDate1AfterDate2(MyDate  Date1, MyDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
    }
    bool IsDate1AfterDate2(MyDate Date2)
    {
        return IsDate1AfterDate2(*this, Date2);
    }
    /////////////////
    static bool IsAlastDayInMonth(int Day, int Month, int Year)
    {
        int LastDayInMonth = NumberOfDaysInAMonth(Year, Month);
        
        return (Day == LastDayInMonth) ? true : false;
    }
    static bool IsAlastDayInMonth(MyDate Date)
    {
        int LastDayInMonth = NumberOfDaysInAMonth(Date._Year, Date._Month);
       
        return (Date._Day == LastDayInMonth) ? true : false;
    }
    bool IsAlastDayInMonth()
    {
        return IsAlastDayInMonth(*this);
    }
    
    static bool IsALastMonthInYear(int Month)
    {
        return (Month == 12) ? true : false;
    }
    static bool IsALastMonthInYear(MyDate Date)
    {
        return (Date._Month == 12) ? true : false;
    }
    bool IsALastMonthInYear()
    {
        return IsALastMonthInYear(*this);
    }

    static void SwapDates(MyDate& Date1, MyDate& Date2)
    {
        MyDate TempDate;
        TempDate._Year = Date1._Year;
        TempDate._Month = Date1._Month;
        TempDate._Day = Date1._Day;

        Date1._Year = Date2._Year;
        Date1._Month = Date2._Month;
        Date1._Day = Date2._Day;

        Date2._Year = TempDate._Year;
        Date2._Month = TempDate._Month;
        Date2._Day = TempDate._Day;
    }
    void SwapDates(MyDate& Date2)
    {
        return SwapDates(*this, Date2);
    }

    static MyDate IncreasingDateByOneDay(MyDate Date)
    {
        if (IsAlastDayInMonth(Date._Day, Date._Month, Date._Year))
        {
            if (IsALastMonthInYear(Date._Month))
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
    MyDate IncreasingDateByOneDay()
    {
        return IncreasingDateByOneDay(*this);
    }

    static int GetDifferenceInDays(MyDate Date1, MyDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;
        short SwapFlagValue = 1;
        // if Date2 < Date1
        if (!IsDate1BeforeDate2(Date1, Date2))
        {
            //Swap Date
            SwapDates(Date1, Date2);
            SwapFlagValue = -1;
        }
        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreasingDateByOneDay(Date1);
        }
        return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
    }
    int GetDifferenceInDays(MyDate Date2, bool IncludeEndDay = false)
    {
        return GetDifferenceInDays(*this, Date2, IncludeEndDay);
    }

    static MyDate GetSystemDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        MyDate DateNow;
        DateNow._Year = now->tm_year + 1900;
        DateNow._Month = now->tm_mon + 1;
        DateNow._Day = now->tm_mday;

        return DateNow;
    }

    static MyDate IncreasingDateByXDay(short HowManyDays, MyDate Date)
    {
        for (short i = 1; i <= HowManyDays; i++)
        {
            Date = IncreasingDateByOneDay(Date);
        }
        return Date;
    }
    MyDate IncreasingDateByXDay(short HowManyDays)
    {
        return IncreasingDateByXDay(HowManyDays, *this);
    }

    static MyDate IncreasingDateByOneWeek(MyDate Date)
    {
        for (short i = 1; i <= 7; i++)
        {
            Date = IncreasingDateByOneDay(Date);
        }
        return Date;
    }
    MyDate IncreasingDateByOneWeek()
    {
        return IncreasingDateByOneWeek(*this);
    }

    static MyDate IncreasingDateByXWeek(short Weeks, MyDate Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = IncreasingDateByOneWeek(Date);
        }
        return Date;
    }
    MyDate IncreasingDateByXWeek(short Weeks)
    {
        return IncreasingDateByXWeek(Weeks, *this);
    }
    
    static MyDate IncreasingDateByOneMonth(MyDate Date)
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
        //example if date is 31/1/2022 increasing one month shoulld not be 31/2/2022, it should
        //be 28/2/2022
        short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
        if (Date._Day > NumberOfDaysInCurrentMonth)
        {
            Date._Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }
    MyDate IncreasingDateByOneMonth()
    {
        return IncreasingDateByOneMonth(*this);
    }
    
    static MyDate IncreasingDateByXMonth(short Months, MyDate Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = IncreasingDateByOneMonth(Date);
        }
        return Date;
    }
    MyDate IncreasingDateByXMonth(short Months)
    {
        return IncreasingDateByXMonth(Months, *this);
    }
    
    static MyDate IncreasingDateByOneYear(MyDate Date)
    {
        Date._Year++;
        return Date;
    }
    MyDate IncreasingDateByOneYear()
    {
        return IncreasingDateByOneYear(*this);
    }
    
    static MyDate IncreasingDateByXYears(short Years, MyDate Date)
    {
        for (short i = 1; i <= Years; i++)
        {
            Date = IncreasingDateByOneYear(Date);
        }
        return Date;
    }
    MyDate IncreasingDateByXYears(short Years)
    {
        return IncreasingDateByXYears(Years, *this);
    }
    
    static MyDate IncreasingDateByXYearFaster(short Years, MyDate Date)
    {
        Date._Year += Years;
        return Date;
    }
    MyDate IncreasingDateByXYearFaster(short Years)
    {
        return IncreasingDateByXYearFaster(Years, *this);
    }
    
    static MyDate IncreasingDateByOneDecade(MyDate Date)
    {
        Date._Year += 10;
        return Date;
    }
    MyDate IncreasingDateByOneDecade()
    {
        return IncreasingDateByOneDecade(*this);
    }
    
    static MyDate IncreasingDateByXDecade(short Decade, MyDate Date)
    {
        for (short i = 1; i <= Decade * 10; i++)
        {
            Date = IncreasingDateByOneYear(Date);
        }
        return Date;
    }
    MyDate IncreasingDateByXDecade(short Decade)
    {
        return IncreasingDateByXDecade(Decade, *this);
    }
    
    static MyDate IncreasingDateByXDecadeFaster(short Decade, MyDate Date)
    {
        Date._Year += Decade * 10;
        return Date;
    }
    MyDate IncreasingDateByXDecadeFaster(short Decade)
    {
        return IncreasingDateByXDecadeFaster(Decade, *this);
    }
    
    static MyDate IncreasingDateByOneCentury(MyDate Date)
    {
        Date._Year += 100;
        return Date;
    }
    MyDate IncreasingDateByOneCentury()
    {
        return IncreasingDateByOneCentury(*this);
    }
    
    static MyDate IncreasingDateByXCentury(short Centurys, MyDate Date)
    {
        Date._Year += Centurys * 100;
        return Date;
    }
    MyDate IncreasingDateByXCentury(short Centurys)
    {
        return IncreasingDateByXCentury(Centurys, *this);
    }
    
    static MyDate IncreasingDateByOneMillennium(MyDate Date)
    {
        Date._Year += 1000;
        return Date;
    }
    MyDate IncreasingDateByOneMillennium()
    {
        return IncreasingDateByOneMillennium(*this);
    }
    
    static MyDate DecreaseDateByOneDay(MyDate Date)
    {
        if (Date._Day <= 1)
        {
            if (Date._Month == 1)
            {
                Date._Month = 12;
                Date._Year--;
                Date._Day = NumberOfDaysInAMonth(Date._Year, Date._Month);
            }
            else
            {
                Date._Day = NumberOfDaysInAMonth(Date._Year, --Date._Month);
            }
        }
        else
        {
            Date._Day--;
        }
        return Date;
    }
    MyDate DecreaseDateByOneDay()
    {
        return DecreaseDateByOneDay(*this);
    }
    
    static MyDate DecreaseDateByXDay(short Days, MyDate Date)
    {
        for (short i = 1; i <= Days; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }
    MyDate DecreaseDateByXDay(short Days)
    {
        return DecreaseDateByXDay(Days, *this);
    }
    
    static MyDate DecreaseDateByOneWeek(MyDate Date)
    {
        Date = DecreaseDateByXDay(7, Date);
        return Date;
    }
    MyDate DecreaseDateByOneWeek()
    {
        return DecreaseDateByOneWeek(*this);
    }
    
    static MyDate DecreaseDateByXWeek(short Weeks, MyDate Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }
    MyDate DecreaseDateByXWeek(short Weeks)
    {
        return DecreaseDateByXWeek(Weeks, *this);
    }
    
    static MyDate DecreaseDateByOneMonth(MyDate Date)
    {
        if (Date._Month == 1)
        {
            Date._Year--;
            Date._Month = NumberOfDaysInAMonth(Date._Year, Date._Month);
        }
        else
        {
            Date._Month--;
        }
        return Date;
    }
    MyDate DecreaseDateByOneMonth()
    {
        return DecreaseDateByOneMonth(*this);
    }
    
    static MyDate DecreaseDateByXMonth(short Months, MyDate Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }
    MyDate DecreaseDateByXMonth(short Months)
    {
        return DecreaseDateByXMonth(Months, *this);
    }
    
    static MyDate DecreaseDateByOneYear(MyDate Date)
    {
        Date._Year -= 1;
        return Date;
    }
    MyDate DecreaseDateByOneYear()
    {
        return DecreaseDateByOneYear(*this);
    }
    
    static MyDate DecreaseDateByXYears(short Years, MyDate Date)
    {
        for (short i = 1; i <= Years; i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }
    MyDate DecreaseDateByXYears(short Years)
    {
        return DecreaseDateByXYears(Years, *this);
    }
    
    static MyDate DecreaseDateByXYearsFaster(short Years, MyDate Date)
    {
        Date._Year -= Years;
        return Date;
    }
    MyDate DecreaseDateByXYearsFaster(short Years)
    {
        return DecreaseDateByXYearsFaster(Years, *this);
    }
    
    static MyDate DecreaseDateByOneDecade(MyDate Date)
    {
        Date._Year -= 10;
        return Date;
    }
    MyDate DecreaseDateByOneDecade()
    {
        return DecreaseDateByOneDecade(*this);
    }
    
    static MyDate DecreaseDateByXDecade(short Decade, MyDate Date)
    {
        for (short i = 1; i <= Decade; i++)
        {
            Date = DecreaseDateByOneDecade(Date);
        }
        return Date;
    }
    MyDate DecreaseDateByXDecade(short Decade)
    {
        return DecreaseDateByXDecade(Decade, *this);
    }
    
    static MyDate DecreaseDateByXDecadeFaster(short Decade, MyDate Date)
    {
        Date._Year -= Decade * 10;
        return Date;
    }
    MyDate DecreaseDateByXDecadeFaster(short Decade)
    {
        return DecreaseDateByXDecadeFaster(Decade, *this);
    }
    
    static MyDate DecreaseDateByOneCentury(MyDate Date)
    {
        Date._Year -= 100;
        return Date;
    }
    MyDate DecreaseDateByOneCentury()
    {
        return DecreaseDateByOneCentury(*this);
    }
    
    static MyDate DcereaseDateByXCentury(short Centurys, MyDate Date)
    {
        Date._Year -= Centurys * 100;
        return Date;
    }
    MyDate DcereaseDateByXCentury(short Centurys)
    {
        return DcereaseDateByXCentury(Centurys,*this);
    }
    
    static MyDate DecreaseDateByOneMillennium(MyDate Date)
    {
        Date._Year -= 1000;
        return Date;
    }
    MyDate DecreaseDateByOneMillennium()
    {
        return DecreaseDateByOneMillennium(*this);
    }
    
    static bool IsEndOfWeek(MyDate Date)
    {
        return (DayOfWeekOrder(Date) == 6);
    }
    bool IsEndOfWeek()
    {
        IsEndOfWeek(*this);
    }
    
    static bool IsWeekend(MyDate Date)
    {
        //weekends are Fri and Sat
        int DayOrder = DayOfWeekOrder(Date);
        return (DayOrder == 5 || DayOrder == 6);
    }
    bool IsWeekend()
    {
        return IsWeekend(*this);
    }
    
    static bool IsBesinessDay(MyDate Date)
    {
        //weekend are sun,mon,tue,wed,thur
       /* //long solution
       int DayOrder = DayOfWeekOrder(Date);
        return (DayOrder > 5 && DayOrder <= 4)*/

        //shorter method is to invert the IsWeekEnd : this well Save updating code.
        return !IsWeekend(Date);
    }
    bool IsBesinessDay()
    {
        return IsBesinessDay(*this);
    }
    
    static short DaysUntilTheEndOfWeek(MyDate Date)
    {
        //endofweek : 6 position 
        return 6 - DayOfWeekOrder(Date);
    }
    short DaysUntilTheEndOfWeek()
    {
        return DaysUntilTheEndOfWeek(*this);
    }
    
    static int DaysUntilTheEndOfMonth(MyDate Date)
    {
        MyDate EndOfMontDate;
        EndOfMontDate._Day = NumberOfDaysInAMonth(Date._Year, Date._Month);
        EndOfMontDate._Month = Date._Month;
        EndOfMontDate._Year = Date._Year;

        return GetDifferenceInDays(Date, EndOfMontDate, true);
    }
    int DaysUntilTheEndOfMonth()
    {
        return DaysUntilTheEndOfMonth(*this);
    }
    
    static int DaysUntilTheEndOFYear(MyDate Date)
    {
        MyDate EndOfYearDate;
        EndOfYearDate._Day = 31;
        EndOfYearDate._Month = 12;
        EndOfYearDate._Year = Date._Year;

        return GetDifferenceInDays(Date, EndOfYearDate, true);
    }
    int DaysUntilTheEndOFYear()
    {
        return DaysUntilTheEndOFYear(*this);
    }
    
    static short CalculateVacationDay(MyDate DateFrom, MyDate DateTo)
    {
        short DaysCount = 0; // remember : short size 33,000

        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBesinessDay(DateFrom))
                DaysCount++;

            DateFrom = IncreasingDateByOneDay(DateFrom);
        }
        return DaysCount;
    }
    short CalculateVacationDay(MyDate DateTo)
    {
        return CalculateVacationDay(*this,DateTo);
    }
    
    short ReadVacationDays()
    {
        short Days;
        cout << "\nPlease enter vacation days? ";
        cin >> Days;
        return Days;
    }

    static MyDate CalculateVacationReturnDate(MyDate DateFrom, short VacationDays)
    {

        short WeekEndCounter = 0;

        //in case the data  is weekend keep adding one day util you reach business day
        //we get rid of all weekends before the first business day
        while (IsWeekend(DateFrom))
        {
            DateFrom = IncreasingDateByOneDay(DateFrom);
        }

        //here we increase the vacation dates to add all weekends to it.

        for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
        {

            if (IsWeekend(DateFrom))
                WeekEndCounter++;

            DateFrom = IncreasingDateByOneDay(DateFrom);
        }

        //in case the return date is week end keep adding one day util you reach business day
        while (IsWeekend(DateFrom))
        {
            DateFrom = IncreasingDateByOneDay(DateFrom);
        }

        return DateFrom;

        /* // way 2:
            short NumOfBusinessDays = 0;

        while (true)
        {
            if (IsBusinessDay(Date))
            {
                NumOfBusinessDays++;
            }

            Date = IncreaseDateByOneDay(Date);

            if (NumOfBusinessDays == VacationDays)
                return Date;
        }
        */
    }
    MyDate CalculateVacationReturnDate(short VacationDays)
    {
        return CalculateVacationReturnDate(*this, VacationDays);
    }
    
    enum enDateCompare { Before = -1, Equal = 0, After = 1 };
    static bool IsValidDate(MyDate Date)
    {
        int DaysInMonth = NumberOfDaysInAMonth(Date._Year, Date._Month);
        if (Date._Day < 1 || Date._Day > DaysInMonth)
            return false;

        if (Date._Month < 1 || Date._Month > 12)
            return false;
        /* // i can used this algorithem When I don't use NumberOfDaysInAMonth() function
        if (Date.Month == 2)
          {
              if (IsLeapYear(Date.Year))
              {
                  if (Date.Day > 29)
                      return false;
              }
              else
              {
                  if (Date.Day > 28)
                      return false;
              }
          }*/

        return true;
    }
    bool IsValidDate()
    {
        return IsValidDate(*this);
    }
    
    string ReadStringDate()
    {
        cout << "Enter Date (dd/mm/yyyy) : ";
        string DateString;
        getline(cin >> ws, DateString);
        return DateString;
    }

    string FormateDate(MyDate Date, string DateFormat = "dd/mm/yyyy")
    {
        string FormattedDateString = "";
        FormattedDateString = MyString::Replace(DateFormat, "dd", to_string(Date._Day));
        FormattedDateString = MyString::Replace(FormattedDateString, "mm", to_string(Date._Month));
        FormattedDateString = MyString::Replace(FormattedDateString, "yyyy", to_string(Date._Year));
        return FormattedDateString;
    }
};