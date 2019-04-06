#include "test_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int FillRandInputData(float* dst_arr, int elem_size, int seed)
{
    if (seed == 0)
        srand((unsigned)time(NULL));
    else
        srand(seed);
    
    float *workp = dst_arr;
    for (int i = 0; i < elem_size; i++)
    {
        float t = 0.f;
        if (rand() % 100 < 8)
            t = (float) (rand() % 1000 / 1000.0f);
        *(workp++) = t;
    }
    return 0;
}

int compare_float_arrays()
{
    return 0;
}
