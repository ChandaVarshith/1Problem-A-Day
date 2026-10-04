class Solution:
    def checkValidString(self, s: str) -> bool:
        n= len(s)
        stack = []
        special = []

        i=0
        #use .append() and .pop()
        for x in s:
            if x is '(':
                stack.append(i)
            elif x is '*':
                special.append(i)
            else:
                if not stack:
                    if not special:
                        return False
                    special.pop()
                else:
                    stack.pop()
            i+=1
        for x in reversed(stack):
            if len(special)!=0 and x <= special.pop():
                #nothing should be done
                stack.pop()
            else:
                return False
        return len(stack)==0