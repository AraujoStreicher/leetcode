class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        bucket = {} 
        
        for i, n in enumerate(nums): 
            bucket_i = n // (valueDiff + 1) 
            if bucket_i in bucket and abs(n - bucket[bucket_i]) <= valueDiff: 
                return True 
            if bucket_i + 1 in bucket and abs(n - bucket[bucket_i + 1]) <= valueDiff: 
                return True 
            if bucket_i - 1 in bucket and abs(n - bucket[bucket_i - 1]) <= valueDiff: 
                return True 
            bucket[bucket_i] = n 
            if i >= indexDiff: 
                del bucket[nums[i-indexDiff] // (valueDiff + 1)] 
        
        return False
