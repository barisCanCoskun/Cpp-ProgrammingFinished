#include<iostream>
#include<vector>

using namespace std;

class Shape{              // Abstract Base class
private:
    // Attributes common to all shapes
public:
    virtual void draw() = 0;    // pure virtual func
    virtual void rotate() = 0;    // pure virtual func
    virtual ~Shape() {}
};

class Open_Shape: public Shape {    // Abstract class
public:

    virtual ~Open_Shape() {}
};

class Closed_Shape: public Shape {    // Abstract class
public:
    
    virtual ~Closed_Shape() {}
};

class Line: public Open_Shape {    // Concrete class
public:
    virtual void draw() override{
        cout << "Drawing a line" << endl;
    }

    virtual void rotate() override{
        cout << "Rotating a line" << endl;
    }
    
    virtual ~Line() {}
};

class Circle: public Closed_Shape {    // Concrete class
public:
    virtual void draw() override{
        cout << "Drawing a circle" << endl;
    }

    virtual void rotate() override{
        cout << "Rotating a circle" << endl;
    }
    
    virtual ~Circle() {}
};

class Square: public Closed_Shape {    // Concrete class
public:
    virtual void draw() override{
        cout << "Drawing a square" << endl;
    }

    virtual void rotate() override{
        cout << "Rotating a square" << endl;
    }
    
    virtual ~Square() {}
};

void screen_refresh(const vector<Shape*> &shapes)
{
    cout << "Refreshing." << endl;
    for(const auto p: shapes){
        p->draw();
        p->rotate();
    }
}

int main()
{
    Shape *s = new Circle();
    
    Circle c;
    c.draw();

    s->rotate();
    s->draw();

    Shape *s1 = new Line();
    Shape *s2 = new Circle();
    Shape *s3 = new Square();

    vector<Shape *> shapes{s1, s2, s3};

    for(const auto sha: shapes){
        sha->draw();
        sha->rotate();
    }

    screen_refresh(shapes);

    delete s1;
    delete s2;
    delete s3;
    
    delete s;    

    return 0;   
}








