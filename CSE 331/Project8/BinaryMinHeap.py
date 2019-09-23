########################################
# PROJECT: Binary Min Heap and Sort
# Author: Brian Martin
########################################

class BinaryMinHeap:
    # DO NOT MODIFY THIS CLASS #
    def __init__(self):
        """
        Creates an empty hash table with a fixed capacity
        """
        self.table = []


    def __eq__(self, other):
        """
        Equality comparison for heaps
        :param other: Heap being compared to
        :return: True if equal, False if not equal
        """
        if len(self.table) != len(other.table):
            return False
        for i in range(len(self.table)):
            if self.table[i] != other.table[i]:
                return False

        return True

    ###### COMPLETE THE FUNCTIONS BELOW ######

    def __str__(self):
        return str(self.table)

    def get_size(self):
        """
        Returns number of nodes currently in heap
        :return: number of nodes currently in heap
        """
        return len(self.table)

    def parent(self, position):
        """
        Finds the index of the parent of the node at index position
        :param position: index of node to find parent for
        :return: index of the parent of node at index
        """
        return (position - 1) // 2 if position != 0 else 0

    def left_child(self, position):
        """
        Finds the index of the left child of the node at index position
        :param position: index of node to find left child for
        :return: index of the left child of node at index
        """
        return (position * 2) + 1

    def right_child(self, position):
        """
        Finds the index of the right child of the node at index position
        :param position: index of node to find right child for
        :return: index of the right child of node at index
        """
        return (position * 2) + 2

    def has_left(self, position):
        """
        Returns boolean value if node at index position has existing left child
        :param position: position of node to be evaluated
        :return: boolean value if node at index position has existing left child
        """
        if position >= 0:
            return (position * 2) + 1 < len(self.table) and self.table[(position * 2) + 1] is not None
        else:
            return False

    def has_right(self, position):
        """
        Returns boolean value if node at index position has existing right child
        :param position: position of node to be evaluated
        :return: boolean value if node at index position has existing right child
        """
        if position >= 0:
            return (position * 2) + 2 < len(self.table) and self.table[(position * 2) + 2] is not None
        else:
            return False

    def find(self, value):
        """
        Returns index of node with value
        :param value: value to be searched
        :return: index of node with value
        """
        for i in range(len(self.table)):
            if self.table[i] == value:
                return i
        return None

    def heap_push(self, value):
        """
        Adds node with given value to heap
        :param value: value to be added to heap
        :return: none
        """
        if value not in self.table:
            self.table.append(value)
            self.percolate_up(len(self.table)-1)

    def heap_pop(self, value):
        """
        Removes node with given value from heap
        :param value: value to be removed
        :return: none
        """
        for i in range(len(self.table)):
            if self.table[i] == value:
                self.swap(i, len(self.table)-1)
                self.table.pop(len(self.table)-1)
                if i < len(self.table) > 1:
                    if self.table[self.parent(i)] > self.table[i]:
                        self.percolate_up(i)
                    else:
                        self.percolate_down(i)
                break

    def pop_min(self):
        """
        Removes and returns minimum node in heap
        :return: minimum node in heap
        """
        result = None
        if len(self.table) == 1:
            return self.table.pop(0)
        if len(self.table) > 0:
            result = self.table[0]
            self.table[0] = self.table.pop(len(self.table)-1)
            self.percolate_down(0)
        return result


    def swap(self, p1, p2):
        """
        Swaps values of heap at indices p1 and p2
        :param p1: first index of value to be swapped
        :param p2: second index of value to be swapped
        :return: none
        """
        temp = self.table[p1]
        self.table[p1] = self.table[p2]
        self.table[p2] = temp

    def percolate_up(self, position):
        """
        Moves node at index position up the tree until it is in the proper place
        :param position: index of node to be evaluated
        :return: none
        """
        while position >= 1:
            parent = (position - 1) // 2
            if self.table[parent] <= self.table[position]:
                return
            else:
                self.swap(position, parent)
                position = parent

    def percolate_down(self, position):
        """
        Moves node at index position down the tree until it is in the proper place
        :param position: index of node to be evaluated
        :return: none
        """
        while position < len(self.table):
            child = (position * 2) + 1
            min = position
            i = 0
            while i < 2 and i + child < len(self.table):
                if self.table[i + child] < self.table[min]:
                    min = i + child
                i += 1

            if self.table[min] == self.table[position]:
                return
            else:
                self.swap(position, min)
                position = min

def heap_sort(unsorted):
    """
    Performs heap sort on an unsorted list
    :param unsorted: list to be sorted
    :return: sorted list
    """
    heap = BinaryMinHeap()
    for x in unsorted:
        heap.heap_push(x)
    result = []
    while heap.get_size() > 0:
        result.append(heap.pop_min())
    return result
