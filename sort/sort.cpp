#include <vector>
#include <list>
#include <iostream>

void selectSort(std::vector<int>& input);
void insertSort(std::vector<int>& input);
void bubbleSort(std::vector<int>& input);
void quickSort(std::vector<int>& input);
void quickSort(std::vector<int>& input, int begin, int end);
void mergeSort(std::vector<int>& input);
void merge(std::vector<int>& input, int begin, int size);
void heapSort(std::vector<int>& input);
void adjustDown(std::vector<int>& input, int index, int length);

void print(const std::vector<int>& input);

int main()
{
    int array[] = {12, 1 ,3, 9, 29, 54, 23, 67, 23, 14, 2, 9, 10, 90, 65, 76, 80, 55, 40, 38, 99, 11};
    //int array[] = {12, 1, 3, 9, 29};
    std::vector<int> v(array, array + sizeof(array) / sizeof(int));

    //selectSort(v);
    //insertSort(v);
    //bubbleSort(v);
    //quickSort(v);
    //mergeSort(v);
    heapSort(v);

    print(v);


    return 0;
}

void print(const std::vector<int>& input)
{
    for(int i = 0; i < input.size(); i++)
    {
        std::cout << input[i] << ",";
    }
    std::cout << std::endl;
}

void selectSort(std::vector<int>& input)
{
    for(int i = 0; i < input.size(); i++)
    {
        int tmp = input[i];
        int index = i;
        for(int j = i; j < input.size(); j++)
        {
            if(input[j] < tmp)
            {
                tmp = input[j];
                index = j;
            }
        }
        input[index] = input[i];
        input[i] = tmp;
    }
}

void insertSort(std::vector<int>& input)
{
    for(int i = 0; i < input.size(); i++)
    {
        int tmp = input[i];
        int j;
        for(j = i - 1; j >= 0; j--)
        {
            if(tmp < input[j])
                input[j+1] = input[j];
            else
                break;
        }
        input[j+1] = tmp;
    }
}

void bubbleSort(std::vector<int>& input)
{
    for(int i = 0; i < input.size(); i++)
    {
        for(int j = 0; j < input.size() - 1; j++)
        {
            if(input[j] > input[j+1])
            {
                int tmp = input[j];
                input[j] = input[j+1];
                input[j+1] = tmp;
            }
            else
                continue;
        }
    }
}

void quickSort(std::vector<int>& input)
{
    quickSort(input, 0, input.size() - 1);
}

void quickSort(std::vector<int>& input, int begin, int end)
{
    if(end - begin <= 0)
        return;
    int i = begin;
    int j = end;
    int target = input[begin];
    while(i < j)
    {
        while(input[i] <= target && i < end)
            i++;
        while(input[j] > target && begin < j)
            j--;
        if(i < j)
            std::swap(input[i], input[j]);
    }
    std::swap(input[j], input[begin]);
    quickSort(input, begin, j - 1);
    quickSort(input, j + 1, end);
}

void mergeSort(std::vector<int>& input)
{
    int begin = 0;
    int size = 1;
    while(size < input.size())
    {
        while(begin < input.size())
        {
            merge(input, begin, size);
            begin += size * 2;
        }
        size *= 2;
        begin = 0;
    }
}

void merge(std::vector<int>& input, int begin, int size)
{
    if(begin + size >= input.size())
        return;
    int end = begin + size * 2 > input.size() ? input.size() : begin + size * 2;
    std::vector<int> tmp(end - begin);
    int i = begin;
    int j = begin + size;
    int i1 = j;
    int j1 = end;
    int k = 0;
    while(i < j && i1 < j1)
        tmp[k++] = input[i] < input[i1] ? input[i++] : input[i1++];
    while(i < j)
        tmp[k++] = input[i++];
    while(i1 < j1)
        tmp[k++] = input[i1++];
    for(int m = 0; m < tmp.size(); m++)
        input[m + begin] = tmp[m];
}

void heapSort(std::vector<int>& input)
{
    for(int mid = input.size() / 2; mid >= 0; mid--)
        adjustDown(input, mid, input.size());
    for(int end = input.size() - 1; end >= 0; end--)
    {
        std::swap(input[0], input[end]);
        adjustDown(input, 0, end);
    }
}

void adjustDown(std::vector<int>& input, int index, int length)
{
    if(length <= 1)
        return;
    int lchild = index * 2 + 1;
    int rchild = index * 2 + 2;
    while(lchild < length)
    {
        int maxchild;
        if(rchild < length)
            maxchild = input[lchild] > input[rchild] ? lchild : rchild;
        else
            maxchild = lchild;
        if(input[maxchild] > input[index])
        {
            std::swap(input[maxchild], input[index]);
            index = maxchild;
            lchild = index * 2 + 1;
            rchild = index * 2 + 2;
        }
        else
            break;
    }
}