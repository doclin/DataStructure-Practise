#include <iostream>
using namespace std;

class Box
{
private:
	int weight;
public:
	Box(int w=0);
	~Box();
};

Box::Box(int w)
{
	weight = w;
	cout << "the weight is " << weight << endl;
}

Box::~Box()
{
	cout << "goodbye " << weight << endl;
}

//global
Box a(12);
Box b = Box();

int main()
{
	Box c = Box(1);
	Box * d = new Box(3);
	delete d;

	return 0;
}


/*
output:
the weight is 12
the weight is 0
the weight is 1
the weight is 3
goodbye 3
goodbye 1
goodbye 0
goodbye 12

answer:
The global objects will be created as soon as the program starts to run and they will stay in memory until 
the program ends. The local object in stack will be created and delete with the process of the function.
The dynamic local object stored in heap will be created when I new it and deleted when I delete it.
*/