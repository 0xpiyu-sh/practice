#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Encapsulation: Data and methods bundled within a class.
//    Access specifiers (private, public, protected) control visibility.
class Vehicle {
private:
    string make;
    string model;
    int year;

public:
    // Constructor
    Vehicle(string make, string model, int year) : 
        make(make), model(model), year(year) {}

    // Getter methods (public interface to private data)
    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }

    // Member function
    void displayInfo() const {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << endl;
    }

    // Virtual function for Polymorphism
    virtual void startEngine() const {
        cout << "Vehicle engine starting..." << endl;
    }
};

// 2. Inheritance: Car inherits properties and methods from Vehicle.
class Car : public Vehicle {
private:
    int numDoors;

public:
    // Constructor calling base class constructor
    Car(string make, string model, int year, int numDoors) : 
        Vehicle(make, model, year), numDoors(numDoors) {}

    // Overriding base class method (Polymorphism)
    void startEngine() const override {
        cout << "Car engine starting with a distinct roar!" << endl;
    }

    void displayCarInfo() const {
        displayInfo(); // Reusing base class method
        cout << "Number of Doors: " << numDoors << endl;
    }
};

// 3. Abstraction: Defining a base class with a pure virtual function.
//    Cannot create objects of an abstract class.
class Shape {
public:
    // Pure virtual function (makes Shape an abstract class)
    virtual double calculateArea() const = 0; 
    virtual void displayShape() const = 0;
};

// Concrete class inheriting from abstract class Shape
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }

    void displayShape() const override {
        cout << "This is a Circle with radius " << radius << endl;
    }
};

// Another concrete class inheriting from abstract class Shape
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() const override {
        return length * width;
    }

    void displayShape() const override {
        cout << "This is a Rectangle with length " << length << " and width " << width << endl;
    }
};

int main() {
    // Encapsulation and Objects
    Vehicle myVehicle("Toyota", "Camry", 2020);
    myVehicle.displayInfo();
    myVehicle.startEngine();

    // Inheritance and Polymorphism
    Car myCar("Honda", "Civic", 2022, 4);
    myCar.displayCarInfo();
    myCar.startEngine(); // Calls overridden method

    // Polymorphism with base class pointers/references
    cout << "\nPolymorphism Example:" << endl;
    Vehicle* vPtr1 = &myVehicle;
    Vehicle* vPtr2 = &myCar;

    vPtr1->startEngine(); // Calls Vehicle's startEngine
    vPtr2->startEngine(); // Calls Car's startEngine due to virtual function and override

    // Abstraction and Polymorphism with Shapes
    cout << "\nAbstraction and Shape Example:" << endl;
    vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));

    for (const auto& shape : shapes) {
        shape->displayShape();
        cout << "Area: " << shape->calculateArea() << endl;
    }

    // Clean up dynamically allocated memory
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}
