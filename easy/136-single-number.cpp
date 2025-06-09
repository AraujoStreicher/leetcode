int singleNumber(int* nums, int numsSize) {
    int _xor = 0;
    for(int i = 0; i < numsSize; i++)
        _xor = _xor ^ nums[i];
    
    return _xor;
}