class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data
    
class BST:
    def __init__(self):
        self.root = None

    def insert(self, data):
        parent = None
        node = self.root

        while node:
            parent = node

            if data < node.data:
                node = node.left
            elif data > node.data:
                node = node.right
            else:
                return
            
        newNode = Node(data)

        if parent == None:
            self.root = newNode
        elif data < parent.data:
            parent.left = newNode
        elif data > parent.data:
            parent.right = newNode

    def print(self):
        self.treeprint(self.root)

    def treeprint(self, tree):
        if tree:
            self.treeprint(tree.left)      # l
            self.treeprint(tree.right)     # r
            print(tree.data, end=" ")      # n

bst = BST()

for i in range(10):
    bst.insert(i)

bst.print()