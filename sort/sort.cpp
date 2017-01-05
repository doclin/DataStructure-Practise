namespace Sort
{
/*
Insertion sort is a kind of simple sort.
*/ 
void insertion_sort(int* array, int len)
{
	for(int index=0; index<len; index++)
	{
		for(int i=0; i<index; i++)
		{
			if(array[index]<array[i])
			{
				int tmp = array[index];
				for(int j=index; j>i; j--)
					array[j] = array[j-1];
				array[i] = tmp;
				break;
			}
		}
	}
}








}

