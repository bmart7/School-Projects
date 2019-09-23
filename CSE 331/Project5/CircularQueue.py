class CircularQueue():
    # DO NOT MODIFY THESE METHODS
    def __init__(self, capacity=4):
        """
        Initialize the queue with an initial capacity
        :param capacity: the initial capacity of the queue
        """
        self.capacity = capacity
        self.size = 0
        self.data = [None] * capacity
        self.head = 0
        self.tail = 0


    def __eq__(self, other):
        """
        Defines equality for two queues
        :return: true if two queues are equal, false otherwise
        """
        if self.capacity != other.capacity:
            return False
        for i in range(self.capacity):
            if self.data[i] != other.data[i]:
                return False
        return self.head == other.head and self.tail == other.tail and self.size == other.size

    # -----------MODIFY BELOW--------------

    def __str__(self):
        """
        Returns the string value of a CircularQueue object
        :return: string value of CircularQueue object
        """
        result = ''
        start = self.head
        for i in range(self.size - 1):
            result += str(self.data[start]) + ', '
            start = (start + 1) % self. capacity
        result += str(self.data[start])
        return result

    def is_empty(self):
        """
        Returns whether or not the queue is empty
        :return: bool representing empty or not
        """
        return self.size == 0

    def __len__(self):
        """
        Returns size of the queue
        :return: size of the queue
        """
        return self.size

    def first_value(self):
        """
        Returns but does not remove the first value of the queue
        :return: first value of the queue
        """
        return self.data[self.head]

    def enqueue(self, val):
        """
        Adds value val to back of the queue
        :param val: value to be added to the queue
        :return: none
        """
        self.data[self.tail] = val
        self.tail = (self.tail + 1) % self.capacity
        self.size += 1
        if self.size == len(self.data):
            self.grow()

    def dequeue(self):
        """
        Removes and returns first value of queue
        :return: first value of the queue
        """
        if self.is_empty():
            return None
        result = self.data[self.head]
        self.data[self.head] = None
        self.size -= 1
        self.head = (self.head + 1) % self.capacity
        if self.size <= self.capacity // 4:
            self.shrink()
        return result

    def grow(self):
        """
        Grows underlying list to double it's size
        :return: none
        """
        old = self.data
        self.capacity *= 2
        self.data = [None] * self.capacity
        count = self.head
        for i in range(self.size):
            self.data[i] = old[count]
            count = (count + 1) % len(old)
        self.head = 0
        self.tail = self.size

    def shrink(self):
        """
        Shrinks underlying list to half of it's size
        :return: none
        """
        if self.capacity == 4:
            return
        old = self.data
        self.capacity = self.capacity // 2
        self.data = [None] * self.capacity
        count = self.head
        for i in range(self.size):
            self.data[i] = old[count]
            count = (count + 1) % len(old)
        self.head = 0
        self.tail = self.size
