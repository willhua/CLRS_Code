#include "CommonInclude.h"


#if 1

using namespace std;


#define PARENT(i) ((i) / 2)
#define LEFT(i) (2*(i))
#define RIGHT(i) (2*(i) + 1)


/*
first: find the max of parent and the left and right son node
second: if the parent, the index, is not the max, so, swap parent with the max position,
and do recursion for max position*/
void max_heap(int *array, const int size, int index)
{
    int max = index,  left = LEFT(index), right = RIGHT(index);
    if (left < size && array[index] < array[left])
    {
        max = left;
    }
    if (right < size && array[max] < array[right])
    {
        max = right;
    }

    if (max != index)
    {
        swap(array + max, array + index);
        max_heap(array, size, max);
    }
}

/*
first: build the max heap
second: remove the root of the heap to the end of heap, bacause the root is the max of current,
so, it should be move to the end, and then, rebuild the heap for the sub-heap*/
void heap_sort(int *array, const int size)
{
    for (int i = size / 2; i >= 0; --i)
    {
        max_heap(array, size, i);
    }

    for (int i = size -1; i > 0; --i)
    {
        swap(array, array + i);
        max_heap(array, i, 0);
    }
}


int main()
{
    srand(time(NULL));
    int array[100];
    for (size_t i = 0; i < 100; i++)
    {
        array[i] = rand() % 1000;
    }

    heap_sort(array, 100);


    for (size_t i = 0; i < 100; i++)
    {
        cout << array[i] << endl;
    }

    waitfordebug();
}

#endif // 1
