class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        db = s + s;
        check = ""
        for i in range(1,len(db) - 1):
            check += db[i]
        return s in check