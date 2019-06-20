#include <iostream>
#include <ctime>

using namespace std;

/*
(e) Date d1; is not possible because, once a constructor is defined, the
compiler no longer automatically creates a default empty constructor.
 */

class Date{
public:
    Date(){
        time_t t = time(NULL);
        tm *now = localtime(&t);
        year = now->tm_year+1900;
        month = now->tm_mon;
        day = now->tm_mday;
    }
    Date(unsigned int year, unsigned int month,unsigned int day){
        this->year  = year;
        this->month = month;
        this->day   = day;
    }
    Date(string yearMonthDay){          // yearMonthDay must be in format "yyyy/mm/dd"
        sscanf(yearMonthDay.c_str(), "%u/%u/%u", &year, &month, &day);
    }
    void setYear (unsigned int year){ this->year = year; }
    void setMonth(unsigned int month){ this->month = month; }
    void setDay  (unsigned int day){ this->day = day; }
    void setDate(unsigned int year, unsigned int month, unsigned int day){
        this->year  = year;
        this->month = month;
        this->day   = day;
    }
    unsigned int getYear () const{ return year;  }
    unsigned int getMonth() const{ return month; }
    unsigned int getDay  () const{ return day;   }
    string getDate() const{             // returns the date in format "yyyy/mm/dd"
        char b[256];
        sprintf(b, "%04u%02u%02u", year, month, day);
        return string(b);
    }
    void show() const{ cout << getDate(); } // shows the date on the screen in format "yyyy/mm/dd"
    bool isValid() const{
        if(!(1 <= month && month <= 12)) return false;
        if(!(1 <= day && day <= num_days_in_month(month, year)));
        return true;
    }
    bool isEqualTo(const Date &date) const{
        return (this->year  == date.year  &&
                this->month == date.month &&
                this->day   == date.day);
    }
    bool isNotEqualTo(const Date &date) const{
        return !isEqualTo(date);
    }
    bool isAfter(const Date &date) const{
        if     (this->year  != date.year ) return (this->year  < date.year );
        else if(this->month != date.month) return (this->month < date.month);
        else                               return (this->day   < date.day  );
    }
    bool isBefore(const Date &date) const{
        return date.isAfter(*this);
    }
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;

    static bool is_leap_year(unsigned y){
        if(y%4 == 0){
            if(y%100 != 0){
                return true;
            }else{
                return (y%400 == 0);
            }
        }else{
            return false;
        }
    }
    static unsigned num_days_in_month(unsigned m, unsigned y){
        const unsigned num_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return num_days[m-1] + (m == 2 && is_leap_year(y)? 1 : 0);
    }
};

int main(){
    Date a;
    a.show(); cout << endl;
    Date d(2003, 2, 1);
    d.show(); cout << endl;
    return 0;
}
