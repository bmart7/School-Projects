class HashNode:
    """
    DO NOT EDIT
    """
    def __init__(self, key, value):
        self.key = key
        self.value = value
    def __repr__(self):
        return "HashNode({self.key}, {self.value})"

class HashTable:
    """
    Hash table class, utilizes double hashing for conflicts
    """

    def __init__(self, capacity=4):
        """
        DO NOT EDIT
        Initializes hash table
        :param tableSize: size of the hash table
        """
        self.capacity = capacity
        self.size = 0
        self.table = [None]*capacity


    def __eq__(self, other):
        """
        DO NOT EDIT
        Equality operator
        :param other: other hash table we are comparing with this one
        :return: bool if equal or not
        """
        if self.capacity != other.capacity or self.size != other.size:
            return False
        for i in range(self.capacity):
            if self.table[i] != other.table[i]:
                return False
        return True


    def __repr__(self):
        pass


    def hash_function(self, x):
        """
        ---DO NOT EDIT---

        Converts a string x into a bin number for our hash table
        :param x: key to be hashed
        :return: bin number to insert hash item at in our table, -1 if x is an empty string
        """
        if not x:
            return -1
        hashed_value = 0

        for char in x:
            hashed_value = 181 * hashed_value + ord(char)

        return hashed_value % self.capacity


    def insert(self, key, value):
        """
        Inserts key(string) and value(string) into the HashTable using a HashNode
        :param key: unique string to identify element
        :param value: value of element
        :return: none
        """
        if key == "" or key is None:
            return

        bucket = self.quadratic_probe(key)
        if self.table[bucket] is None or self.table[bucket] is False:
            self.table[bucket] = HashNode(key, value)
            self.size += 1
        elif self.table[bucket].key == key:
            self.table[bucket].value = value

        if self.size / float(self.capacity) > 0.75:
            self.grow()

    def quadratic_probe(self, key):
        """
        Runs the quadratic hashing procedure
        :param key: unique string to identify element
        :return: -1 if key is invalid, otherwise returns bucket index of present node or next available
        """
        if key == "" or key is None:
            return -1

        successor_found = False
        successor = None
        bucket = self.hash_function(key)
        for i in range(len(self.table)):
            bucket = (bucket + i * i) % self.capacity

            if self.table[bucket] is None:
                if successor_found is False:
                    successor = bucket
                break
            elif self.table[bucket] is False:
                if successor_found is False:
                    successor = bucket
                    successor_found = True
                continue
            elif self.table[bucket].key == key:
                return bucket

        return successor


    def find(self, key):
        """
        Searches for key in HashTable and returns node of element
        :param key: unique string to identify element
        :return: node of element in HashTable with Key or False if not found
        """
        if key == "" or key is None or self.size == 0:
            return False

        bucket = self.quadratic_probe(key)
        if self.table[bucket] is None or self.table[bucket] is False:
            return False
        if self.table[bucket].key == key:
            return self.table[bucket]

        return False


    def lookup(self, key):
        """
        Searches for key in HashTable and returns value of element
        :param key: unique string to identify element
        :return: value of element in HashTable with Key or False if not found
        """
        if key == "" or key is None or self.size == 0:
            return False

        node = self.find(key)
        if node is False:
            return False
        return node.value

    def delete(self, key):
        """
        Searches HashTable for key and removes element if found
        :param key: unique string to identify element
        :return: none
        """
        if key == "" or key is None or self.size == 0:
            return

        bucket = self.quadratic_probe(key)
        if self.table[bucket] is None or self.table[bucket] is False:
            return
        if self.table[bucket].key == key:
            self.table[bucket] = False
            self.size -= 1

    def grow(self):
        """
        Doubles the capacity of the HashTable and rehashes
        :return: none
        """
        old = self.table
        self.capacity *= 2
        self.table = [None]*self.capacity
        for i in range(len(old)):
            self.table[i] = old[i]
        self.rehash()

    def rehash(self):
        """
        Rehashes all elements of HashTable
        :return: none
        """
        old = self.table
        self.table = [None]*self.capacity
        self.size = 0
        for x in old:
            if x is not None and x is not False:
                self.insert(x.key, x.value)


def string_difference(string1, string2):
    """
    Takes in two strings, uses hash tables to get the difference of characters from the strings
    :param string1: first string to be evaluated
    :param string2: second string to be evaluated
    :return: Set of strings containing the separated characters of the differed amounts
    """
    alpha_table1 = HashTable()
    alpha_table2 = HashTable()
    for i in range(26):
        alpha_table1.insert(chr(ord('a') + i), 0)
        alpha_table2.insert(chr(ord('a') + i), 0)
    for x in string1:
        count = alpha_table1.lookup(x)
        alpha_table1.insert(x, count+1)
    for x in string2:
        count = alpha_table2.lookup(x)
        alpha_table2.insert(x, count + 1)

    result = set()
    for i in range(26):
        current = chr(ord('a') + i)
        count1 = alpha_table1.lookup(current)
        count2 = alpha_table2.lookup(current)
        diff = abs(count1 - count2)
        if diff != 0:
            result.add(current*diff)

    return result
