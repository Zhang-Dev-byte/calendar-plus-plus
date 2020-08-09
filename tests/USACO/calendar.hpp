/*      CALENDAR-PLUS-PLUS      
        
        
        GNU GENERAL PUBLIC LICENSE
        Version 3, 29 June 2007

Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
Everyone is permitted to copy and distribute verbatim copies
of this license document, but changing it is not allowed.*/

#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#define SUNDAY 0
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>

namespace cal{
    class Day{
    public:
        Day(int day){
            this->day = day;
        }
        explicit operator int() const { return day; }

        void operator +=(int count) { day += count; }
        int operator + (int other) { return day + other; }
    private:
        int day;
    };
    extern int calGetDaysInMonth(int month, int year){
        switch(month){
            case 9:
            case 4:
            case 6:
            case 11:
                return 30;
            case 2:
                if(year%4==0 && year%100!=0 || year%400==0)
                    return 29;
                else
                    return 28;
            default:
                return 31;
        }
    }
    extern float calGetVersion(){
        return 1.0f;
    }
}
#endif