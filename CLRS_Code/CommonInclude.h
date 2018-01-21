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

