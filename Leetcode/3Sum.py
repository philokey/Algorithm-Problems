class Solution:
    # @return a list of lists of length 3, [[val1,val2,val3]]
    def threeSum(self, num):
        ret = []
        now = []
        n = len(num)
        if n < 3: return ret
        num.sort()
        pre = num[0] - 1
        for i in range(n - 2):
            if (num[i] == pre): continue
            pre = num[i]
            now = [num[i], 0, 0]
            l = i + 1
            r = n - 1
            while l < r:
                sum = num[i] + num[l] + num[r]
                if sum == 0:
                    now[1] = num[l]
                    now[2] = num[r]
                    ret.append(now[:])
                    l += 1
                    r -= 1
                    while l < r and num[l] == num[l - 1] and num[r] == num[r + 1]:
                        l += 1
                        r -= 1
                elif sum > 0:
                    r -= 1
                else : l += 1
        return ret
