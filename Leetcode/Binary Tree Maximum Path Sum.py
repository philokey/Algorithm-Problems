# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def dfs(self,root):
        if root == None: return 0
        lf = self.dfs(root.left)
        ri = self.dfs(root.right)
        mx = max(lf, ri, lf + ri)
        self.ret = max(self.ret,mx + root.val)
        return max(lf,ri,0) + root.val
         
    def maxPathSum(self, root):
        if root == None: return 0
        self.ret = root.val
        self.dfs(root)
        return self.ret
