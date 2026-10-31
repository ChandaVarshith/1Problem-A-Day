class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]

        dp[0][0] = 1
        for i in range(m):
            for j in range(n):
                if dp[i][j] > 0:
                    r = i + 1
                    c = j
                    cur_dir = 1
                    while r < m and c < n:
                        if grid[r][c] == 0:
                            dp[r][c] = (dp[r][c] + dp[i][j]) % (10**9 + 7)
                            break
                        else:
                            if cur_dir == 1:
                                cur_dir = 0
                                c += 1
                            else:
                                cur_dir = 1
                                r += 1

                    r = i
                    c = j + 1
                    cur_dir = 0
                    while r < m and c < n:
                        if grid[r][c] == 0:
                            dp[r][c] = (dp[r][c] + dp[i][j]) % (10**9 + 7)
                            break
                        else:
                            if cur_dir == 0:
                                cur_dir = 1
                                r += 1
                            else:
                                cur_dir = 0
                                c += 1

        return dp[m - 1][n - 1]




        
        # @cache
        # def f(i, j, dir):
        #     if i == m - 1 and j == n - 1:
        #         return 1
            
        #     if i >= m or j >= n:
        #         return 0
            
        #     if grid[i][j] == 1 and dir == 1:
        #         return f(i + 1, j, 0)
        #     elif grid[i][j] == 1 and dir == 0:
        #         return f(i, j + 1, 1)
        #     else:
        #         if grid[i][j] == 0:
        #             return f(i + 1, j, 0) + f(i, j + 1, 1)

        # return f(0, 0, 0) % (10**9 + 7)