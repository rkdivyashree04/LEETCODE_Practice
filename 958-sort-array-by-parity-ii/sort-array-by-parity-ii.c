/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize)
{
    int even = 0;
    int odd = 1;

    while(even < numsSize && odd < numsSize)
    {
        // Find an odd number at an even index
        while(even < numsSize && nums[even] % 2 == 0)
        {
            even += 2;
        }

        // Find an even number at an odd index
        while(odd < numsSize && nums[odd] % 2 != 0)
        {
            odd += 2;
        }

        if(even < numsSize && odd < numsSize)
        {
            int temp = nums[even];
            nums[even] = nums[odd];
            nums[odd] = temp;
        }
    }

    *returnSize = numsSize;
    return nums;
}