#include<iostream>
#include"Adapter.h"
#include"Adaptee.h"

using namespace std;

int main(int argc, char * argv[])
{
	Adaptee * adaptee = new Adaptee();
	Target * tar = new Adapter(adaptee);
	tar.request();

	return 0;
}
