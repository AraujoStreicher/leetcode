class Solution:
    def canJump2(self, nums: List[int]) -> bool:
        n = len(nums)
        achieve = [False] * n
        achieve[n-1] = True

        for pos in range(n-2, -1, -1):
            num = nums[pos]
            
            for i in range(1, num+1):
                if achieve[pos+i] == True:
                    achieve[pos] = True
                    break
        

        return achieve[0]
    
    def canJump(self, nums: List[int]) -> bool:
        maxReach = 0

        for i in range(0, len(nums)):
            if i > maxReach:
                return False
            maxReach = max(maxReach, i+nums[i])
        
        return True

                