#include <iostream>
#include <cmath>
using namespace std;

class TRTriangle {
protected:
    double sideLength; 

public:
    // Constructor without parameters
    TRTriangle() : sideLength(0.0) {}

    // Constructor with parameters
    TRTriangle(double length) : sideLength(length) {}

    // Copy constructor
    TRTriangle(const TRTriangle& other) : sideLength(other.sideLength) {}

    // Input method
    void input() {
        cout << "Enter the length of the side: ";
        cin >> sideLength;
    }

    // Output method
    void output() const {
        cout << "Side length: " << sideLength << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }

    // Method to calculate the area
    double getArea() const {
        return (sqrt(3) / 4) * sideLength * sideLength;
    }

    // Method to calculate the perimeter
    double getPerimeter() const {
        return 3 * sideLength;
    }

    // Method to compare with another triangle
    bool operator==(const TRTriangle& other) const {
        return sideLength == other.sideLength;
    }

    bool operator!=(const TRTriangle& other) const {
        return !(*this == other);
    }

    // Overloading operator +
    TRTriangle operator+(const TRTriangle& other) const {
        return TRTriangle(sideLength + other.sideLength);
    }

    // Overloading operator -
    TRTriangle operator-(const TRTriangle& other) const {
        return TRTriangle(sideLength - other.sideLength);
    }

    // Overloading operator *
    TRTriangle operator*(double multiplier) const {
        return TRTriangle(sideLength * multiplier);
    }

    // Overloading output operator
    friend ostream& operator<<(ostream& os, const TRTriangle& triangle) {
        os << "Side: " << triangle.sideLength << endl;
        return os;
    }

    // Overloading input operator
    friend istream& operator>>(istream& is, TRTriangle& triangle) {
        is >> triangle.sideLength;
        return is;
    }
};

class TPyramid : public TRTriangle {
private:
    double height;

public:
    // Constructor without parameters
    TPyramid() : TRTriangle(), height(0.0) {}

    // Constructor with parameters
    TPyramid(double side, double h) : TRTriangle(side), height(h) {}
    
    // Copy constructor
    TPyramid(const TPyramid& other) : TRTriangle(other), height(other.height) {}

    // Input method
    void input() {
        TRTriangle::input();
        cout << "Enter height: ";
        cin >> height;
    }

    // Output method
    void output() const {
        TRTriangle::output();
        cout << "Height: " << height << endl;
        cout << "Pyramid volume: " << getVolume() << endl;
    }

    // Method to calculate the volume of the pyramid
    double getVolume() const {
        return (getArea() * height) / 3.0;
    }

    // Overloading output operator
    friend ostream& operator<<(ostream& os, const TPyramid& pyramid) {
        os << static_cast<const TRTriangle&>(pyramid);
        os << "Height: " << pyramid.height << endl;
        os << "Volume: " << pyramid.getVolume() << endl;
        return os;
    }

    // Overloading input operator
    friend istream& operator>>(istream& is, TPyramid& pyramid) {
        is >> static_cast<TRTriangle&>(pyramid);
        is >> pyramid.height;
        return is;
    }
};

int main() {
    TRTriangle triangle1(5.0); 
    TRTriangle triangle2(7.0);

    cout << "Information about Triangle 1:" << endl;
    triangle1.output();

    cout << "\nInformation about Triangle 2:" << endl;
    triangle2.output();

    // Adding two triangles
    TRTriangle triangle3 = triangle1 + triangle2;
    cout << "\nResult of adding the sides of two triangles:" << endl;
    triangle3.output();

    // Multiplying the side by a number
    TRTriangle triangle4 = triangle1 * 2;
    cout << "\nResult of multiplying the side of the first triangle by 2:" << endl;
    triangle4.output();

    // Pyramid
    TPyramid pyramid(5.0, 10.0);
    cout << "\nInformation about the pyramid:" << endl;
    pyramid.output();

    return 0;
}