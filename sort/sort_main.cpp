#include <iostream>
//#include "sort.h"

using namespace std;
const int LENGTH = 9;

void display(int* array, int len)
{
	for(int i=0; i<len; i++)
		cout << array[i] << endl;
}

int main()
{
	int a1[LENGTH] = {11, 3, 5, 2, 4, 9, 6, 8, 7};
	Sort::insertion_sort(a1, LENGTH);
	display(a1, LENGTH);


}