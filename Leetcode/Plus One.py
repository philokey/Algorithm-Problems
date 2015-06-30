class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        for i in range(len(digits)):
            digits[i] = str(digits[i])
        s = int(''.join(digits))
        s += 1
        s = str(s)
        s = list(s)
        for i in range(len(s)):
            s[i] = int(s[i])
        return s
        
