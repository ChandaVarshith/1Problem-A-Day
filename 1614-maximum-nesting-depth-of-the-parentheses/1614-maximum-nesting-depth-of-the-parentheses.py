class Solution:
    def maxDepth(self, s: str) -> int:
        stack = []
        maxi = 0
        for i in s:
            if i is '(':
                stack.append(i)
            elif i is ')':
                stack.pop()
            maxi = max(len(stack),maxi)
        return maxi
        
        