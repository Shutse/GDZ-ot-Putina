#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>

#include "./Rectangle.h"

using namespace std;

void main()
{
    Rectangle rec1(5, 8, { 3,1 });
    rec1.print();

    Rectangle rec2(5, 8, { 1,1 });
    rec2.print();

    Rectangle rec3(rec2 + rec1);
    rec3.print();

    Rectangle rec4(rec2 * rec1);
    rec4.print();
}