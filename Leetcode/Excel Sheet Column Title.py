class Solution:
    # @return a string
    def convertToTitle(self, num):
        ret = ''
        while num > 0:
            if num % 26 == 0:
                ret = 'Z' + ret
                num /= 26
                num -= 1
            else:
                tmp = num % 26 + 64
                ret = chr(tmp) + ret
                num /= 26
        return ret