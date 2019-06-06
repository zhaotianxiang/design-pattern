#include<iostream>
using namespace std;

/** people builder **/
class Builder
{
	public:
		virtual void buildHead();
		virtual void buildBody();
};

class ThinBuilder: public Builder
{
	public:
		void buildHead(){cout << "thin head"<<endl;}
		void buildBody(){cout << "thin body"<<endl;}
};

class FatBuilder: public Builder
{
	public:
		void buildHead(){cout << "fat head"<<endl;}
		void buildBody(){cout << "fat body"<<endl;}
};

/** 指挥建造者的类 **/
class Director
{
	private:
	    Builder *mBuilder;
	public:
		Director(Builder *builder){mBuilder = builder;}
		void create()
		{
			mBuilder->buildHead();
			mBuilder->buildBody();
		}
};

int main()
{
	FatBuilder *fat = new FatBuilder();
	Director director(fat);
	director.create();
	return 0;
}
