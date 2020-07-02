#pragma once

#include <iostream>

using namespace std;

class Date{
    friend istream& operator>>(istream &f, Date &date);
    friend ostream& operator<<(ostream &f, const Date &date);
    friend bool operator<(const Date &left, const Date &right);
    friend bool operator==(const Date &left, const Date &right);
public:
    Date(int y=1, int m=1, int d=1);
private:
    int y, m, d;
};

Date::Date(int y, int m, int d){
    this->y = y;
    this->m = m;
    this->d = d;
}

bool operator<(const Date &left, const Date &right){
    int l = 10000*left.y + 100*left.m + left.d;
    int r = 10000*right.y + 100*right.m + right.d;
    return (l<r);
}

#include <stdexcept>
#include <cstdio>
istream& operator>>(istream &f, Date &date){
    string s; f >> s;
    int r = sscanf(s.c_str(), "%d-%d-%d", &date.y, &date.m, &date.d);
    if(r != 3) throw runtime_error("invalid Date");
    return f;
}
