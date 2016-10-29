#include <iostream>

using namespace std;
void sort(int *, int *, int *);

int main()
{
	int i = 19;
	int j = 16;
	int k = 8;
	sort(&i, &j, &k);
	cout << i << "," << j << "," << k << endl;

	return 0;
}

void sort(int *a, int *b, int *c)
{
	if(*a >= *c)
	{
		int ta = *a;
		*a = *c;
		*c = ta;
	}
	if(*b >= *c)
	{
		int tc = *c;
		*c = *b;
		*b = tc;
	}
	if(*a >= *b)
	{
		int tb = *b;
		*b = *a;
		*a = tb;
	}

}