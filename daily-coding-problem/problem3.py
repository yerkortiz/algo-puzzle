"""
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
"""
from queue import Queue
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    def serialize(self):
        bfs_list = []
        q = Queue()
        q.put(self)
        while(not q.empty()):
            current = q.get()
            if current == None or current.val == 'n':
                bfs_list.append('n')
                continue
            bfs_list.append(current.val)
            q.put(current.left)
            q.put(current.right)
        return bfs_list
    def deserialize(self, l):
        if l == None or len(l) == 0:
            return None            
        q = Queue()
        j = 1
        i = 0
        tree = Node(l[0])
        q.put(tree)
        while(not q.empty()):
            current = q.get()
            if(current == None or current.val == 'n'):
                continue
            if j < (len(l)/2 ):
                left = Node(l[j])
                j += 1
                right = Node(l[j])
                j += 1
            else:
                left = None
                right = None
            current.left = left
            current.right = right
            q.put(current.left)
            q.put(current.right)
        return tree
            
tree = Node('root', Node('l', Node('ll')), Node('r'))
print(tree.serialize())
print(tree.deserialize(tree.serialize()).serialize())
assert tree.deserialize(tree.serialize()).left.left.val == 'll'



