class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        n = len(grid)
        m = len(grid[0])
        visited = [[False] * m for _ in range(n)]
        def dfs(i, j):
            if i < 0 or j < 0 or i >= n or j >= m or visited[i][j] or grid[i][j] == 0:
                return 0

            visited[i][j] = True

            total = grid[i][j]
            total += dfs(i - 1, j)
            total += dfs(i + 1, j)
            total += dfs(i, j + 1)
            total += dfs(i, j - 1)

            return total
        
        cnt = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] != 0 and not visited[i][j]:
                    t = dfs(i, j)

                    if t % k == 0:
                        cnt += 1

        return cnt

'''
    [0 0 0]
    [0 0 1]
    [11 0 6]
    [0 10 2]
    [0 0 0]
    [8 0 0]
'''