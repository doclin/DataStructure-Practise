#include <iostream>
#include "../linear_lists/sequential_list/sequential_list.h"
#include "../stack/stack.h"

using namespace std;

bool is_valid(SequentialList<bool> sequence, int goal_num)   // 判断当前解序列是否正确
{
	int push_num = 0;                                        // 记录净压入次数
	int total_push_num = 0;                                  // 记录总压入次数
	for(int i=0; i<sequence.length(); i++)
	{
		if(sequence[i] == 1)                                 // 1为压入
		{
			push_num++;
			total_push_num++;
		}
		if(sequence[i] == 0)
			push_num--;
		if(push_num < 0 or total_push_num > goal_num)        // 如果出栈多于入栈或压入次数大于元素个数
			return false;
	}
	return true;
}

/*
回溯法获得解序列：
sequence: 当前部分解序列，包含递归规模变化
goal_num: 总元素个数，不变
result: 为避免使用全局变量，用于存储有效解的栈
最终获得的解序列是长度为goal_num两倍的bool序列，1表示压入，0表示弹出，每个解序列对应唯一的输出结果
*/
void get_result_sequence(SequentialList<bool> sequence, int goal_num, Stack< SequentialList<bool> >& result)
{
	if(sequence.length() == goal_num*2)                      // 两倍长度
	{
		result.push(sequence);
		return;
	}
	else
	{
		sequence.append(1);
		if(is_valid(sequence, goal_num))                     // 进入下一层
			get_result_sequence(sequence, goal_num, result);
		sequence.remove(sequence.length()-1);
		sequence.append(0);
		if(is_valid(sequence, goal_num))
			get_result_sequence(sequence, goal_num, result);
	}
}

void show_result(Stack< SequentialList<bool> > result, int* array)               // 将获得的解集打印出来
{
	SequentialList<bool> sequence;                                               // 两个tempt容器
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