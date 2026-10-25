class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        n, m = len(grid), len(grid[0])
        visited = [[False] * m for _ in range(n)]

        def dfs(i, j):
            if (i >= n or j >= m or j < 0 or i < 0):
                return False

            if grid[i][j] == 1 or visited[i][j]:
                return True
            
            visited[i][j] = True

            bottom = dfs(i + 1, j)
            up = dfs(i - 1, j)
            right = dfs(i, j + 1)
            left = dfs(i, j - 1)

            return up and bottom and left and right

        cnt = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0 and not visited[i][j]:
                    if dfs(i, j):
                        cnt += 1
        return cnt