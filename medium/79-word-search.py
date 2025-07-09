class Solution:
    

    def exist(self, board: List[List[str]], word: str) -> bool:
        def dp(i,j,k):
            if k == len(word):
                return True
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or board[i][j] != word[k]:
                return False
            
            aux = board[i][j]
            board[i][j] = ''

            if dp(i+1, j, k+1) or dp(i-1, j, k+1) or dp(i, j+1, k+1) or dp(i, j-1, k+1):
                return True

            board[i][j] = aux
            return False

        for i in range(len(board)):
            for j in range(len(board[0])):
                if dp(i,j,0):
                    return True
        
        return False