#pragma once

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class MyString {
public:
	MyString() {
		set();
	}
	void set() {
		cout << "Write string: ";
		cin >> this->stroka;
		this->len = this->stroka.length();
	}
	~MyString(void) {
		cout << "String: " << this->stroka << " - is deleted" << endl;
	}

	void update() {
		if (len >= 10) {
			stroka.erase(std::remove_if(stroka.begin(), stroka.end(),
				[this](char c) { return my_predicate(c); }),
				stroka.end());
			len = stroka.length();
			cout << "From String been deleted all A..Z: " << endl;
		}
	}

	void print() {
		cout << "String is: " << this->stroka << endl;
	}
private:
	string stroka = "";
	int len = 0;

	bool my_predicate(char c) {
		return (c >= 'A' && c <= 'Z');
	}
};