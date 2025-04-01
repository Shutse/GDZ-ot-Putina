#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>

#include "./Worker.h"
#include "./Triangle.h"

using namespace std;

void main()
{
    cout << "File WORKER:" << endl;
    // File WORKER

    Worker* wrk1 = new Worker();

    wrk1->workerPrint();
    wrk1->age = 34;
    wrk1->name = "Иванов";

    wrk1->eat(2);
    wrk1->eat(3);

    float ves;
    ves = wrk1->get_weight();
    cout << "Worker's weight: +" << ves << endl << endl;

    //---------------------------------------

    cout << "File TRIANGLE:" << endl;
    // File TRIANGLE

    Triangle* tri = new Triangle();
    tri->printAll();
}