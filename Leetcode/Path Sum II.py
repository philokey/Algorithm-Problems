# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a list of lists of integers
    def pathSum(self, root, sum):
        if root == None: return []
        Solution.sum = sum
        Solution.ret = []
        self.solve(root,[root.val])
        return Solution.ret
        
    def solve(self,root,nodeList):
        if root.left == None and root.right == None:
            if Solution.sum == sum(nodeList):
                Solution.ret.append(nodeList)
            return
        if root.left != None:
            self.solve(root.left, nodeList + [root.left.val])
        if root.right != None:
            self.solve(root.right, nodeList + [root.right.val])
        
        
