import sys
class MaxHeap():
    def __init__(self,maxsize=1000):
        self.maxsize = maxsize
        self.size = 0
        self.Heap = [0] * (self.maxsize + 1)
        self.Heap[0] = sys.maxsize
        self.FRONT = 1

    def parent(self,pos):
        return pos // 2
    
    def leftChild(self,pos):
        return 2 * pos
    
    def righyChild(self,pos):
        return 2 * pos + 1
    
    def isLeaf(self,pos):
        if pos >= self.size // 2 and pos <= self.size:
            return True
        return False
    
    def swap(self,fpos,spos):
        self.Heap[fpos], self.Heap[spos] = self.Heap[spos], self.Heap[fpos]

    def maxHeapify(self,pos):
        if not self.isLeaf(pos):
            if self.Heap[pos] < self.Heap[self.leftChild(pos)] or self.Heap[pos] < self.Heap[self.righyChild(pos)]:
                if self.Heap[self.leftChild(pos)] > self.Heap[self.righyChild(pos)]:
                    self.swap(pos,self.leftChild(pos))
                    self.maxHeapify(self.leftChild(pos))
                else:
                    self.swap(pos, self.righyChild(pos))
                    self.maxHeapify(self.righyChild(pos))

    def insert(self,element):
        if self.size >= self.maxsize:
            return
        self.size += 1
        self.Heap[self.size] = element

        current = self.size
        while self.Heap[current] > self.Heap[self.parent(current)]:
            self.swap(current,self.parent(current))
            current = self.parent(current)

    def Print(self):
        for i in range(1, (self.size // 2) + 1):
            print(f'Parent : {self.Heap[i]}\nLeft Child : {self.Heap[2 * i]}\nRight Child : {self.Heap[2 * i + 1]}')

    def extractMax(self):
        pooped = self.Heap[self.FRONT]
        self.Heap[self.FRONT] = self.Heap[self.size]
        self.size -= 1
        self.maxHeapify(self.FRONT)
        return pooped
    def wstawianie_listy_do_kopca(self,lista):
        for i in lista:
            self.insert(i)

kopiec = MaxHeap(10)
lista = [12,43,123,62,1762,2134,32,16,432]
kopiec.wstawianie_listy_do_kopca(lista)
kopiec.Print()