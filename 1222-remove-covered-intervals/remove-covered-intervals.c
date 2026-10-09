#include <stdlib.h>

int compare(const void* a, const void* b)
{
    int* x = *(int**)a;
    int* y = *(int**)b;

    // Sort by start
    if (x[0] != y[0])
        return x[0] - y[0];

    // Same start -> larger end first
    return y[1] - x[1];
}

int removeCoveredIntervals(int** intervals, int intervalsSize,
                           int* intervalsColSize)
{
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int count = 0;
    int maxEnd = 0;

    for (int i = 0; i < intervalsSize; i++)
    {
        if (intervals[i][1] > maxEnd)
        {
            count++;
            maxEnd = intervals[i][1];
        }
    }

    return count;
}