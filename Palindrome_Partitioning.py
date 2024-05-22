from typing import List

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def is_palindrome(sub: str) -> bool:
            return sub == sub[::-1]
        
        def backtrack(start: int, path: List[str]):
            if start == len(s):
                result.append(path[:])
                return
            for end in range(start + 1, len(s) + 1):
                current_sub = s[start:end]
                if is_palindrome(current_sub):
                    path.append(current_sub)
                    backtrack(end, path)
                    path.pop()
        
        result = []
        backtrack(0, [])
        return result
