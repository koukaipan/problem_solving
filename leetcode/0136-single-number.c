int singleNumber(int* nums, int numsSize)
{
    unsigned int i, val;
    
    if (numsSize == 1)
        return *nums;
    
    for (val = i = 0; i < numsSize; i++) {
        val ^= nums[i];
    }
    return val;
}
