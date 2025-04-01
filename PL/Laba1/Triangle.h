#pragma once

#include <iostream>

using namespace std;

class Triangle {
public:
    float h;
    float a;
    float c;
    float angleA;
    float angleC;
    float space;
    float perem;
    float pperem;
    float mediana;

    Triangle() {
        cout << "Enter the heigth of the triangle: ";
        cin >> h;
        cout << "Enter the side 'A' of the triangle: ";
        cin >> a;
        if (h < a && h != 0 && a != 0) {
            getAngle();
            getSpace();
            getPeren();
            getMedian();
        }
        else {
            cout << "error data: " << endl;
        }

    }

    void stScale(float per) {
        this->h *= per;
        this->a *= per;
        this->c *= per;
        this->perem *= per;
        this->space *= per;
    }
    void printAll() {
        cout << "Base: " << this->c << endl;
        cout << "Ribs: " << this->a << endl;
        cout << "Space: " << this->space << endl;
        cout << "Perimeter: " << this->perem << endl;
        cout << "Angles at the base: " << this->angleA / 3.14 * 180 << endl;
        cout << "Corners at the top: " << this->angleC / 3.14 * 180 << endl;
        cout << "Medians to ribs: " << this->mediana << endl;
    }

private:
    void getAngle() {
        this->angleA = asin(this->h / this->a);
        this->angleC = 3.14 - (this->angleA * 2);
    }
    void getSpace() {
        this->c = 2 * this->a * cos(this->angleA);
        this->space = 0.5 * this->h * this->c;
    }
    void getPeren() {
        this->perem = this->c + (2 * this->a);
        this->pperem = 0.5 * this->perem;
    }
    void getMedian() {
        this->mediana = this->perem - ((this->space * this->space) / (this->pperem * (this->pperem - this->a) * (this->pperem - this->a / 2) * (this->pperem - this->c)));
    }
};
