#include <iostream>
#include <vector>

using namespace std;

class Vehicle {
protected:
    int wheels;
    int speed;
public:
    Vehicle(int wheels, int speed)
     : wheels(wheels), speed(speed) {
    }
    int getWheels() {
        return wheels;
    }
    float getSpeed() {
        return speed;
    }
    virtual float getDuration(float distance) {
        return distance / getSpeed();
    }
    virtual string getName() = 0;
};

class Car : public Vehicle {
    int capacity;
public:
    Car(int capacity) 
        : Vehicle(4, 20), 
          capacity(capacity) {
    }
    string getName() {
        return "Автомобиль";
    }
    int getCapacity() const {
        return capacity;
    }
};

class Bike : public Vehicle {
public:
    Bike() : Vehicle(2, 8) {
    }

    string getName() {
        return "Велосипед";
    }

    float getDuration(float distance) {
        return distance / getSpeed() * 1.1;
    }
};

int main() {
    setlocale(LC_ALL, "");

    vector<Vehicle*> vehicles;
    Car* car = new Car(5);
    Bike* bike = new Bike();
    vehicles.push_back(car);
    vehicles.push_back(bike);

    for (Vehicle* vehicle : vehicles) {
        cout << vehicle->getName() << " ";
        cout << vehicle->getDuration(1000)/60 << endl;
    }
    return 0;
}
