#ifndef HEADER

#include <iostream>
using namespace std;


class shape {
protected:
    int length;
    int breadth;
    int height;
public:
    shape();
};
class Painting {
    int cost;
public:

    Painting(int);

    void getcost(int);


};
class Square :public shape, public Painting {
public:
    int getarea();
    Square();
    

};
class Rectangle :public shape, public Painting {
public:
    int getarea();

    Rectangle();
};
class Triangle :public Painting, public shape {
public:
    int getarea();

    Triangle();

};

#endif