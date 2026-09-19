class Solution:
    def checkOverlap(self, r: int, xC: int, yC: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        lX, lY = min(x1, x2), min(y1, y2)
        hX, hY = max(x1, x2), max(y1, y2)

        closeX = max(lX, min(hX, xC)) # close to center of X of circle
        closeY = max(lY, min(hY, yC)) # close to center of Y of circle

        return (xC - closeX)**2 + (yC - closeY)**2 <= r * r

        '''
        (x1 - dx)^2 + (y1 - dy)^2 <= r*r

        '''