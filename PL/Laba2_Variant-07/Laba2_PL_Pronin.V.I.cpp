#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>

#include "./MyString.h"
#include "./Employer.h"

using namespace std;

void main()
{
    cout << "File EMPLOYER:" << endl;
    // File EMPLOYER
    const char* name1 = "Happy Jamsa";
    employee worker(name1, 101, 10101.0);
    worker.show_employee();

    const char* name2 = "Jane Doe";
    employee manager(name2, 102);
    manager.show_employee();


    cout << endl << "File MySTRING:" << endl;
    // File MySTRING
    MyString* str = new MyString();
    str->update();
    str->print();
    delete str;
}