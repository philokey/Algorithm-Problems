class Solution:
    # @return an integer
    def reverse(self, x):
        tp = 1
        if x < 0: 
            x = -x
            tp = -1
        x = str(x)
        x = x[::-1]
        x = int(x)
        return x * tp
