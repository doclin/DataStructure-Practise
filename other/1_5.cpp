#include <iostream>
using namespace std;

const int N = 8; // total num of people
const int R = 2; // interval

int func_of_joseph(int , int); // executed by recursion to get the winner without array
void test_of_joseph(int[], int, int); // executed in array by loop

int main()
{
	int * p = new int [N]();
	test_of_joseph(p, R, N);
	int result = func_of_joseph(N, R);
	cout << "the func last one is " << result << "th" << endl;

	return 0;
}


int func_of_joseph(int num, int r) // O(n)
{
	if(num == 1)
		return 0;

	return (func_of_joseph(num-1, r) + r) % num; 
}

void test_of_joseph(int array[], int r, int len) // O(nm)?
{
	int exit_total_num = 0; // num of people having exited
	int index_now = 0; 
	while(exit_total_num < N)
	{
		int counter = 0; // counter for interval
		while(counter < r)
		{
			if(array[index_now % len] == -1)
			{
				index_now++; // jump
			}
			else
			{
				index_now++;
				counter++;
			}
		}
		cout << ((index_now-1) % len) << endl;
		array[(index_now-1) % len] = -1; // mark by the value
		exit_total_num++;
	}
	cout << "the test last one is " << ((index_now-1) % len) << "th" << endl;
}

/*
output:
1
3
5
7
2
6
4
0
the test last one is 0th
the func last one is 0th
*/