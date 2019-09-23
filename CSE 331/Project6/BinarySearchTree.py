class Node:
    # DO NOT MODIFY THIS CLASS #
    __slots__ = 'value', 'parent', 'left', 'right'

    def __init__(self, value, parent=None, left=None, right=None):
        """
        Initialization of a node
        :param value: value stored at the node
        :param parent: the parent node
        :param left: the left child node
        :param right: the right child node
        """
        self.value = value
        self.parent = parent
        self.left = left
        self.right = right

    def __eq__(self, other):
        """
        Determine if the two nodes are equal
        :param other: the node being compared to
        :return: true if the nodes are equal, false otherwise
        """
        if type(self) is not type(other):
            return False
        return self.value == other.value

    def __str__(self):
        """String representation of a node by its value"""
        return str(self.value)

    def __repr__(self):
        """String representation of a node by its value"""
        return str(self.value)


class BinarySearchTree:

    def __init__(self):
        # DO NOT MODIFY THIS FUNCTION #
        """
        Initializes an empty Binary Search Tree
        """
        self.root = None
        self.size = 0

    def __eq__(self, other):
        """
        Describe equality comparison for BSTs ('==')
        :param other: BST being compared to
        :return: True if equal, False if not equal
        """
        if self.size != other.size:
            return False
        if self.root != other.root:
            return False
        if self.root is None or other.root is None:
            return True  # Both must be None

        if self.root.left is not None and other.root.left is not None:
            r1 = self._compare(self.root.left, other.root.left)
        else:
            r1 = (self.root.left == other.root.left)
        if self.root.right is not None and other.root.right is not None:
            r2 = self._compare(self.root.right, other.root.right)
        else:
            r2 = (self.root.right == other.root.right)

        result = r1 and r2
        return result

    def _compare(self, t1, t2):
        """
        Recursively compares two trees, used in __eq__.
        :param t1: root node of first tree
        :param t2: root node of second tree
        :return: True if equal, False if nott
        """
        if t1 is None or t2 is None:
            return t1 == t2
        if t1 != t2:
            return False
        result = self._compare(t1.left, t2.left) and self._compare(t1.right, t2.right)
        return result

    ### Implement/Modify the functions below ###

    def insert(self, value):
        """
        Inserts value 'value' as a node in the tree
        :param value: value to be inserted into the tree
        :return: none
        """
        if self.size == 0:
            self.root = Node(value)
            self.size += 1
        else:
            current = self.root
            while current is not None:
                if value < current.value:
                    if current.left is None:
                        current.left = Node(value, current)
                        self.size += 1
                        current = None
                    else:
                        current = current.left
                elif value > current.value:
                    if current.right is None:
                        current.right = Node(value, current)
                        self.size += 1
                        current = None
                    else:
                        current = current.right
                else:
                    current = None

    def remove(self, value):
        """
        Searches and removes node with value 'value' in tree
        :param value: value to be removed from tree
        :return: none
        """
        current = self.root
        while current is not None:
            if current.value == value:
                if current.left is None and current.right is None:
                    if current.parent is None:
                        self.root = None
                    elif current.parent.left == current:
                        current.parent.left = None
                    else:
                        current.parent.right = None
                    self.size -= 1
                    current = None
                elif current.left is None and current.right is not None:
                    if current.parent is None:
                        self.root = current.right
                        current.right.parent = None
                    elif current.parent.left == current:
                        current.parent.left = current.right
                        current.right.parent = current.parent
                    else:
                        current.parent.right = current.right
                        current.right.parent = current.parent
                    self.size -= 1
                    current = None
                elif current.right is None and current.left is not None:
                    if current.parent is None:
                        self.root = current.left
                        current.left.parent = None
                    elif current.parent.left == current:
                        current.parent.left = current.left
                        current.left.parent = current.parent
                    else:
                        current.parent.right = current.left
                        current.left.parent = current.parent
                    self.size -= 1
                    current = None
                else:
                    successor = current.right
                    while successor.left is not None:
                        successor = successor.left
                    current.value = successor.value
                    current = current.right
                    value = successor.value
            elif value < current.value:
                current = current.left
            else:
                current = current.right

    def search(self, value, node):
        """
        Searches and returns node containing value 'value' starting at root 'node'
        :param value: value to be found from root 'node'
        :param node: root node of tree or subtree to be searched
        :return: node containing 'value' or potential parent from root 'node'
        """
        if node is None:
            return None
        if node.value == value:
            return node
        if value < node.value:
            if node.left is None:
                return node
            else:
                return self.search(value, node.left)
        else:
            if node.right is None:
                return node
            else:
                return self.search(value, node.right)

    def inorder(self, node):
        """
        Returns a Generator Object of tree from root 'node' traversed using inorder method
        :param node: root node of tree or subtree to be traversed
        :return: Generator Object of tree traversed using indorder method
        """
        if self.size == 0:
            yield None
        if node.left is not None:
            for temp in self.inorder(node.left):
                yield temp
        yield node.value
        if node.right is not None:
            for temp in self.inorder(node.right):
                yield temp

    def preorder(self, node):
        """
        Returns a Generator Object of tree from root 'node' traversed using preorder method
        :param node: root node of tree or subtree to be traversed
        :return: Generator Object of tree traversed using preorder method
        """
        if self.size == 0:
            yield None
        yield node.value
        if node.left is not None:
            for temp in self.preorder(node.left):
                yield temp
        if node.right is not None:
            for temp in self.preorder(node.right):
                yield temp

    def postorder(self, node):
        """
        Returns a Generator Object of tree from root 'node' traversed using postorder method
        :param node: root node of tree or subtree to be traversed
        :return: Generator Object of tree traversed using postorder method
        """
        if self.size == 0:
            yield None
        if node.left is not None:
            for temp in self.postorder(node.left):
                yield temp
        if node.right is not None:
            for temp in self.postorder(node.right):
                yield temp
        yield node.value

    def preorder_node(self, node):
        """
        Returns a Generator Object of nodes from tree at root 'node' using preorder method
        :param node: root node of tree or subtree to be traversed
        :return: Generator Object of nodes from tree traversed using preorder method
        """
        if self.size == 0:
            yield None
        yield node
        if node.left is not None:
            for temp in self.preorder_node(node.left):
                yield temp
        if node.right is not None:
            for temp in self.preorder_node(node.right):
                yield temp

    def depth(self, value):
        """
        Returns depth of node containing value 'value'
        :param value: value of node to be processed
        :return: depth of node containing value 'value'
        """
        if self.size == 0:
            return -1
        node = self.search(value, self.root)
        if node.value != value:
            return -1
        count = 0
        while node != self.root:
            node = node.parent
            count += 1
        return count

    def height(self, node):
        """
        Returns height of tree or subtree from root 'node'
        :param node: root node of tree or subtree
        :return: height of tree or subtree from root 'node'
        """
        if node is None:
            return -1
        left = self.height(node.left)
        right = self.height(node.right)
        return 1 + max(left, right)

    def min(self, node):
        """
        Returns node of the minimum value of tree rooted at 'node'
        :param node: root of tree or subtree to be searched
        :return: node containing minimum value from tree
        """
        if node is None:
            return None
        if node.left is not None:
            return self.min(node.left)
        else:
            return node

    def max(self, node):
        """
        Returns node of the maximum value of tree rooted at 'node'
        :param node: root of tree or subtree to be searched
        :return: node containing maximum value from tree
        """
        if node is None:
            return None
        if node.right is not None:
            return self.max(node.right)
        else:
            return node

    def get_size(self):
        """
        Returns number of nodes in tree
        :return: number of nodes in tree
        """
        return self.size

    def is_perfect(self, node):
        """
        Returns a boolean value if binary tree rooted at 'node' is perfect
        :param node: root of binary tree or subtree
        :return: boolean value if binary tree is perfect
        """
        if node is None or (node.left is None and node.right is None):
            return True
        left_count = 0
        right_count = 0
        for current in self.preorder_node(node):
            if current.left is not None and current.right is not None:
                if current.value < node.value:
                    left_count += 1
                elif current.value > node.value:
                    right_count += 1
            elif current.left is None and current.right is None:
                if current.value < node.value:
                    left_count += 1
                elif current.value > node.value:
                    right_count += 1
            else:
                return False
        if right_count != left_count:
            return False
        total = right_count + left_count + 1
        return pow(2, self.height(node)+1)-1 == total

    def is_degenerate(self):
        """
        Returns a boolean value if binary tree is degenerate
        :return: boolean value if binary tree is degenerate
        """
        if self.size == 0 or self.size == 1:
            return False
        for current in self.preorder_node(self.root):
            if current.left is not None and current.right is not None:
                return False
        return True
