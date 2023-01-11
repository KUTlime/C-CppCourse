#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

class GraphicalDrawingBoard
{};

class DrawableObject
{
public:
    virtual void Clear(GraphicalDrawingBoard&) const { std::cout << "DrawableObject::Clear()" << std::endl; };
    virtual void Draw(GraphicalDrawingBoard&) const = 0; //draw to GraphicalDrawingBoard
    void Test() { std::cout << "DrawableObject::Test()" << std::endl; };
};

class Triangle : public DrawableObject
{
public:
    void Draw(GraphicalDrawingBoard&) const; //draw a triangle
};

class Rectangle : public DrawableObject
{
public:
    void Draw(GraphicalDrawingBoard&) const; //draw a rectangle
};

class Circle : public DrawableObject
{
public:
    void Draw(GraphicalDrawingBoard&) const; //draw a circle
    void Clear(GraphicalDrawingBoard&) const override { std::cout << "Circle::Clear()" << std::endl; };
    void Test() /*override will not compile */ { std::cout << "Circle::Test()" << std::endl; };
};

struct Base
{
    virtual int foo() const {};
};

struct Derived : Base
{
    virtual int foo() const override  // whoops!​
    {
        // ... Where is my const?​
    }
};

int main()
{
    std::cout << "Hello World!\n";

    std::vector<DrawableObject*> drawableList;
    GraphicalDrawingBoard drawingBoard;

    //drawableList.push_back(new DrawableObject());
    drawableList.push_back(new Triangle());
    drawableList.push_back(new Rectangle());
    drawableList.push_back(new Circle());

    std::for_each(drawableList.begin(), drawableList.end(), [&drawingBoard](DrawableObject* object)
    { 
        object->Draw(drawingBoard);
        object->Clear(drawingBoard);
        object->Test();
    });

    Triangle t;
    Rectangle r;
    Circle c;
    /*std::vector<DrawableObject> drawableList2 = { t, r, c };
    
    std::for_each(drawableList2.begin(), drawableList2.end(), [&drawingBoard](DrawableObject & object)
    {
        object.Draw(drawingBoard);
        object.Clear(drawingBoard);
        object.Test();
    });
    */
}

void Triangle::Draw(GraphicalDrawingBoard&) const
{
    std::cout << "Draw Triangle" << std::endl;
}

void Rectangle::Draw(GraphicalDrawingBoard&) const
{
    std::cout << "Draw Rectangle" << std::endl;
}

void Circle::Draw(GraphicalDrawingBoard&) const
{
    std::cout << "Draw Circle" << std::endl;
}
