// Option 11
#include <iostream>
#include <list>
#include <fstream>

using namespace std;

class Student {
private:
    string studentName;
    int mathGrade;
    int physicsGrade;
    int informaticsGrade;
public:
    Student() {
        this->studentName = "";
        this->mathGrade = 0;
        this->physicsGrade = 0;
        this->informaticsGrade = 0;
    }

    Student(string studentName, int mathGrade, int physicsGrade, int informaticsGrade) {
        this->studentName = studentName;
        this->mathGrade = mathGrade;
        this->physicsGrade = physicsGrade;
        this->informaticsGrade = informaticsGrade;
    }

    void showSuccessfulStudent() {
        const int averageGrade = (mathGrade + physicsGrade + informaticsGrade) / 3;
        const int goodGrade = averageGrade >= 4;

        if (goodGrade) {
            cout << studentName.append(" has grades: ").append(to_string(mathGrade))
                    .append(", ").append(to_string(physicsGrade))
                    .append(", ").append(to_string(informaticsGrade)).append("\n");
        }
    }

    friend ostream &operator<<(ostream &out, Student &obj) {
        out << obj.studentName << " " << obj.mathGrade << " "
            << obj.physicsGrade << " " << obj.informaticsGrade << "\n";
        return out;
    }

    friend istream &operator>>(istream &in, Student &obj) {
        in >> obj.studentName;
        in >> obj.mathGrade;
        in >> obj.physicsGrade;
        in >> obj.informaticsGrade;
        return in;
    }
};

int main() {
    Student student1("Jim", 4, 3, 5);
    Student student2("El", 4, 4, 3);
    Student student3("Mike", 4, 5, 5);
    Student student4("Will", 4, 3, 5);
    Student student5("Dustin", 5, 4, 5);

    ofstream out("students.txt");

    out << student1;
    out << student2;
    out << student3;
    out << student4;
    out << student5;

    out.close();

    ifstream in("students.txt");

    while (!in.eof()) {
        Student person;
        in >> person;
        if (in.eof()) break;
        person.showSuccessfulStudent();
    }
    in.close();

    return 0;
}