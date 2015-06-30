class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        subStr = ''
        head = 0
        n = len(s)
        ret = 0
        for i in range(n):
            if s[i] not in subStr:
                subStr += s[i]
            else :
                ret = max(ret, len(subStr))
                while s[i] != s[head]: head += 1
                head += 1
                subStr = s[head:i+1]
        return max(ret, len(subStr))

