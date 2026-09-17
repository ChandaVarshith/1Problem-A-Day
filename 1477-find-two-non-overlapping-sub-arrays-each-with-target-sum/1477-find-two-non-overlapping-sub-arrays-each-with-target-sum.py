class Solution:
    def minSumOfLengths(self, arr: list[int], target: int) -> int:
        n = len(arr)
        sum, l = 0, 0

        dp = [float('inf')] * n
        ans, best = sys.maxsize, sys.maxsize

        for r in range(n):
            sum += arr[r]

            while sum > target:
                sum -= arr[l]
                l += 1
            

            if sum == target:
                length = r - l + 1
                if l > 0 and dp[l - 1] != float('inf'):
                    ans = min(ans, length + dp[l - 1])

                best = min(best, length)

            dp[r] = best
        
        return -1 if ans == sys.maxsize else ans