#include <iostream>
using namespace std;
 
// =============== PART 1: FUNCTION OVERLOADING (compile-time) ===============
// Same function name area(), but different parameters
double area(int side) {                 // area of a square
    if (side <= 0) {                    // boundary case: invalid side
        cout << "  Error: side must be greater than 0" << endl;
        return 0;
    }
    return side * side;
}
 
double area(int length, int breadth) {  // area of a rectangle
    if (length <= 0 || breadth <= 0) {
        cout << "  Error: length and breadth must be greater than 0" << endl;
        return 0;
    }
    return length * breadth;
}
 
double area(double radius) {            // area of a circle
    if (radius <= 0) {
        cout << "  Error: radius must be greater than 0" << endl;
        return 0;
    }
    return 3.14 * radius * radius;
}
 
// =============== PART 2: OPERATOR OVERLOADING (compile-time) ===============
// Complex number class: we teach the + and == operators to work on objects
class Complex {
private:
    int real;
    int imag;
public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }
    Complex operator+(Complex c) {      // c1 + c2
        return Complex(real + c.real, imag + c.imag);
    }
    bool operator==(Complex c) {        // c1 == c2
        return (real == c.real && imag == c.imag);
    }
    void display() {
        cout << real << " + " << imag << "i";
    }
};
 
// =============== PART 3: VIRTUAL FUNCTION (run-time) ===============
class Animal {
public:
    void eat() {                        // normal function (NOT virtual)
        cout << "  Animal eats food" << endl;
    }
    virtual void sound() {              // virtual function
        cout << "  Animal makes a sound" << endl;
    }
    virtual ~Animal() {}
};
 
class Dog : public Animal {
public:
    void eat() {
        cout << "  Dog eats bones" << endl;
    }
    void sound() {
        cout << "  Dog barks: Woof Woof" << endl;
    }
};
 
class Cat : public Animal {
public:
    void sound() {
        cout << "  Cat meows: Meow Meow" << endl;
    }
};
 
// =============== PART 4: ABSTRACT CLASS (pure virtual function) ===============
class Shape {
public:
    virtual double getArea() = 0;       // pure virtual: no body, derived classes must write it
    virtual ~Shape() {}
};
 
class Circle : public Shape {
    double radius;
public:
    Circle(double r) { radius = r; }
    double getArea() { return 3.14 * radius * radius; }
};
 
class Rectangle : public Shape {
    double length, breadth;
public:
    Rectangle(double l, double b) { length = l; breadth = b; }
    double getArea() { return length * breadth; }
};
 
int main() {
    // ----- Part 1 -----
    cout << "===== 1. Function overloading: area() =====" << endl;
    cout << "  Square (side 5)          : " << area(5) << endl;
    cout << "  Rectangle (4 x 6)        : " << area(4, 6) << endl;
    cout << "  Circle (radius 2.0)      : " << area(2.0) << endl;
    cout << "  Square (side -3):" << endl;
    double r = area(-3);
    cout << "  Value returned           : " << r << endl;
 
    // ----- Part 2 -----
    cout << "\n===== 2. Operator overloading: + and == =====" << endl;
    Complex c1(2, 3), c2(4, 5), c3;     // c3 is (0 + 0i) by default
    Complex sum = c1 + c2;
    cout << "  (2 + 3i) + (4 + 5i) = ";
    sum.display();
    cout << endl;
    Complex sum2 = c3 + c1;
    cout << "  (0 + 0i) + (2 + 3i) = ";
    sum2.display();
    cout << endl;
    cout << "  c1 == c2 ? " << (c1 == c2 ? "Yes" : "No") << endl;
    cout << "  c1 == (2 + 3i) ? " << (c1 == Complex(2, 3) ? "Yes" : "No") << endl;
 
    // ----- Part 3 -----
    cout << "\n===== 3. Virtual function (run-time polymorphism) =====" << endl;
    Dog d;
    Cat c;
    Animal *a1 = &d;                    // base class pointer pointing to Dog object
    Animal *a2 = &c;                    // base class pointer pointing to Cat object
    cout << "  Non-virtual eat() through base pointer:" << endl;
    a1->eat();                          // calls Animal::eat (no virtual)
    cout << "  Virtual sound() through base pointer:" << endl;
    a1->sound();                        // calls Dog::sound
    a2->sound();                        // calls Cat::sound
 
    // ----- Part 4 -----
    cout << "\n===== 4. Abstract class and pure virtual function =====" << endl;
    Shape *shapes[3];
    Circle circle(3);
    Rectangle rect(4, 5);
    Rectangle zeroRect(0, 5);           // boundary case: zero length
    shapes[0] = &circle;
    shapes[1] = &rect;
    shapes[2] = &zeroRect;
    for (int i = 0; i < 3; i++) {
        cout << "  Shape " << i + 1 << " area = " << shapes[i]->getArea() << endl;
    }
 
    cout << "\nProgram finished successfully." << endl;
    return 0;
}

