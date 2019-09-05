class MinHeap:
    def __init__(self, hsize = 10):
        self.heap = int[hsize]
        self.size = hsize
        self.elements = 0
        self.builder(self.heap, self.size)
    def builder(self, heap: int, n: int) -> None:
        i = n/2
        while i >= 1:
            self.heapify(heap,i,n)
            i -= 1
    def heapify(self, heap: int, i: int, n: int) -> None:
        tmp = heap[i]
        j = 2 * i
        while j <= n:
            if (j < n) and (heap[j+1] < heap[j]):
                j = j + 1
            if tmp < heap[j]:
                break
            elif tmp >= heap[j]:
                heap[j/2] = heap[j]
                j = 2 * j
        heap[j/2] = tmp
        return
    def add(self, data: int) -> bool:
        if self.elements >= self.size:
            return False
        self.heap[elements + 1] = data
        self.builder(self.heap, self.size)
        return True
    def remove(self) -> None:
        j = 0
        while j < elements:
            self.heap[j] = self.heap[j + 1]
            elements -= 1
        self.builder(self.heap, self.size)
    def getVal(self, index: int) -> int:
        if index < self.elements:
            return self.heap[index]
        else:
            return -1
        
