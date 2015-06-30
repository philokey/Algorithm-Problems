class Solution:
    # @return an integer
    def maxArea(self, height):
        l, r = 0, len(height) - 1
        ret = 0
        while l < r:
            if height[l] < height[r]:
                ret = max(ret, height[l] * (r - l))
                l += 1
            else :
                ret = max(ret, height[r] * (r - l))
                r -= 1
        return ret
