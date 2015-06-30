class Solution:
	# @param A, a list of integer
	# @return an integer
	def singleNumber(self, A):
		bit = [0 for i in range(32)]
		for x in A:
			for i in range(32):
				if x & (1 << i) == 1 << i: bit[i] += 1
		ret = 0
		
		if bit[31] % 3 == 0: 
			for i in range(31): 
				if bit[i] % 3 == 1: ret += 1 << i	
		else: 
			for i in range(31): 
				if bit[i] % 3 == 0: ret += 1 << i
			ret = -(ret + 1)
		return ret
			
