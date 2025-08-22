class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def generate(open, close, ans):
            if open + close == n*2:
                res.append(ans)
                return
            
            if open < n:
                generate(open+1, close, ans+"(")
            
            if close < n and close < open:
                generate(open, close+1, ans+")")
        
        generate(0,0,"")

        return res