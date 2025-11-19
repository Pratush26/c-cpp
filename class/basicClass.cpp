#include <bits/stdc++.h>
using namespace std;

//  without constructor
class Student {
    public:
    char name[20];
    int roll;
    float gpa;
};

//  with constructor
class Bike {
    public:
    char name[20];
    char color[20];
    int cc;
    Bike(const char* n, const char* c, int p) {
        strcpy(name, n);    //  string can't declare directly after intial declaration
        strcpy(color, c);   //  so, new string declare here to copy it's value
        cc = p;
    }
};

class Car {
    public:
    char name[20];
    char color[20];
    int cc;
    Car(const char* name, const char* color, int cc) {
        strcpy(this->name, name);
        strcpy((*this).color, color);
        this->cc = cc;  //  using this pointer
    }
};

int main() {
    //  without constructor
    Student a, b;
    cin >> a.name >> a.roll >> a.gpa;
    cin >> b.name >> b.roll >> b.gpa;
    cout << a.name << " " << a.roll << " " << a.gpa << "\n";
    cout << b.name << " " << b.roll << " " << b.gpa << "\n";
    //
        // test inputs ->
        // Rakib 34 4.5
        // Sakib 23 3.5

    //  with constructor
    Bike ab("Suzuki", "blue", 150);
    cout << ab.name << " " << ab.color << " " << ab.cc << "\n";
    Car bb("Ford", "red", 550);
    cout << bb.name << " " << bb.color << " " << bb.cc << "\n";

    return 0;
}