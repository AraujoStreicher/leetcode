class Solution:
    def minPath(self, i: int, j: int,  grid: List[List[int]], dp: List[List[int]]) -> int:
        
        if i == 0 and j == 0:
            return grid[0][0]
        if i < 0 or j < 0:
            return float('inf')
        
        if(dp[i][j] != -1):
            return dp[i][j]
        
        up = self.minPath(i-1, j, grid, dp)
        left = self.minPath(i, j-1, grid, dp)

        dp[i][j] = grid[i][j] + min(up, left)

        return dp[i][j]
    
    def minPathSum(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        dp = [[-1 for _ in range(cols)] for _ in range(rows)]
        return self.minPath(rows - 1, cols - 1, grid, dp)