from __future__ import annotations

class SList:
    def __init__(self):
        self.head = None
        self.tail = None
    def push_back(a: str) -> None:
        node = SListNode(a)
        if head == None:
            self.head = node
            self.tail = node
        else:
            self.tail.setNext(node)
            self.tail = node
    def remove_front(self, a: str) -> bool:
        if not self.empty():
            copy = self.head.getItem()
            tmp = self.head.getNext()
            self.head = tmp
            if tmp == None:
                self.tail = None
            return True
        return False
    def empty(self) -> bool:
        return self.head == None
    def get(self, n: int) -> str:
        i = 0
        currNode = self.head
        while currNode != None:
            if i == n:
                return currNode.getItem()
            i += 1
            currNode = currNode.getNext()
        return ""
    def length(self) -> int:
        i = 0
        currNode = self.head
        while currNode != None:
            i += 1
            currNode = currNode.getNext()
        return i
    def __del__(self):
        t = "";
        while not self.empty():
            self.remove_front(t)

class SListNode(SList):
    def __init__(self, a: str):
        self.item = a
        self.nxt = None
    def getNext(self) -> SListNode:
        return self.nxt
    def setNext(self, n: SListNode) -> None:
        self.nxt = n
    def getItem(self) -> str:
        return item
