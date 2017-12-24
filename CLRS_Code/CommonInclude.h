#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>




typedef struct MaxSubArray {
    int left;
    int right;
    int value;

    MaxSubArray(int l, int r, int v) {
        left = l;
        right = r;
        value = v;
    }

    MaxSubArray() {
        left = INT32_MAX;
        right = INT32_MIN;
        value = INT32_MIN;
    }

    std::string tostring() {
        return "[" + std::to_string(left) +", " + std::to_string(right) + "] = " + std::to_string(value);
    }
} * pMaxSubArray;