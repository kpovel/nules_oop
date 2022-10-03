#include <iostream>

using namespace std;

class Hourglass {
    int height;
    int weight;
public:
    Hourglass() {
        this->height = 0;
        this->weight = 0;
    }

    Hourglass(int height, int weight) {
        this->height = height;
        this->weight = weight;
    }

    int getHeight() {
        return height;
    }

    int getWeight() {
        return weight;
    }

    int setHeight(int newHeight) {
        this->height = newHeight;
    }

    int setWeight(int newWeight) {
        this->weight = newWeight;
    }

    int calcArea() const {
        int area = (height / 2) * weight * 2;
        return area;
    }

    friend void operator<<(ostream &t, Hourglass &obj) {
        cout << "Height: " << obj.height << "\n"
             << "Weight: " << obj.weight << "\n"
             << "Area: " << obj.calcArea() << "\n\n";
    }

    void operator++() {
        height++;
        weight++;
    }

    static Hourglass createNewHourglass(Hourglass h1, Hourglass h2) {
        Hourglass newFigure;
        newFigure.height = h1.height + h2.height;
        newFigure.weight = h1.weight + h2.weight;
        return newFigure;
    }
};

int main() {
    Hourglass h1(10, 5);
    Hourglass h2(20, 10);

    cout << h1;

    Hourglass newFigure = Hourglass::createNewHourglass(h1, h2);
    ++newFigure;
    cout << newFigure;

    return 0;
}
