class Node:
    def __init__(self, data, next):
        self.next = next
        self.data = data

class ForwardList:
    def __init__(self):
        self.head = None
        self.sz = 0

    def push_front(self, data):
        self.head = Node(data, self.head)
        self.sz = self.sz + 1

    def pop_front(self):
        if self.head:
            self.head = self.head.next
            self.sz = self.sz - 1

    def size(self):
        return self.sz

    def __getitem__(self, idx):
        tmpNode = self.head
        while idx > 0:
            tmpNode = tmpNode.next
            idx = idx - 1
        return tmpNode.data
    
import unittest

class TestForwardList(unittest.TestCase):
    def test_push_front(self):
        fl = ForwardList()

        for i in range(100):
            fl.push_front(i + 1)

        for i in range(100):
            self.assertEqual(fl[i],  100 - i)

    def test_pop_front(self):
        fl = ForwardList()

        for i in range(100):
            fl.push_front(i + 1)

        for i in range(50):
            fl.pop_front();

        for i in range(0, 50):
            self.assertEqual(fl[i],  50 - i)

        self.assertEqual(fl.size(), 50)

if __name__ == "__main__":
    unittest.main()