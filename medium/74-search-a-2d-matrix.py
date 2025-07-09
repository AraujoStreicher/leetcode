class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        l = 0
        r = len(matrix)-1

        while l <= r:
            mid = (l+r)//2

            if target == matrix[mid][0]:
                return True
            elif target > matrix[mid][0]:
                l = mid + 1
            else:
                r = mid - 1
        
        line = matrix[r]
        
        l=0
        r=len(line)-1
        while l <= r:
            mid = (l+r)//2
            
            if target == line[mid]:
                return True
            elif target > line[mid]:
                l = mid + 1
            else:
                r = mid - 1
        
        return False