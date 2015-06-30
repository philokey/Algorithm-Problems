class Solution:
    # @return an integer
    def threeSumClosest(self, num, target):
        ret = sum(num[0:3])
        n = len(num)
        num.sort()
        pre = num[0] - 1
        for i in range(n - 2):
            if (num[i] == pre): continue
            pre = num[i]
            l = i + 1
            r = n - 1
            while l < r:
                s = num[i] + num[l] + num[r]
                if s == target: return s
                if abs(s - target) < abs(ret - target): ret = s
                if s < target: l += 1
                else: r -= 1
        return ret
        
