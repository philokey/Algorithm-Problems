# Definition for a point
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        n = len(points)
        if n < 3: return n
        ret = 0
        for i in xrange(n):
            slope = {'inf': 0}
            samePoint = 0
            for j in xrange(n):
                if points[i].x == points[j].x and points[i].y == points[j].y:
                    samePoint += 1
                elif points[i].x == points[j].x:
                    slope['inf'] += 1
                else:
                     k = 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x)
                     slope[k] = 1 if k not in slope else slope[k] + 1
            ret = max(ret, max(slope.values()) + samePoint)
        return ret