class Solution:
    # @return an integer
    def atoi(self, str):
        str = str.strip()
        newStr = ''
        for i in xrange(len(str)):
            if '0' <= str[i] <= '9' or (str[i] in ('+', '-') and i == 0):
                newStr += str[i]
            else:
                break
        if newStr in ('', '+', '-'):
            return 0
        elif -2147483648 <= int(newStr) <= 2147483647:
            return int(newStr)
        elif int(newStr) > 2147483647:
            return 2147483647
        else:
            return -2147483648
