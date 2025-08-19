class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        cnt = 0
        res = 0
        for num in nums:
            if num != 0:
                cnt = 0
            else: 
                cnt += 1
                res += cnt
        
        return res