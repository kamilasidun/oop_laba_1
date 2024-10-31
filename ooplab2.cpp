#include <iostream>
#include <cmath> 
using namespace std;

class TTriangle {
private:
    double a, b, c;

public:
    // Конструктор без параметрів
    TTriangle() : a(0), b(0), c(0) {}

    // Конструктор з параметрами
    TTriangle(double sideA, double sideB, double sideC) {
        if (sideA + sideB <= sideC || sideA + sideC <= sideB || sideB + sideC <= sideA) {
            throw invalid_argument("Sides can't create the triangle");
        }
        a = sideA;
        b = sideB;
        c = sideC;
    }
    
    // Конструктор копіювання
    TTriangle(const TTriangle& other) : a(other.a), b(other.b), c(other.c) {}

    // Метод для введення даних
    void input() {
        cout << "Enter sides of the triangle (a, b, c): ";
        cin >> a >> b >> c;
        if (a + b <= c || a + c <= b || b + c <= a) {
            throw invalid_argument("Sides can't create the triangle");
        }
    }

    // Метод для виведення даних
    void output() const {
        cout << "Sides of the triangle: a = " << a << ", b = " << b << ", c = " << c << endl;
    }

    // Визначення площі трикутника за формулою Герона
    double area() const {
        double smallPerimetr = (a + b + c) / 2;
        return sqrt(smallPerimetr * (smallPerimetr - a) * (smallPerimetr - b) * (smallPerimetr - c));
    }

    // Визначення периметру трикутника
    double perimeter() const {
        return a + b + c;
    }

    // Порівняння трикутників за довжинами сторін
    bool operator==(const TTriangle& other) const {
        return a == other.a && b == other.b && c == other.c;
    }

    // Перевантаження оператора додавання (+)
    TTriangle operator+(const TTriangle& other) const {
        return TTriangle(a + other.a, b + other.b, c + other.c);
    }
    
    // Перевантаження оператора віднімання (-)
    TTriangle operator-(const TTriangle& other) const {
        return TTriangle(a - other.a, b - other.b, c - other.c);
    }

    // Перевантаження оператора множення на число (*)
    TTriangle operator*(double scalar) const {
        return TTriangle(a * scalar, b * scalar, c * scalar);
    }
};

int main() {
    try {
        TTriangle t1(3, 4, 5);
        TTriangle t2(2, 3, 4);

        // Виведення сторін
        t1.output();
        t2.output();

        // Площа і периметр
        cout << "Square of triangle 1: " << t1.area() << endl;
        cout << "Perimetr of triangle 1: " << t1.perimeter() << endl;

        // Порівняння
        if (t1 == t2) {
            cout << "Triangles are the same with the sides" << endl;
        } else {
            cout << "Triangles are different with the sides" << endl;
        }

        // Додавання сторін
        TTriangle t3 = t1 + t2;
        cout << "Triangle after adding the sides: ";
        t3.output();

        // Віднімання сторін
        TTriangle t4 = t1 - t2;
        cout << "Triangle after minusing the sides: ";
        t4.output();

        // Множення сторін на число
        TTriangle t5 = t1 * 2;
        cout << "Triangle 1 after multiplicating it by 2: ";
        t5.output();

    } catch (invalid_argument& error) {
        cerr << "Error: " << error.what() << endl;
    }

    return 0;
}