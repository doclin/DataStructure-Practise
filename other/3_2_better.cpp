#include "../linear_lists/sequential_list/sequential_list.h"
#include "../stack/stack.h"
#include <iostream>

using namespace std;


void get_result_sequence(SequentialList<int> sequence, int n, Stack< SequentialList<int> >& result)
{
	if(n == 0)
	{
		result.push(sequence);
		return;
	}
	else
	{
		for(int i=0; i<sequence.length()-n-1; i++)
		{
			if(sequence[i]==0 and sequence[i+n+1]==0)
			{
				sequence[i] = sequence[i+n+1] = n;
				/*
				for(int h=0; h<sequence.length(); h++)
					cout << sequence[h];
				cout << endl;
				*/
				get_result_sequence(sequence, n-1, result);
				sequence[i] = sequence[i+n+1] = 0;
			}
		}
	}
}

void show_result(Stack< SequentialList<int> > result)      // 输出解集
{
	SequentialList<int> sequence;
	while(!result.is_empty())
	{
		sequence = result.pop();
		for(int i=0; i<sequence.length(); i++)
		{
			cout<< sequence[i];
		}
		cout << endl;
	}
}

int main()
{
	int try1 = 3;
	int try2 = 7;
	int try3 = 9;
	SequentialList<int> sequence(try2*2);
	for(int i=0; i<try2*2; i++)
		sequence.append(0);
	Stack< SequentialList<int> > result;
	get_result_sequence(sequence, try2, result);
	show_result(result);


	return 0;
}