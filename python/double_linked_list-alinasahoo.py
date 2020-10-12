class DLLNode:
    def __init__(self,data):
        self.data = data
        self.next = None
        self.previous = None

    def __repr__(self):
        return "DLL Node object: data={}".format(self.data)

    def get_data(self):
        """"Return the self.data attribue"""
        return self.data

    def set_data(self,new_data):
        """"Replace the existing value of the self.data attribute with the new_data parameter"""
        self.data = new_data

    def get_next(self):
        """"Return the self.next attribute"""
        return self.next

    def set_next(self, new_next):
        """"Replace the existing value of the self.data attribute with the new_next parameter"""
        self.next = new_next

    def get_previous(self):
        """"Return the self.previous attribue"""
        return self.previous

    def set_previous(self,new_previous):
        """"Replace the existing value of the self.previous attribute with the new_previous parameter"""
        self.previous=new_previous;

class DLL:
    def __init__(self):
        self.head = None

    def __repr__(self):
        return "<DLL object: head=>".format(self.head)

    def is_empty(self):
        return self.head is None

    def size(self):
        """Traverses the Linked List and returns an integer value representing the number of nodes in the Linked List"""
        size = 0
        if self.head == None:
            return 0

        current = self.head
        while current is not None: #while there are more still nodes left to count
            size = size + 1
            current = current.get_next()

        return size

    def search(self, data):
        """Traverses the linked list and returns true if the data searched is present in one of the nodes. Otherwise, returns false.

        The time complexity is O(n). """
        if self.head == None:
            return "Linked List is empty. No nodes to search."

        current = self.head
        while current is not None:
            if current.get_data() == data:
                return True
            else:
                current = current.get_next()

        return False

    def add_front(self, new_data):
        """Add a node whose data is a new_data argument to the front of the linked list"""
        temp = DLLNode(new_data)
        temp.set_next(self.head)
        if self.head is not None:
            self.head.set_previous(temp)
        self.head = temp

    def remove(self,data):
        """Removes the first occurence of a node that contains a data argument as it's self.data attribute. Returns nothing.

        The time complexity of this is O(n) because in worst case we have to visit everything before finding the one we want to remove."""
        if self.head is None:
            return "Linked List is empty. No nodes to remove."

        current = self.head
        found = False
        while not found:
            if current.get_data() == data:
                found = True
            else:
                if current.get_next() is None:
                    return "A node with that data value is not present."
                else:
                    current = current.get_next()

        if current.previous is None:
            self.head = current.get_next()
        else:
            current.previous.set_next(current.get_next())
            current.next.set_previous(current.get_previous())
