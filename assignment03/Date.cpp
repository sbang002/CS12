#include "Date.h"
#include <iostream>

using namespace std;

bool Date::isLeap( unsigned y) const
{
    if(y%4 == 0)
    {
        if(!(y%100 == 0))
        {
            return true;
        }
        else
        {
            if(y%400 == 0)
            { return true;}
        }
    }
    return false;
}

//DAYS PER MONTH :: returns 0 if invalid month
unsigned Date::daysPerMonth(unsigned m, unsigned y)const
{
    //what do you do if month goes over
    int d;
    if((m > 12))
    {
        d = 0;
    }
    else if(m < 1)
    {
        d = 0;
    }
    else if((m == 1)||(m == 3)||(m == 5) ||(m == 7)||(m == 8)||(m == 10)||(m == 12))
    {
        d = 31;
    }
    else if(m == 2)
    {
        if(isLeap(y))
        {   
            d = 29;
        }
        else 
        {
            d = 28;
        }
    }
    else if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
    {
        d = 30;
    }
    
    return d;
}

// # --> name
std::string Date::name( unsigned m ) const
{
    
    if (m < 1)
    {
        return "January";
    }
    if(m == 1)
    {
        return "January";
    }
    if(m == 2)
    {
        return "February";
    }
    if(m == 3)
    {
        return "March";
    }
    if(m == 4)
    {
        return "April";
    }
    if(m == 5)
    {
        return "May";
    }
    if(m == 6)
    {
        return "June";
    }
    if(m == 7)
    {
        return "July";
    }
    if(m == 8)
    {
        return "August";
    }
    if(m == 9)
    {
        return "September";
    }
    if(m == 10)
    {
        return "October";
    }
    if(m == 11 )
    {
        return "November";
    }
    if(m == 12)
    {
        return "December";
    }
    if(m > 12)
    {
        return "December";
    }
}

//Months name --> # :: what if name is not valid
unsigned Date::number( const std::string &mn ) const
{
    if((mn == "January") || (mn == "january"))
    {
        return 1;
    }
    else if((mn == "February") || (mn == "february"))
    {
        return 2;
    }
    else if((mn == "March") || (mn == "march"))
    {
        return 3;
    }
    else if((mn == "April") || (mn == "april"))
    {
        return 4;
    }
    else if((mn == "May") || (mn == "may"))
    {
        return 5;
    }
    else if((mn == "June") || (mn == "june"))
    {
        return 6;
    }
    else if((mn == "July") || (mn == "july"))
    {
        return 7;
    }
    else if((mn == "August") || (mn == "august"))
    {
        return 8;
    }
    else if((mn == "September") || (mn == "september"))
    {
        return 9;
    }
    else if((mn == "October") || (mn == "october"))
    {
        return 10;
    }
    else if((mn == "November") || (mn == "november"))
    {
        return 11;
    }
    else if((mn == "December") || (mn == "december"))
    {
        return 12;
    }
    else
    {
        return 0;
    }
    
}

Date::Date()
{
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
}

Date::Date(unsigned m,unsigned d,unsigned y)
{
    int change = 0;
    day = d;
    month = m;
    year = y;
    
    if(month < 1)
    {
        month = 1;
        change = 1;
    }
    else if(month > 12)
    {
        month = 12;
        change = 1;
    }
  
    
    while((day > daysPerMonth(month,y)) || (day == 0))
    {
        if(day > daysPerMonth(month,y))
        {
            day = daysPerMonth(month,y); 
            change = 2;
        }
        else
        {
            day = 1;
            change = 2;
        }
    }
    
    if(change == 1)
    {
        cout << "Invalid month values: Date corrected to " << month << '/' <<day
            << '/' << year << endl;
    }
    if(change == 2)
    {
        cout << "Invalid date values: Date corrected to " << month << '/' <<day
            << '/' << year << endl;
    }
    monthName = name(month);

}

Date::Date(const string&mn, unsigned d, unsigned y)
{
    
    day = d;
    month = 0;
    monthName = mn;
    year = y;
    
    if(!number(monthName))
    {
        month = 1;
        day = 1;
        year = 2000;
        monthName = "January";
        
        cout << "Invalid month name: the Date was set to " << month << '/' 
            << day << '/' << year << endl;
    }
    else
    {
        int change;
        month = number(monthName);
         do
        {
            if(!daysPerMonth(month,year))
            {
                month = 12;
                change = 1;
            }
            else
            {
                if(day > daysPerMonth(month,y))
                {
                    day = daysPerMonth(month,y);
                    change = 1;
                }
            }
        }while(day > daysPerMonth(month,year));
        
        if(change == 1)
        {
            cout << "Invalid date values: Date corrected to " << month 
                << '/' << day << '/' << year << endl;
        }
    }
    
}


void Date::printNumeric( )  const
{
    cout << month << '/' << day << '/' << year;
}

void Date::printAlpha( )  const
{
    
    cout << monthName << ' ' << day << ", " << year;
}

