class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        lenA = len(a)
        lenB = len(b)
        if lenA > lenB:
            b = '0' * (lenA - lenB) + b
        else:
            a = '0' * (lenB - lenA) + a
        length = len(a)
        a = a[::-1]
        b = b[::-1]
        ret = ''
        carry = 0
        for i in xrange(length):
            tmp = ord(a[i]) - 48 + ord(b[i]) - 48 + carry
            ret += str(tmp % 2)
            carry = tmp / 2
        if carry == 1:
            ret += '1'
        return ret[::-1]
