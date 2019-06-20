#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

bool is_leap_year(int y){
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

int num_days_in_month(int m, int y){
    const int num_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return num_days[m-1] + (m == 2 && is_leap_year(y)? 1 : 0);
}

/**
 * From date info, determines day of week.
 * 0 - Sat
 * 1 - Sun
 * 2 - Mon
 * 3 - Tue
 * 4 - Wed
 * 5 - Thu
 * 6 - Fri
 * @param d Day
 * @param m Month
 * @param y Year
 */
int get_weekday(int d, int m, int y){
    const int c_common[] = {0,3,3,6,1,4,6,2,5,0,3,5};
    const int c_leap[]   = {6,2,3,6,1,4,6,2,5,0,3,5};
    int a = y%100;
    int c = (is_leap_year(y)? c_leap[m-1] : c_common[m-1]);
    int s = y/100;
    int ds = (int(5*a/4)+c+d-2*(s%4)+7)%7;
    return ds;
}

/*
0 -> 0
1 -> 6
2 -> 5
 */

vector<string> print_month(int m, int y){
    //const string week[] = {"Sab", "Dom", "Seg", "Ter", "Qua", "Qui", "Sex"};
    const string month[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    char b[256];

    vector<string> ret(8);
    sprintf(b, "%d", y);
    ret[0] = month[m-1] + "/" + string(b) + "\t\t\t\t\t\t";
    ret[1] = "Dom\tSeg\tTer\tQua\tQui\tSex\tSab\t";
    int ds = get_weekday(1,m,y);
    int l = 2; int c = (ds+6)%7;
    ret[2] += string(c, '\t');
    int num_days = num_days_in_month(m,y);
    for(int d = 1; d <= num_days; ++d, l += (c==6?1:0), c = (c+1)%7){
        sprintf(b, "%d", d);
        ret[l] += string(b) + "\t";
    }
    ret[l++] += string(7-c, '\t');
    for(; l < 8; ++l){
        ret[l] += "\t\t\t\t\t\t\t";
    }
    return ret;
}

int main(){
    for(unsigned i = 1; i < 12; i += 2){
        vector<string> a1 = print_month(i  ,2011);
        vector<string> a2 = print_month(i+1,2011);
        for(unsigned j = 0; j < a1.size(); ++j){
            cout << a1[j] << "\t" << a2[j] << endl;
        }
        cout << endl;
    }
    return 0;
}
