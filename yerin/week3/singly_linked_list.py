class LinkedList:
    class __Node:
        def __init__(self, element=None):
            self.element = element
            self.next = None

        def __str__(self):
            return str(self.element)

        def hasNext(self):
            return self.next != None

        def getNext(self):
            return self.next

        def getElement(self):
            return self.element

        def setNext(self,nextItem):
            self.next = nextItem

        def setElement(self, element):
            self.element = element

        def __len__(self):
            return self.length

        def isEmpty(self):
            return self.length == 0
