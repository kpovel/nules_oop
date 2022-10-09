#include <iostream>

using namespace std;


class Vehicle {
protected:
    string color;
public:
    Vehicle() {
        this->color = "none";
    }

    Vehicle(string color) {
        this->color = color;
    }

    void setColor(string color) {
        this->color = color;
    }

    void showColor() {
        cout << "Vehicle color: " << color << "\n";
    }
};

class Train : public Vehicle {
protected:
    int numberWagons;
    string trainType;
public:
    Train() {
        this->numberWagons = 1;
        this->trainType = "default";
    }

    Train(int numberWagons, string trainType) {
        this->numberWagons = numberWagons;
        this->trainType = trainType;
    }
};

class Car : public Vehicle {
protected:
    int numberSeats;
    string carType;
public:
    Car() {
        this->numberSeats = 1;
        this->carType = "passenger";
    }

    Car(int numberSeats, string carType) {
        this->numberSeats = numberSeats;
        this->carType = carType;
    }

    void setNumberSeats(int numberSeats) {
        this->numberSeats = numberSeats;
    }

    void setCarType(string carType) {
        this->carType = carType;
    }

    void getCarInfo() {
        cout << "Number seats: " << numberSeats << "\n" <<
             "Car type: " << carType << "\n";
    }
};

class Taxi : public Car {
    int price;
public:
    Taxi() {
        this->price = 0;
    }

    Taxi(int price) {
        this->price = price;
    }

    void showTaxiInfo() {
        cout << "Taxi has color: " << color << "\n" <<
             "Number seats: " << numberSeats << "\n" <<
             "Car type: " << carType << "\n" <<
             "Price per ride: " << price << "$" << "\n";
    }

};


int main() {
    Taxi n(300);
    n.setColor("yellow");
    n.setCarType("passenger");
    n.setNumberSeats(5);
    n.showTaxiInfo();

    return 0;
}