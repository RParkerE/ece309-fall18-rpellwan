from __future__ import annotations

class StringArrayList:
    def __init__(self, size=1):
        self.arrList = str[size]
        self.firstIdx = 0
        self.lastIdx = size - 1
    def push_back(self, s: str) -> bool:
        i = 0
        while i <= lastIdx:
            if self.arrList[i].empty():
                self.arrList[i] = s
                return True
            i += 1
        self.lastIdx = self.lastIdx + 1
        newSize = self.lastIdx + 1
        tmpList = str[newSize]
        n = 0
        while n <= self.lastIdx:
            if tmpList[n].empty():
                tmpList[n] = self.arrList[n]
            n += 1
        self.arrList = str[newSize]
        self.arrList = tmpList
        return True
    def get(self, n: int) -> str:
        return self.arrList[n]
    def length(self) -> int:
        return self.lastIdx + 1
    def remove_front(self) -> str:
        s = ""
        tmpList = str[self.lastIdx]
        i = 0
        while i <= self.lastIdx:
            if i == 0:
                s = self.arrList[i]
            else:
                tmpList[i-1] = self.arrList[i]
            i += 1
        self.arrList = str[self.lastIdx]
        self.arrList = tmpList
        return s
    def __del__(self):
        del self.arrList
            
