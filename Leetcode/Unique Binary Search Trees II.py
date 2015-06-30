# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @return a list of tree node
    def solve(self,s,t):
        if s > t: return [None]
        res = []
        for root in range(s, t + 1):
            left = self.solve(s, root - 1)
            right = self.solve(root + 1, t)
            for i in left:
                for j  in right:
                    rt = TreeNode(root)
                    rt.left = i
                    rt.right = j
                    res.append(rt)
        return res
    def generateTrees(self, n):
        return self.solve(1,n)
