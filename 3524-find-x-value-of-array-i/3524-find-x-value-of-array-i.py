class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)

        dp = [[-1] * k for _ in range(n)]
        result = [0] * k

        def solve(i):
            
            if i >= n:
                return [0] * k
            
            if dp[i][0] != -1:
                return dp[i]

            nxt_dp = solve(i + 1)

            cur = [0] * k
            x = nums[i] % k

            cur[x] += 1

            for r in range(k):
                if nxt_dp[r]:
                    new_r = (r * x) % k
                    cur[new_r] += nxt_dp[r]
            
            dp[i] = cur
            return cur
        
        result = [0] * k
        for i in range(n):
            cur = solve(i)

            for j in range(k):
                result[j] += cur[j]

        return result