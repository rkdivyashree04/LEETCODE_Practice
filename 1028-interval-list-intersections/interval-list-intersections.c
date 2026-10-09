/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned in *returnColumnSizes.
 */

#include <stdlib.h>

int** intervalIntersection(int** firstList, int firstSize,
                           int* firstColSize, int** secondList,
                           int secondSize, int* secondColSize,
                           int* returnSize, int** returnColumnSizes)
{
    int i = 0, j = 0;
    
    int maxSize = firstSize + secondSize;
    
    int** result = (int**)malloc(maxSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSize * sizeof(int));
    
    *returnSize = 0;

    while (i < firstSize && j < secondSize)
    {
        // Find intersection
        int start = firstList[i][0] > secondList[j][0]
                    ? firstList[i][0] : secondList[j][0];

        int end = firstList[i][1] < secondList[j][1]
                  ? firstList[i][1] : secondList[j][1];

        // If they intersect
        if (start <= end)
        {
            result[*returnSize] = (int*)malloc(2 * sizeof(int));

            result[*returnSize][0] = start;
            result[*returnSize][1] = end;

            (*returnColumnSizes)[*returnSize] = 2;

            (*returnSize)++;
        }

        // Move the interval which ends first
        if (firstList[i][1] < secondList[j][1])
            i++;
        else
            j++;
    }

    return result;
}