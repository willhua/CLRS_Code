#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>


inline void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

inline void waitfordebug()
{
    int i = 0;
    std::cin >> i;
}

//fill the array of size number elements by rand number which is not bigger than max 
inline void randArray(int *array, int size, int max = INT_MAX)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (max + 1);
    }
}

//std::cout the data of array with width elements during one line
inline void coutArray(int *array, int size, int width = 5)
{
    for (int  i = 0; i < size; i+=width)
    {
        for (int j = i; j < i + width && j < size; ++j)
            std::cout << array[j] << "\t";
        std::cout << std::endl;
    }
}

