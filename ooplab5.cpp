#include <iostream>
#include <stdexcept>

using namespace std;

// Інтерфейс для розв'язання системи 2 рівнянь з 2 невідомими
class TwoEquationsSolver {
public:
    virtual void solve(double a1, double b1, double c1,
                       double a2, double b2, double c2,
                       double& x, double& y) = 0; // Передаємо x та y через посилання
                //solve() шукає значення x та y, які одночасно задовольняють обидва ці рівняння.
    virtual ~TwoEquationsSolver() = default;
};

// Інтерфейс для розв'язання системи 3 рівнянь з 3 невідомими
class ThreeEquationsSolver {
public:
    virtual void solve(double a1, double b1, double c1, double d1,
                       double a2, double b2, double c2, double d2,
                       double a3, double b3, double c3, double d3,
                       double& x, double& y, double& z) = 0; // Передаємо змінні через посилання
    virtual ~ThreeEquationsSolver() = default;
};

// Клас для розв'язання системи 2 рівнянь з 2 невідомими
class TwoEquations : public TwoEquationsSolver {
public:
    void solve(double a1, double b1, double c1,
               double a2, double b2, double c2,
               double& x, double& y) override {
        double det = a1 * b2 - a2 * b1;
        if (det == 0) {
            throw runtime_error("Система не має єдиного розв'язку.");
        } //throw дозволяє сигналізувати про помилки та виняткові ситуації.
        x = (c1 * b2 - c2 * b1) / det;
        y = (a1 * c2 - a2 * c1) / det;
    }
};

// Клас для розв'язання системи 3 рівнянь з 3 невідомими
class ThreeEquations : public ThreeEquationsSolver {
public:
    void solve(double a1, double b1, double c1, double d1,
               double a2, double b2, double c2, double d2,
               double a3, double b3, double c3, double d3,
               double& x, double& y, double& z) override {
        double det = a1 * (b2 * c3 - b3 * c2)
                   - b1 * (a2 * c3 - a3 * c2)
                   + c1 * (a2 * b3 - a3 * b2);

        if (det == 0) {
            throw runtime_error("Система не має єдиного розв'язку.");
        }

        x = (d1 * (b2 * c3 - b3 * c2)
           - b1 * (d2 * c3 - d3 * c2)
           + c1 * (d2 * b3 - d3 * b2)) / det;

        y = (a1 * (d2 * c3 - d3 * c2)
           - d1 * (a2 * c3 - a3 * c2)
           + c1 * (a2 * d3 - a3 * d2)) / det;

        z = (a1 * (b2 * d3 - b3 * d2)
           - b1 * (a2 * d3 - a3 * d2)
           + d1 * (a2 * b3 - a3 * b2)) / det;
    }
};

// Функція для тестування
int main() {
    try {
        // Тестування системи 2 рівнянь з 2 невідомими
        TwoEquations twoEquations;
        double x, y;
        twoEquations.solve(2, 3, 5, 4, -1, 1, x, y);
        //solve() шукає значення x та y, які одночасно задовольняють обидва ці рівняння.
        cout << "Розв'язок системи 2 рівнянь: x = " << x << ", y = " << y << endl;

        // Тестування системи 3 рівнянь з 3 невідомими
        ThreeEquations threeEquations;
        double z;
        threeEquations.solve(1, 2, 3, 4,
                             2, 3, 4, 5,
                             3, 4, 5, 6, x, y, z);
        cout << "Розв'язок системи 3 рівнянь: x = " << x << ", y = " << y << ", z = " << z << endl;
    } catch (const runtime_error& e) {
        cerr << "Помилка: " << e.what() << endl; 
        //e.what() дозволяє отримати текстове повідомлення про виняток, що допомагає в діагностиці та налагодженні програм.
    }

    return 0;
}