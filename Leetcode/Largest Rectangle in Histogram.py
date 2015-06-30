class Solution:
    # @param height, a list of integer
    # @return an integer

    def largestRectangleArea(self, height):
        q = []
        ret = 0
        height += [0]
        n = len(height)
        i = 0
        while i < n:
            if not q or height[q[-1]] <= height[i]:
                q.append(i)
                i += 1
            else :
                t = q.pop()
                ret = max(ret, height[t] * (i if not q else i - q[-1] -1))
                
        return ret


