#pragma once

#include <iostream>

using namespace std;

template <typename T>

class Cord {
public:
	T x;
	T y;

	Cord(T x_val, T y_val) : x(x_val), y(y_val) {}

	Cord& operator+=(const Cord& other) {
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

};

class Rectengle {
public:
	Cord<float> x0y0 = { 0,0 };
	Cord<float> x1y0 = { 0,0 };
	Cord<float> x0y1 = { 0,0 };
	Cord<float> x1y1 = { 0,0 };

	float side_a = 0;
	float side_b = 0;

	float perimetr = 0;
	float area = 0;

	Rectengle() {}

	Rectengle(Cord<float> x0y0, Cord<float> x1y0, Cord<float> x0y1, Cord<float> x1y1) {
		this->side_a = x1y0.x - x0y0.x;
		this->side_b = x0y1.y - x0y0.y;
		SortCord(x0y0, x1y0, x0y1, x1y1);
		getArea();
		getPerimetr();
	}

	Rectengle(float a, float b, Cord<float> cord = { 0,0 }) : side_a(a), side_b(b), x0y0(cord) {
		this->x1y0 = cord;
		this->x1y0 += {a, 0};

		this->x0y1 = cord;
		this->x0y1 += { 0, b };

		this->x1y1 = cord;
		this->x1y1 += { a, b };
		getArea();
		getPerimetr();
	}

	Rectengle(Rectengle* rec) {
		this->side_a = rec->side_a;
		this->side_b = rec->side_b;
		this->x0y0 = rec->x0y0;
		this->x1y0 = rec->x1y0;
		this->x0y1 = rec->x0y1;
		this->x1y1 = rec->x1y1;
		getArea();
		getPerimetr();
	}

	void getArea() {
		this->area = side_a * side_b;
	}
	void getPerimetr() {
		this->perimetr = (this->side_a + this->side_b) * 2;
	}

	void print() {
		cout << "x0y0: (" << this->x0y0.x << "; " << this->x0y0.y << ")" << endl;
		cout << "x1y0: (" << this->x1y0.x << "; " << this->x1y0.y << ")" << endl;
		cout << "x0y1: (" << this->x0y1.x << "; " << this->x0y1.y << ")" << endl;
		cout << "x1y1: (" << this->x1y1.x << "; " << this->x1y1.y << ")" << endl;

		cout << "Side A: " << this->side_a << endl;
		cout << "Side B: " << this->side_b << endl;
		cout << "Perimeter: " << (this->side_a + this->side_b) * 2 << endl;
		cout << "Area: " << this->side_b * this->side_a << endl;
		cout << "Diagonal: " << sqrt(this->side_b + this->side_a) << endl << endl;
	}

	Rectengle operator+(Rectengle& rec) {
		float Cxmin = min(this->x0y0.x, rec.x0y0.x);
		float Cxmax = max(this->x1y0.x, rec.x1y0.x);
		float Cymin = min(this->x0y0.y, rec.x0y0.y);
		float Cymax = max(this->x0y1.y, rec.x0y1.y);

		Cord<float> zero(Cxmin, Cymin);
		float side_a = Cxmax - Cxmin;
		float side_b = Cymax - Cymin;

		return { side_a, side_b, zero };
	}

	Rectengle operator*(Rectengle& rec) {
		float Cxmin = max(this->x0y0.x, rec.x0y0.x);
		float Cxmax = min(this->x1y0.x, rec.x1y0.x);
		float Cymin = max(this->x0y0.y, rec.x0y0.y);
		float Cymax = min(this->x0y1.y, rec.x0y1.y);

		if (Cxmin < Cxmax and Cymin < Cymax) {
			Cord<float> zero(Cxmin, Cymin);
			float side_a = Cxmax - Cxmin;
			float side_b = Cymax - Cymin;

			return { side_a, side_b, zero };
		}
		else return { 0,0,{0,0} };
	}

private:
	void SortCord(Cord<float> x0y0, Cord<float> x1y0, Cord<float> x0y1, Cord<float> x1y1) {
		float Cxmin = min({ x0y0.x, x1y0.x, x0y1.x, x1y1.x });
		float Cxmax = max({ x0y0.x, x1y0.x, x0y1.x, x1y1.x });
		float Cymin = min({ x0y0.y, x1y0.y, x0y1.y, x1y1.y });
		float Cymax = max({ x0y0.y, x1y0.y, x0y1.y, x1y1.y });

		this->x0y0 = { Cxmin, Cymin };
		this->x1y0 = { Cxmax, Cymin };
		this->x0y1 = { Cxmin, Cymax };
		this->x1y1 = { Cxmax, Cymax };
	}
};

class Parallelepiped :public Rectengle {
public:
	float side_a = 0;
	float side_b = 0;
	float side_c = 0;

	float volume = 0;
	float area = 0;

	Parallelepiped(float a, float b, float c) :side_a(a), side_b(b), side_c(c) {
		getVolume();
		getArea();
	}

	void getVolume() {
		this->volume = side_a * side_b * side_c;
	}
	void getArea() {
		this->area = ((side_a * side_b) + (side_b * side_c) + (side_a * side_c)) * 2;
	}
	void print() {
		cout << "Side A: " << this->side_a << endl;
		cout << "Side B: " << this->side_b << endl;
		cout << "Side B: " << this->side_c << endl;
		cout << "Area: " << this->area << endl;
		cout << "Volume: " << this->volume << endl;
	}
};