class Solution:
    # @param s, a string
    # @return an integer
    def longestValidParentheses(self, s):
        sLen, stack, ret = len(s), [(-1, ')')], 0
        for i in range(sLen):
            if stack[-1][1] == '(' and s[i] == ')':
                stack.pop()
                ret = max(ret, i - stack[-1][0])
            else :
                stack.append((i, s[i]))
        return ret
