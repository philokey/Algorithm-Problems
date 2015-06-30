# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    # @param intervals, a list of Interval
    # @return a list of Interval
    def merge(self, intervals):
        n = len(intervals)
        if n == 0: return []
        intervals.sort(key = lambda x:x.start)
        ret = []
        l = intervals[0].start
        r = intervals[0].end
        for i in range (1,n):
            if r < intervals[i].start:
                ret.append([l,r])
                l = intervals[i].start
                r = intervals[i].end
            else :
                r = max(r,intervals[i].end)
        ret.append([l,r])
        return ret
