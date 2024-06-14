int cmp(const void* a, const void *b){
    return *(int*)a - *(int*)b;
}

int minIncrementForUnique(int* nums, int numsSize) {
    int count = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    
    int next_unique = nums[0] + 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < next_unique) {
            count += next_unique - nums[i];
            next_unique++;
        } else {
            next_unique = nums[i] + 1;
        }
    }
    
    return count;
}
