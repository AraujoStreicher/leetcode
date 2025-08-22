class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])

        i1 = rows+1
        j1 = cols+1
        i2 = 0
        j2 = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    if i < i1:
                        i1 = i
                    if j < j1:
                        j1 = j
                    if i > i2:
                        i2 = i
                    if j > j2:
                        j2 = j
        
        return (i2 - i1 + 1) * (j2 - j1 + 1)