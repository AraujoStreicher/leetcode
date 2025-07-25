# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return None

        if key < root.val:
            root.left = self.deleteNode( root.left, key)
        elif key > root.val:
            root.right = self.deleteNode( root.right, key)
        else: #key == root.val
            if root.right is None:
                return root.left

            aux = root.right
            while aux.left is not None:
                aux = aux.left
            aux.left = root.left
            return root.right 
        
        return root