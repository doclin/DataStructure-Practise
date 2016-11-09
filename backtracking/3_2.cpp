#include "../linear_lists/sequential_list/sequential_list.h"
#include "../stack/stack.h"
#include <iostream>

using namespace std;

bool is_valid(SequentialList<int> sequence)                           // 判断当前序列是否合法
{
	for(int i=0; i<sequence.length(); i++)
	{
		int count = 0;
		for(int j=i+1; j<sequence.length(); j++)
		{
			if(sequence[i]==sequence[j] and count!=sequence[i])
				return false;
			count++;
		}
	}
	return true;
}

void get_result_sequence(SequentialList<int> sequence, int n, Stack< SequentialList<int> >& result) // 获得解集
{
	if(sequence.length() == n*2)
	{
		result.push(sequence);
		return;
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			sequence.append(i);
			if(is_valid(sequence))
			{
				/*
				for(int h=0; h<sequence.length(); h++)
					cout << sequence[h];
				cout << endl;
				*/
				get_result_sequence(sequence, n, result);
			}
			sequence.remove(sequence.length()-1);
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
	SequentialList<int> sequence;
	Stack< SequentialList<int> > result;
	get_result_sequence(sequence, try2, result);
	show_result(result);


	return 0;
}

/*

when n=7:
74151643752362
73625324765141
73161345726425
72632453764151
72462354736151
72452634753161
71416354732652
71316435724625
62742356437151
61517346532472
57416154372632
57263254376141
57236253471614
57141653472362
56171354632742
53672352461714
53647352462171
52732653417164
52642753461317
52472654131763
52462754316137
51716254237643
46357432652171
46171452632753
46171435623725
45671415362732
41716425327635
41617435263275
37463254276151
36713145627425
35743625427161
35723625417164
34673245261715
34573641512762
27423564371516
26721514637543
26327435614175
26325734615147
25623745361417
24723645317165
23726351417654
23627345161475
17126425374635
17125623475364
16172452634753
16135743625427
15173465324726
15167245236473
15163745326427
15146735423627
14167345236275
14156742352637


*/
