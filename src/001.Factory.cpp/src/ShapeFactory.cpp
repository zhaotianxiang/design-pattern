#include<iostream>
#include<string>

using namespace std;

enum TYPE{CIRCLE, SQUARE};

class Shape
{
	public:
		virtual void show()=0;
};

class Circle: public Shape
{
	public:
		void show()
		{
			cout << "Circle" << endl;
		}
};

class Square: public Shape
{
	public:
		void show()
		{
			cout << "Square" << endl;
		}
};

class ShapeFactory
{
	public:
		Shape* getShape(enum TYPE type)
		{
			if(type == CIRCLE)
			{
				return new Circle();
			}
			if(type == SQUARE)
			{
				return new Square();
			}
		}
};
