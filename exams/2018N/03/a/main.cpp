#include <iostream>
#include <numeric>

using namespace std;

float average(const int grades[], int numStudents){
    float ret = accumulate(grades, grades+numStudents, float(0.0));
    return ret/numStudents;
}

void readGrades(int grades[], int numStudents){
    for(int i = 0; i < numStudents; ++i){
        cin >> grades[i];
    }
}

int main(){
    int N; cin >> N;
    int *grades = new int[N];
    readGrades(grades, N);
    cout << average(grades, N) << endl;
    delete[] grades;
    return 0;
}
