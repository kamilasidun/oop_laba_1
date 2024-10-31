#include <iostream>
using namespace std;

class Number {
private:
    int number;

public:
    Number() : number(0) {}

    void setNum() {
        cout << "Enter natural number: ";
        cin >> number;

        while (number <= 0) {
            cout << "It has to be natural. Enter one more time: ";
            cin >> number;
        }
    }

    void getNum() const {
        cout << "Number: " << number << endl;
    }

    int countDigits() const {
        int count = 0;
        int i = number;

        do {
            i /= 10;
            count++;
        } while (i > 0);

        return count;
    }

    int sumDigits() const {
        int sum = 0;
        int i = number;

        while (i > 0) {
            sum += i % 10;
            i /= 10;
        }

        return sum;
    }
};

int main() {
    Number num;

    num.setNum();
    num.getNum();
    cout << "Amount of numbers: " << num.countDigits() << endl;
    cout << "Sum of numbers: " << num.sumDigits() << endl;

    return 0;
}