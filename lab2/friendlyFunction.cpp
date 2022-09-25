// Option 11
#include <iostream>

using namespace std;

class ComplexNumber {
    int realPart;
    int imaginaryPart;
public:
    ComplexNumber() {
        this->realPart = 0;
        this->imaginaryPart = 0;
    }

    ComplexNumber(int realPart, int imaginaryPart) {
        this->realPart = realPart;
        this->imaginaryPart = imaginaryPart;
    }

    void set() {
        cout << "Enter Real part: ";
        cin >> realPart;
        cout << "Enter Imaginary Part: ";
        cin >> imaginaryPart;
    }

    void get() const {
        cout << "The complex number is: " << realPart << " + " << imaginaryPart << "i" << endl;
    }

    void showResult() const {
        if (imaginaryPart < 0) {
            if (imaginaryPart == -1) {
                cout << "The complex number is: " << realPart << " - i" << "\n";
            } else {
                cout << "The complex number is: " << realPart << imaginaryPart << "i" << "\n";
            }
        } else if (imaginaryPart == 1) {
            cout << "The complex number is: " << realPart << " + i" << "\n";
        } else {
            cout << "The complex number is: " << realPart << " + " << imaginaryPart << "i" << "\n";
        }
    }

    friend ComplexNumber add(ComplexNumber, ComplexNumber);

    friend ComplexNumber sub(ComplexNumber, ComplexNumber);
};

ComplexNumber add(ComplexNumber c1, ComplexNumber c2) {
    ComplexNumber result;
    result.realPart = c1.realPart + c2.realPart;
    result.imaginaryPart = c1.imaginaryPart + c2.imaginaryPart;
    return result;
}

ComplexNumber sub(ComplexNumber c1, ComplexNumber c2) {
    ComplexNumber result;

    result.realPart = c1.realPart - c2.realPart;
    result.imaginaryPart = c1.imaginaryPart - c2.imaginaryPart;
    return result;
}


int main() {
    ComplexNumber n1(5, 2);
    ComplexNumber n2(4, 3);

    ComplexNumber result = add(n1, n2);
    result.showResult();

    return 0;
}
