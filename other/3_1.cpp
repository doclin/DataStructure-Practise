#include <iostream>
#include "../linear_lists/sequential_list/sequential_list.h"
#include "../stack/stack.h"

using namespace std;

bool is_valid(SequentialList<bool> sequence, int goal_num)   //
{
	int push_num = 0;       //1
	int total_push_num = 0;
	for(int i=0; i<sequence.length(); i++)
	{
		if(sequence[i] == 1)   //
		{
			push_num++;
			total_push_num++;
		}
		if(sequence[i] == 0)
			push_num--;
		if(push_num < 0 or total_push_num > goal_num)
			return false;
	}
	return true;
}

void get_result_sequence(SequentialList<bool> sequence, int goal_num, Stack< SequentialList<bool> >& result)                //
{
	if(sequence.length() == goal_num*2)        //
	{
		result.push(sequence);
		return;
	}
	else
	{
		sequence.append(1);
		if(is_valid(sequence, goal_num))
			get_result_sequence(sequence, goal_num, result);
		sequence.remove(sequence.length()-1);
		sequence.append(0);
		if(is_valid(sequence, goal_num))
			get_result_sequence(sequence, goal_num, result);
	}
}

void show_result(Stack< SequentialList<bool> > result, int* array)
{
	SequentialList<bool> sequence;                          //
	Stack<int> stack;
	while(!result.is_empty())
	{
		int index = 0;
		sequence = result.pop();
		for(int i=0; i<sequence.length(); i++)
		{
			if(sequence[i] == 1)
			{
				stack.push(array[index]);
				index++;
			}
			if(sequence[i] == 0)
			{
				cout << stack.pop();
			}
		}
		cout << endl;
	}
}

int main()
{
	SequentialList<bool> sequence;
	Stack< SequentialList<bool> > result;
	get_result_sequence(sequence, 4, result);
	int array[4] {1, 2, 3, 4};
	/*
	while(!result.is_empty())
	{
		sequence = result.pop();
		for(int i=0; i<sequence.length(); i++)
			cout << sequence[i];
		cout << endl;
	}
	*/
	show_result(result, array);

	return 0;
}


/*
output:
1234
1243
1324
1342
1432
2134
2143
2314
2341
2431
3214
3241
3421
4321
*/