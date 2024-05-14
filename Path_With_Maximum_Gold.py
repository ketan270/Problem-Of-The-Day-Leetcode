class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        visited = [[0] * col for _ in range(row)]
        ans = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] != 0:
                    ans = max(self.find_max(grid, visited, i, j), ans)
        return ans
    
    def find_max(self, arr, visited, i, j):
        if (i < 0 or j < 0 or i >= len(arr) or j >= len(arr[0]) or
                visited[i][j] == 1 or arr[i][j] == 0):
            return -1000000
        
        visited[i][j] = 1
        a = self.find_max(arr, visited, i + 1, j)
        if a < 0:
            a = 0
        b = self.find_max(arr, visited, i - 1, j)
        if b < 0:
            b = 0
        c = self.find_max(arr, visited, i, j + 1)
        if c < 0:
            c = 0
        d = self.find_max(arr, visited, i, j - 1)
        if d < 0:
            d = 0
        visited[i][j] = 0
        return max(max(a, b), max(c, d)) + arr[i][j]
