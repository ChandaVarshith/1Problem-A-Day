class Solution:
    def reverse(self, x: int) -> int:
        a = str(x)
        check = False
        if(a[0] == '-'):
            a = a[1:]
            check = True
        n = len(a)
        a = a[::-1]
        cnt = 0
        for i in a:
            if i=="0":
                cnt+=1
            else:
                break
        if cnt==n:
            return 0
        a = a[cnt:]
        x = int(a)
        if check==True:
            x = -x
        if x > 2**31 -1 or x < -2**31:
            return 0 
        return x
