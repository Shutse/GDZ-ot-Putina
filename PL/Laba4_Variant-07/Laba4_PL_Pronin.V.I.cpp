#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>

#include "./Rectangle.h"

using namespace std;

void main()
{
    vector<Rectengle> MassiveR;
    vector<Parallelepiped> MassiveP;

    srand(time(NULL));

    for (size_t i = 0; i < 1000; i++)
    {
        MassiveR.push_back({ float(rand() % 20),float(rand() % 20),{float(rand() % 20), float(rand() % 20)}});
        MassiveP.push_back({ float(rand() % 20),float(rand() % 20),float(rand() % 20)});

    }

    float sumArea = 0;
    int countP = 0;

    for (size_t i = 0; i < MassiveR.size(); i++)
    {
        sumArea += MassiveR[i].area / MassiveR.size();
        if (MassiveP[i].side_a == MassiveP[i].side_b && MassiveP[i].side_b == MassiveP[i].side_c) countP++;
    }
    cout << "The average area of 1000 rectangles: " << sumArea << endl;


    float count = 0;
    for (size_t i = 0; i < MassiveR.size(); i++)
    {
        if (MassiveR[i].area > sumArea) count++;
        //cout << MassiveR[i].area << "\t" << count << endl;
    }

    cout << "The number of similar Rectangles: " << count << endl;
    cout << "The number of similar Parallelograms: " << countP << endl;
}