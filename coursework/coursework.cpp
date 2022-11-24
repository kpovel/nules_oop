#include <iostream>
#include <fstream>
#include <list>


using namespace std;

const int MAX_VALID_YR = 2100;
const int MIN_VALID_YR = 1800;

bool isLeap(int year) {
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool isValidDate(int d, int m, int y) {
    if (y > MAX_VALID_YR || y < MIN_VALID_YR)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;

    if (m == 2) {
        if (isLeap(y))
            return (d <= 29);
        else
            return (d <= 28);
    }

    if (m == 4 || m == 6 || m == 9 || m == 11) return (d <= 30);
    return true;
}

class Book {
    string bookTitle;
    string authorName;
public:
    Book(string title, string author) {
        this->bookTitle = title;
        this->authorName = author;
    }

    string getBookTitle() {
        return bookTitle;
    }

    string getAuthorName() {
        return authorName;
    }
};

class Library {
    Book *book;
    string clientSurname;
    int day;
    int month;
    int year;
public:
    Library() = default;

    Library(Book *book, string clientSurname, int day, int month, int year) {
        this->book = book;
        this->clientSurname = clientSurname;
        if (isValidDate(day, month, year)) {
            this->day = day;
            this->month = month;
            this->year = year;
        } else {
            cout << "Not valid date \n";
        }
    }

    string getClientSurname() {
        return clientSurname;
    }

    int getDayReturn() const {
        return day;
    }

    int getMothReturn() const {
        return month;
    }

    int getYearReturn() const {
        return year;
    }

    int checkDate(const int date[3]) const {
        bool deadlineDeliveryRunoff = (getYearReturn() > date[2]) ||
                                      (getYearReturn() >= date[2] && getMothReturn() > date[1]) ||
                                      (getYearReturn() >= date[2] && getMothReturn() >= date[1] &&
                                       getDayReturn() > date[0]);
        bool deadlineExpiresToday = getYearReturn() == date[2] && getMothReturn() == date[1] &&
                                    getDayReturn() == date[0];
        if (deadlineDeliveryRunoff) return -1;
        if (deadlineExpiresToday) return 0;
        return 1;
    }

    friend ostream &operator<<(ostream &out, Library &obj) {
        out << obj.clientSurname << " " << obj.day << " " << obj.month << " " << obj.year
            << " " << obj.book->getAuthorName() << " " << obj.book->getBookTitle() << endl;
        return out;
    }

    friend istream &operator>>(istream &in, Library &obj) {
        string authorName = obj.book->getAuthorName();
        string bookTitle = obj.book->getBookTitle();

        in >> obj.clientSurname;
        in >> obj.day;
        in >> obj.month;
        in >> obj.year;
        in >> authorName;
        in >> bookTitle;

        return in;
    }
};

void showResult(list<Library> &clientList, const string &description) {
    cout << description << ": ";

    clientList.sort([](Library f, Library s) {
        return f.getClientSurname() < s.getClientSurname();
    });

    if (clientList.empty()) {
        cout << "there are no such clients";
    }

    for (Library client: clientList) {
        cout << client.getClientSurname() << ", ";
    }

    cout << "\n\n";
}

int main() {
    Book book1("Factor-Churchill", "Jonson");
    Book book2("Testament", "Shevchencko");
    Book book3("City", "Pidmohylnyi");
    Library library1(&book1, "Karas", 12, 2, 2022);
    Library library2(&book2, "Ivanov", 24, 4, 2005);
    Library library3(&book2, "Petrov", 11, 2, 2008);
    Library library4(&book3, "Petrov", 22, 6, 2021);
    Library library5(&book2, "Karas", 17, 8, 2021);

    ofstream out("in.txt");

    out << library1;
    out << library2;
    out << library3;
    out << library4;
    out << library5;

    out.close();


    int todayDate[3];

    cout << "Enter today's date in this format (11 11 2011): ";
    cin >> todayDate[0] >> todayDate[1] >> todayDate[2];

    ifstream in("in.txt");
    list<Library> listOfDebtors;
    list<Library> listOfDelay;
    while (!in.eof()) {
        Library library;
        in >> library;
        if (in.eof()) break;
        if (!isValidDate(todayDate[0], todayDate[1], todayDate[2])) {
            cout << "The entered date is invalid";
            break;
        }

        int checkClientStatus = library.checkDate(todayDate);
        if (checkClientStatus == -1) {
            listOfDebtors.push_back(library);
        } else if (checkClientStatus == 0) {
            listOfDelay.push_back(library);
        }
    }

    showResult(listOfDebtors, "List of debtors");
    showResult(listOfDelay, "list of delay");

    in.close();

    return 0;
}
