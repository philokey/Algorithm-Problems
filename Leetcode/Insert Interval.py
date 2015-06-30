# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
    def insert(self, intervals, newInterval):
        l = newInterval.start
        r = newInterval.end
        ret = []
        flag = 1
        for i in intervals:
            if flag == 1:
                if r < i.start:
                    flag = 0
                    ret.append([l,r])
                    ret.append(i)
                elif l > i.end:
                    ret.append(i)
                elif i.start < l and i.end > r:
                    flag = 0
                    ret.append(i)
                else :
                    r = max(r,i.end)
                    l = min(l,i.start)
                
            else : ret.append(i)
        if flag :
            ret.append([l,r])
        return ret
                
                    
            
