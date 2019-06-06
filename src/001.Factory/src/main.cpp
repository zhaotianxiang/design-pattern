#include<iostream>
#include"ShapeFactory.cpp"
using namespace std;

int main()
{
	ShapeFactory sf;
	Shape* shape = sf.getShape(CIRCLE);
	shape->show();

    return 0;
}
