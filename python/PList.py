from __future__ import annotations

class Object:
    def __init__(self):
        pass
class StringItem(Object):
    def __init__(self, c=""):
        s = c
class IntegerItem(Object):
    def __init__(self, n = 0):
        i = int(n)
class DoubleItem(Object):
    def __init__(self, n = 0.0):
        i = float(n)
class PList:
    def __init__(self):
        self.head = None
        self.tail = None
    def push_back(self, a: Object) -> None:
        node = ListNode(a)
        if self.head == None:
            self.head = node
            self.tail = node
        else:
            self.tail.setNext(node)
            self.tail = node
    def remove_front(self, a: Object) -> bool:
        if not self.empty():
            tmp = self.head.getNext()
            self.head = tmp
            if tmp == None:
                self.tail = None
            return True
        return False
    def empty(self) -> bool:
        return self.head == None
    def get(self, n: int) -> Object:
        i = 0
        o = Object()
        currNode = self.head
        while currNode != None:
            if i == n:
                return currNode.getItem()
            i += 1
            currNode = currNode.getNext()
        return i
    def __del__(self):
        t = Object()
        while not self.empty():
            self.remove_front(t)
class PListNode(PList):
    def __init__(self, a: Object):
        self.obj = a
        self.nxt = None
    def getNext(self) -> PListNode:
        return self.next
    def setNext(self, n: PListNode) -> None:
        self.nxt = n
    def getItem(self) -> Object:
        return self.obj
