#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * (a) The weights are static because they are not associated with one
 * particular student, but rather to all students (since all the students are
 * evaluated based on the same formula). Therefore, it would not make sense to
 * declare the same values (and thus taking up memory) for values that are the
 * same for all students.
 */

class Student {
public:
    Student(){}
    Student(const string &code, const string &name){
        this->code = code;
        this->name = name;
    }
    void setGrades(double shortExam, double project, double exam){
        this->shortExam  = shortExam;
        this->project    = project;
        this->exam       = exam;
        int totalWeights = weightShortExam+weightProject+weightExam;
        double finalDouble = this->shortExam*weightShortExam + this->project*weightProject + this->exam*weightExam;
        finalDouble = finalDouble/totalWeights;
        finalGrade       = int(finalDouble) + (finalDouble-double(int(finalDouble)) >= 0.5L ? 1 : 0);
    }
    string getCode() const{ return code; }
    string getName() const{ return name; }
    int getFinalGrade() const{ return finalGrade; }
    // other get and set methods
    bool isApproved() const{ return (finalGrade >= 10); } // is the student approved or not ?
    static int weightShortExam, weightProject, weightExam; // weights in percentage (ex:20,30,50)
private:
    string code; // student code
    string name; // student complete name
    double shortExam, project, exam; // grades obtained by the student in the different components
    int finalGrade;
};
int Student::weightShortExam = 20;
int Student::weightProject = 30;
int Student::weightExam = 50;

Student readStudentData(istream &is, ostream &os){
    string code;
    char name[256];
    os << "Student code? "; is >> code; is.ignore(256,'\n');
    os << "Student name? "; is.getline(name, 256);
    Student ret(code, string(name));
    double shortExam, project, exam;
    os << "Short exam grade? "; is >> shortExam;
    os << "Project grade? "; is >> project;
    os << "Exam grade? "; is >> exam;
    ret.setGrades(shortExam, project, exam);
    return ret;
}

Student readStudentData(istream &is){
    string code;
    char name[256];
    is >> code; is.ignore(256,'\n');
    is.getline(name, 256);
    Student ret(code, string(name));
    double shortExam, project, exam;
    is >> shortExam;
    is >> project;
    is >> exam;
    ret.setGrades(shortExam, project, exam);
    return ret;
}

void showAboveAverageStudents(ostream& os, const vector<Student>& v){
    double avgGrade = 0.0;
    for(const auto& s: v) avgGrade += s.getFinalGrade();
    avgGrade /= v.size();
    cout << setfill(' ') << left << setw(15) << "Code" << setw(40) << "Name" << right << setw(15) << "Final grade" << setw(12) << "Approved" << endl;
    for(const auto& s: v){
        if(s.getFinalGrade() > avgGrade){
            cout << setfill(' ') << left << setw(15) << s.getCode() << setw(40) << s.getName() << right << setw(15) << s.getFinalGrade() << setw(12) << (s.isApproved()? "yes":"no") << endl;
        }
    }
}

void getStudentList(){
    int N; cout << "How many students? "; cin >> N;
    vector<Student> v(N);
    for(auto& s:v)
        s = readStudentData(cin, cout);
    showAboveAverageStudents(cout, v);
}

void readFromFile(string s){
    ifstream ifs(s);
    char line[1024];
    vector<Student> v;
    while(true){
        ifs.getline(line, 1000);
        if(!ifs) break;
        string str(line);
        replace(str.begin(), str.end(), ';','\n');
        istringstream iss(str);
        v.push_back(readStudentData(iss));
    }
    showAboveAverageStudents(cout, v);
}

int main(){
    readFromFile("02_in.txt");
    return 0;
}
