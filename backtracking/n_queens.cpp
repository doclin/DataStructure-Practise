#include "../linear_lists/sequential_list/sequential_list.h"
#include "../stack/stack.h"
#include <iostream>

using namespace std;

/*
用一维序列表示棋盘，判断新加入的最后一个元素是否合法
*/
bool is_valid(SequentialList<int> sequence)
{
	int last_row = sequence.length() - 1;
	int last_col = sequence[last_row];             // 获取最后一行的位置
	for(int i=0; i<sequence.length()-1; i++)
	{
		if(sequence[i] == last_col)                // 判断是否同列
			return false;
		if(sequence[i]-last_col == last_row-i)     // 判断是否同斜线
			return false;
		if(sequence[i]-last_col == i-last_row)
			return false;
	}
	return true;
}

void get_result_sequence(SequentialList<int> sequence, int n, Stack< SequentialList<int> >& result)
{
	if(sequence.length() == n)
	{
		result.push(sequence);
		return;
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			sequence.append(i);
			if(is_valid(sequence))
				get_result_sequence(sequence, n, result);
			sequence.remove(sequence.length() - 1);
		}
	}
}

void show_result(Stack< SequentialList<int> > result)
{
	SequentialList<int> sequence;
	while(!result.is_empty())
	{
		sequence = result.pop();
		for(int i=0; i<sequence.length(); i++)
			cout << sequence[i];
		cout << endl;
	}
}

int main()
{
	int n = 10;
	SequentialList<int> sequence(n);
	Stack< SequentialList<int> > result;
	get_result_sequence(sequence, n, result);
	show_result(result);

	return 0;
}
