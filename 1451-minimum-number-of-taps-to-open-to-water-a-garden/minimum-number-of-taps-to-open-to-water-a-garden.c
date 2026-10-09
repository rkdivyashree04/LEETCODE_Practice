#include <stdlib.h>

int minTaps(int n, int* ranges, int rangesSize)
{
    // maxReach[i] = farthest point we can reach
    // from an interval starting at i
    int* maxReach = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i <= n; i++)
    {
        int start = i - ranges[i];

        if (start < 0)
            start = 0;

        int end = i + ranges[i];

        if (end > n)
            end = n;

        if (end > maxReach[start])
            maxReach[start] = end;
    }

    int taps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < n; i++)
    {
        if (maxReach[i] > farthest)
            farthest = maxReach[i];

        // Need another tap
        if (i == currentEnd)
        {
            if (farthest <= currentEnd)
            {
                free(maxReach);
                return -1;
            }

            taps++;
            currentEnd = farthest;
        }
    }

    free(maxReach);

    return taps;
}