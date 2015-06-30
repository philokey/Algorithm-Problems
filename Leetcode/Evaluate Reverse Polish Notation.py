class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
		sta = []
		for i in tokens:
			if i not in ('+','-','*','/'):
				sta.append(int(i))
			else:
				b = sta.pop()
				a = sta.pop()
				c = 0
				if i == '+': c = a + b
				elif i == '-': c = a - b
				elif i == '*': c = a * b
				else: c = int(a * 1.0 / b)
				sta.append(c)
		return sta[0]
