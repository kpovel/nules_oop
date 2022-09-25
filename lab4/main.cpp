#include <iostream>
#include <list>

using namespace std;

class Array {
private:
    list<double> nums;
public:
    Array(double n) {
        srand(time(0));
        for (int i = 0; i < n; i++) {
            int number = (rand() % 10) + 1;

            if (number % 2 == 0) {
                nums.push_front(number + 5.1);
            } else {
                nums.push_front(number - 4.1);
            }
        }
    }

    ~Array() {
        nums.clear();
        nums.empty();
    }

    list<double> getNums() {
        return nums;
    }

    void printElements() {
        for (double n: nums) {
            cout << n << '\n';
        }
    }
};


double sumOfSecondsElements(Array a) {
    double sum = 0;
    list<double> nums = a.getNums();

    list<double>::iterator it = nums.begin();

    for (int i = 0; i < nums.size() - 1; ++i) {
        advance(it, i);
        if (i % 2 != 0) sum += *it;
    }

    return sum;
}

int main() {
    Array arrayOfNumbers(12);
    arrayOfNumbers.printElements();

    double res = sumOfSecondsElements(arrayOfNumbers);
    cout << "The sum of every seconds elements: " << res;

    return 0;
}