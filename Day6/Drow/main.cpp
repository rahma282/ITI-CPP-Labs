#include <iostream>
#include <graphics.h>
using namespace std;

class Point
{
private:
    int x, y;
public:
    Point() {
        x=0;
        y=0;
    }
    Point(int x, int y) {
       this->x=x;
       this->y=y;

    }

    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};

class Shape
{
private:
    int color;
protected:
    Shape(int color)
    {
        this->color = color;
    }
public:
    void setColor(int color)
    {
        this->color = color;
    }
    int getColor()
    {
        return this->color;
    }
    virtual ~Shape() {}
    virtual void drow() = 0;  
};

class Line : public Shape
{
private:
    Point start;
    Point end;
public:
    Line() : Shape(0), start(), end() {}
    Line(int x1, int y1, int x2, int y2, int color) : Shape(color), start(x1, y1), end(x2, y2) {}
    
    void drow()
    {
        setcolor(this->getColor());
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

class Rect : public Shape
{
private:
    Point ul;
    Point lr;
public:
    Rect() : Shape(0), ul(), lr() {}
    Rect(int x1, int y1, int x2, int y2, int color) : Shape(color), ul(x1, y1), lr(x2, y2) {}

    void drow()
    {
        setcolor(this->getColor());
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};

class Circle : public Shape
{
private:
    Point center;
    int radius;
public:
    Circle() : Shape(0), center(), radius(0) {}
    Circle(int m, int n, int r, int color) : Shape(color), center(m, n), radius(r) {}
    
    void drow()
    {
        setcolor(this->getColor());
        circle(center.getX(), center.getY(), radius);
    }
};

class Picture
{
private:
    int size;
    int currentIndex;
    Shape** items;

public:
    Picture(int size)
    {
        this->size = size;
        items = new Shape*[size];
        currentIndex = -1;
    }

    void addShape(Shape* s)
    {
        if (currentIndex == size - 1)
        {
            return;
        }
        currentIndex++;
        items[currentIndex] = s;
    }

    void paint()
    {
        for (int i = 0; i <= currentIndex; i++)  
        {
            items[i]->drow();
        }
    }
};

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
    Picture picture(7);
    picture.addShape(new Circle(50, 50, 50,RED));
    picture.addShape(new Circle(200, 100, 100,RED));
    picture.addShape(new Circle(420, 50, 30,RED));
    picture.addShape(new Rect(30, 40, 170, 100,GREEN));
    picture.addShape(new Rect(420, 50, 500, 300,GREEN));
    picture.addShape(new Line(420, 50, 300, 300,BLUE));
    picture.addShape(new Line(40, 500, 500, 400,BLUE));

    picture.paint();

    getch();
    return 0;

}
