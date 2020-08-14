/*
Find the number of Friday 13th in the given year.

Input: Year as an integer.

Output: Number of Black Fridays in the year as an integer.
*/

#include <stdio.h>
#include <time.h>
#include <string.h>


int unlucky_days(int year) {
    int ret = 0;
    struct tm tm;
    char daybuf[20];
    
    tm.tm_year = year-1900;
    tm.tm_mday = 13;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 1;
    tm.tm_isdst = -1;
    for(int i = 0; i<12;i++)
    {
        tm.tm_mon = i; //month number
        if(mktime(&tm) == -1)
        {
            return -1;
        }
        else
        {
            strftime(daybuf, sizeof(daybuf), "%A", &tm);
            if(strcmp(daybuf, "Friday") == 0)
            {
                ret+=1;
            }
        }
    }
    return ret;
}

int main()
{
    printf("%i", unlucky_days(2016) );
    return 0;
}
