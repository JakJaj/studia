class Node:
    '''Klasa opisujaca pojedynczy wezel'''
    def __init__(self,data):
        self.data=data
        self.next=None

class Deque:
    '''Klasa opisujaca kolejke dwustronna'''
    def __init__(self,maxSize=10000):
        self.head=None
        self.dequeSize=0
        self.maxSize = maxSize

    def isEmpty(self):
        if self.dequeSize==0:
            return True
        return False

    def size(self):
        return self.dequeSize

    def enqueueFront(self,data): 
        assert self.dequeSize < self.maxSize,'Dequeue overflow'
        temp=Node(data)
        if self.head==None:
            self.head=temp
            self.dequeSize += 1
        else:
            temp.next=self.head
            self.head=temp
            self.dequeSize=self.dequeSize+1

    def enqueueRear(self,data): 
        assert self.dequeSize < self.maxSize,'Dequeue overflow'
        temp=Node(data)
        if self.head==None:
            self.head=temp
            self.dequeSize += 1
        else:
            curr=self.head
            while curr.next!=None:
                curr=curr.next
            curr.next=temp
            self.dequeSize=self.dequeSize+1

    def dequeueFront(self):
        try:
            if self.dequeSize==0:
                raise Exception("Deque is Empty")
            else:
                temp=self.front
                self.front=self.front.next
                self.dequeSize=self.dequeSize-1
                del temp
        except Exception as e:
            print('Dequeue empty')
        

    def dequeueRear(self):
        try:
            if self.dequeSize==0:
                raise Exception("Deque is Empty")
            else:
                curr=self.front
                prev=None
                while curr.next!=None:
                    prev=curr
                    curr=curr.next
                prev.next=curr.next
                self.dequeSize=self.dequeSize-1
                del curr
        except Exception as e:
            print('Dequeue empty')
        

    def first(self):
        try:
            if self.dequeSize==0:
                raise Exception("Deque is Empty")
            else:
                return self.head.data
        except Exception as e:
            print(str(e))


kolejka = Deque()
