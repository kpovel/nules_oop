// Option 3

#include <iostream>
#include <cmath>
#include <list>

using namespace std;

class Cylinder {
private:
    string figureName;
    double radius;
    double height;
public:
    Cylinder() {
        this->figureName = "";
        this->radius = 0;
        this->height = 0;
    }

    Cylinder(string figureName, double radius, double height) {
        this->figureName = figureName;
        this->radius = radius;
        this->height = height;
    }

    double getVolume() const {
        return M_PI * pow(radius, 2) * height;
    }

    double getRadius() {
        return radius;
    }

    double getHeight() {
        return height;
    }

    string numberToString(double num) {
        std::string str = std::to_string(num);
        str.erase(str.find_last_not_of('0') + 1, std::string::npos);
        return str.erase(str.find_last_not_of('.') + 1, std::string::npos);
    }

    string print_val() {
        return figureName.append(" has radius: ").append(numberToString(radius))
                .append(", \n height: ").append(numberToString(height))
                .append(", \n volume: ").append(numberToString(getVolume()));
    }
};


int main() {

    list<Cylinder> figure;

    Cylinder cylinder1("figure1", 10, 10);
    Cylinder cylinder2("figure2", 20.5, 9.3);

    figure.push_back(cylinder1);
    figure.push_back(cylinder2);


    for (Cylinder f: figure) {
        std::cout << f.print_val() << "\n";
    }

    return 0;
}

