#pragma once

#include <iostream>

using namespace std;

class Worker
{
public:
    int age;
    const char* name;
    int happy = 10;

    Worker() {
        char* n = new char();
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Name: ";
        cin >> n;
        name = n;
    }

    void workerPrint() {
        cout << "Name: " << name << ". Years Old: " << age << endl;
    }

    void walk() {
        happy++;
    }
    void dance() {
        happy += 2;
    }
    void work() {
        happy -= 2;
    }

    void getHappy() {
        cout << "Happy level: " << happy << endl;
    }

    void eat(float how_much);
    float get_weight();

private:
    float weight;
};

void Worker::eat(float how_much)
{
    if (how_much > 10) {
        weight += (how_much / 2);
        age++;
    }
    else weight += how_much;
}
float Worker::get_weight()
{
    return weight;
}