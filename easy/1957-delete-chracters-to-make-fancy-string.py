class Solution:
    def makeFancyString(self, s: str) -> str:
        res = s[0]
        cnt = 0
        for i in range(1, len(s)):
            if s[i] == res[-1]:
                cnt += 1
                if cnt < 2:
                    res += s[i]
            else:
                cnt = 0
                res += s[i]
        return res
