void reverse(int arr[], int start, int end)
{
    while(start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    k = k % numsSize;

    // Reverse entire array
    reverse(nums, 0, numsSize - 1);

    // Reverse first k elements
    reverse(nums, 0, k - 1);

    // Reverse remaining elements
    reverse(nums, k, numsSize - 1);
}