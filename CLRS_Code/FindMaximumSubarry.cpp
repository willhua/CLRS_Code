#include "CommonInclude.h"

/*CLRS chapter 4.1*/

MaxSubArray find_max_subarray_SIMPLE(int *array, int low, int high)
{
    int max = INT32_MIN, sum = 0, left,right;
    for (int i = low; i < high; i++)
    {
        sum = 0;
        for (int j = i; j < high; ++j)
        {
            sum += array[j];
            if (sum > max) {
                max = sum;
                left = i;
                right = j;
            }
        }
    }
    return MaxSubArray(left, right, max);
}

MaxSubArray find_max_cross_subarray(int *array, int low, int high)
{

    if (low == high) // there is only one element. 
        return MaxSubArray(low, low, array[low]);

    int mid = (low + high) / 2;
    int left_max = INT32_MIN, left = mid; 
    int sum = 0;
    for (int i = left; i >= low; --i)
    {
        sum += array[i];
        if (sum > left_max) {
            left_max = sum;
            left = i;
        }
    }
    int right_max = INT32_MIN, right = mid + 1;
    sum = 0;
    for (int i = right; i <= high; i++)
    {
        sum += array[i];
        if (sum > right_max) {
            right_max = sum;
            right = i;
        }
    }
    return MaxSubArray(left, right, left_max + right_max);
}

//the result is an closed interval on double side.
MaxSubArray find_max_subarry(int *array, int low, int high)
{
    if (low == high)    
        return MaxSubArray(low, low, array[low]);
    struct MaxSubArray left, cross, right;
    int mid = (low + high) / 2;
    cross = find_max_cross_subarray(array, low, high);
    left = find_max_subarry(array, low, mid);
    right = find_max_subarry(array, mid+1, high);
    if (cross.value > left.value && cross.value > right.value)
        return cross;
    else if (left.value > right.value && left.value > cross.value)
        return left;
    else
        return right;
}

#if true

int main()
{
    const int len = 300;
    int array[len];
    std::srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        array[i] = std::rand() * (std::rand() & 0x01 ? 1:-1);
    }

    std::cout << find_max_subarray_SIMPLE(array, 0, len).tostring() << "   " << find_max_subarry(array, 0, len-1).tostring();

    return 0;
}

#endif