class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        n = len(arr)
        MOD = 10**9 + 7

        odd, even = 0, 1
        pref, cnt = 0, 0
        total = 0

        for i in arr:
            pref += i

            if pref & 1:
                total = (total + even) % MOD
                odd += 1
            else:
                total = (total + odd) % MOD
                even += 1

        return total