class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        ns = []
        for i in s:
            if '0' <= i <= '9' or 'a' <= i <= 'z': ns.append(i)
            elif 'A' <= i <= 'Z': ns.append(chr(ord(i) - ord('A') + ord('a')))
        return ns == ns[::-1]