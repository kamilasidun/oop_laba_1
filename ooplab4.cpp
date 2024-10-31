#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class TTriangle {
public:
    virtual double area() const = 0; // Віртуальний метод для обчислення площі
    virtual double perimeter() const = 0; // Віртуальний метод для обчислення периметру
    virtual ~TTriangle() {} // Віртуальний деструктор
};

class EquilateralTriangle : public TTriangle {
private:
    double side; // Сторона рівностороннього трикутника
public:
    EquilateralTriangle(double s) : side(s) {}
    
    double area() const override {
        return (sqrt(3) / 4) * side * side; // Формула площі рівностороннього трикутника
    }

    double perimeter() const override {
        return 3 * side; // Периметр
    }
};

class RightTriangle : public TTriangle {
private:
    double base; // Основа прямокутного трикутника
    double height; // Висота прямокутного трикутника
public:
    RightTriangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height; // Формула площі прямокутного трикутника
    }

    double perimeter() const override {
        double hypotenuse = sqrt(base * base + height * height); // Знайдемо гіпотенузу
        return base + height + hypotenuse; // Периметр
    }
};

class IsoscelesTriangle : public TTriangle {
private:
    double base; // Основа рівнобедреного трикутника
    double side; // Сторона рівнобедреного трикутника
public:
    IsoscelesTriangle(double b, double s) : base(b), side(s) {}

    double area() const override {
        double height = sqrt(side * side - (base * base) / 4); // Знайдемо висоту
        return 0.5 * base * height; // Площа
    }

    double perimeter() const override {
        return 2 * side + base; // Периметр
    }
};

int main() {
    const int n = 10; // Кількість трикутників
    TTriangle* triangles[n]; // Масив вказівників на TTriangle

    srand(time(0)); // Ініціалізуємо генератор випадкових чисел

    // Створення випадкових трикутників
    for (int i = 0; i < n; ++i) {
        int type = rand() % 3; // Вибір одного з трьох типів трикутників, за допомогою залишку від ділення на 3
        if (type == 0) {
            double side = rand() % 10 + 1; // Випадкова сторона
            //rand() % 10 + 1 змінює діапазон значень, що генеруються, з [0, 9] на [1, 10], так як сторона не може дорівнювати 0.
            triangles[i] = new EquilateralTriangle(side);
            //створення нового об'єкта типу EquilateralTriangle, який є похідним класом від базового класу TTriangle.
        } else if (type == 1) {
            double base = rand() % 10 + 1; // Випадкова основа
            double height = rand() % 10 + 1; // Випадкова висота
            triangles[i] = new RightTriangle(base, height);
        } else {
            double base = rand() % 10 + 1; // Випадкова основа
            double side = rand() % 10 + 1; // Випадкова сторона
            triangles[i] = new IsoscelesTriangle(base, side);
        }
    }

    double totalAreaEquilateral = 0.0;
    double totalAreaRight = 0.0;
    double totalPerimeterIsosceles = 0.0;

    // Обчислення сум
    for (int i = 0; i < n; ++i) {
        //цикл проходить через масив triangles, що містить вказівники на об'єкти трикутників, n - це загальна кількість трикутників.
        if (dynamic_cast<EquilateralTriangle*>(triangles[i])) {
        //dynamic_cast дозволяє безпечно перевірити, чи вказівник triangles[i] насправді вказує на об'єкт типу EquilateralTriangle.
        //Якщо приведення успішне, то triangles[i] є вказівником на EquilateralTriangle, і ми можемо викликати метод area() для підрахунку площі.
            totalAreaEquilateral += triangles[i]->area(); //вираз використовує поліморфізм для виклику відповідного методу площі залежно від типу об'єкта
            //-> - для доступу до методу area() класу, на який вказує triangles[i]
        } else if (dynamic_cast<RightTriangle*>(triangles[i])) {
            totalAreaRight += triangles[i]->area();
        } else if (dynamic_cast<IsoscelesTriangle*>(triangles[i])) {
            totalPerimeterIsosceles += triangles[i]->perimeter();
        }
    }

    // Виведення результатів
    cout << "Sum of areas of equilateral triangles: " << totalAreaEquilateral << endl;
    cout << "Sum of areas of right triangles: " << totalAreaRight << endl;
    cout << "Sum of perimeters of isosceles triangles: " << totalPerimeterIsosceles << endl;

    // Очищення пам'яті
    for (int i = 0; i < n; ++i) {
        delete triangles[i];
    }

    return 0;
}