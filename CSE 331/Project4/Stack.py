"""
# Project 4
# Name: Brian Martin
# PID: A56350138
"""


class Stack:
    """
    Stack class
    """
    def __init__(self, capacity=2):
        """
        DO NOT MODIFY
        Creates an empty Stack with a fixed capacity
        :param capacity: Initial size of the stack. Default size 2.
        """
        self.capacity = capacity
        self.data = [None] * self.capacity
        self.size = 0

    def __str__(self):
        """
        DO NOT MODIFY
        Prints the values in the stack from bottom to top. Then, prints capacity.
        :return: string
        """
        if self.size == 0:
            return "Empty Stack"

        output = []
        for i in range(self.size):
            output.append(str(self.data[i]))
        return "{} Capacity: {}".format(output, str(self.capacity))

    def __eq__(self, stack2):
        """
        DO NOT MODIFY
        Checks if two stacks are equivalent to each other. Checks equivalency of data and capacity
        :return: True if equal, False if not
        """
        if self.capacity != stack2.capacity:
            return False

        count = 0
        for item in self.data:
            if item != stack2.data[count]:
                return False
            count += 1

        return True

    def stack_size(self):
        """
        Returns the current number of items in the stack.
        :return: Number of items in the stack
        """
        return self.size

    def is_empty(self):
        """
        Returns True if the stack is empty, False if not.
        :return: Truth value of the stack being empty
        """
        return self.size == 0

    def top(self):
        """
        Returns but does not remove the top value of the stack.
        :return: Top value of the stack
        """
        if self.is_empty():

            return None

        return self.data[self.size-1]

    def push(self, val):
        """
        Adds value val to the top of the stack.
        :param val: value to be added to the stack
        :return: no return
        """
        if self.size == self.capacity:

            self.grow()

        self.data[self.size] = val
        self.size += 1

    def pop(self):
        """
        Removes and returns the top value of the stack.
        :return: Value of removed element
        """
        if self.is_empty():

            return None

        temp = self.data[self.size-1]
        self.data[self.size-1] = None
        self.size -= 1
        if self.size <= self.capacity // 2:

            self.shrink()

        return temp

    def grow(self):
        """
        Double the size of the stack when the size is equal to the capacity.
        :return: no return
        """
        if self.size == self.capacity:

            self.capacity *= 2
            result = [None] * self.capacity
            for i in range(len(self.data)):

                result[i] = self.data[i]

            self.data = result

    def shrink(self):
        """
        Resizes the stack to half of the current size if the size is less than half the capacity.
        :return: no return
        """
        if self.size <= self.capacity // 2 and self.capacity // 2 >= 2:

            self.capacity = self.capacity // 2
            result = [None] * self.capacity
            for i in range(len(result)):

                result[i] = self.data[i]

            self.data = result


def reverse(stack):
    """
    Reverses the order of the stack, stack, and returns it.
    :return: Stack, stack, in reverse order
    """
    if stack.size <= 1:

        return stack

    result = Stack(stack.capacity)
    for i in range(stack.stack_size()):

        result.push(stack.pop())

    stack = result
    return stack


def replace(stack, old, new):
    """
    Replaces all instances of value old in the stack, stack, with value new.
    :param stack: Stack with values to be replaced
    :param old: Value to be replaced
    :param new: Value to replace old value
    :return: Stack stack with replaced values
    """
    if stack.size == 0:

        return stack

    result = Stack(stack.capacity)
    for i in range(stack.stack_size()):

        temp = stack.pop()
        if temp == old:

            result.push(new)

        else:

            result.push(temp)

    stack = reverse(result)
    return stack


stk = Stack()
for i in range(10, 0, -1):
    stk.push(i)
    print(stk)
stk = reverse(stk)
print(stk)
