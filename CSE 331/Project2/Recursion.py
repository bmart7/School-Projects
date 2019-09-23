"""
PROJECT 2 - Recursion
Name: Brian Martin
PID: A56350183
"""

from Project2.LinkedNode import LinkedNode


def insert(value, node=None):
    """
    Adds a node with value 'value' in ascending order to a list with head 'node' or creates a new list of length 1
    :param value: value to add to list
    :param node: head node of a list
    :return: head node of the list with inserted value
    """
    if node is None:

        temp = LinkedNode(value, None)
        return temp

    if node.value < value:

        if node.next_node is None or node.next_node.value >= value:

            temp = LinkedNode(value, node.next_node)
            node.next_node = temp
            return node

        if node.next_node.value < value:

            insert(value, node.next_node)
            return node

    else:

        temp = LinkedNode(value, node)
        return temp


def string(node):
    """
    Returns a string representation of the list with head 'node'
    :param node: head node of a list
    :return: string representation of the list with head 'node'
    """
    if node is None:

        return ''

    if node.next_node is None:

        return '%s' % node.value

    else:

        return '%s, ' % node.value + string(node.next_node)


def reversed_string(node):
    """
    Returns a string representation of the list with head 'node', in reverse order
    :param node: head node of a list
    :return: string representation of the list with head 'node', in reverse order
    """
    if node is None:

        return ''

    if node.next_node is not None:

        return reversed_string(node.next_node) + ', %s' % node.value

    else:

        return '%s' % node.value


def remove(value, node):
    """
    Removes first node with value 'value' from a list with head 'node'
    :param value: value to remove from list
    :param node: head node of a list
    :return: head node of the list with removed value
    """
    if node is None:

        return node

    if node.value == value:

        temp = node.next_node
        node.next_node = None
        return temp

    elif node.next_node is not None:

        if node.next_node.value == value:

            node.next_node = node.next_node.next_node
            return node

        else:

            remove(value, node.next_node)
            return node

    else:

        return node


def remove_all(value, node):
    """
    Removes all nodes with value 'value' from a list with head 'node'
    :param value: value to remove from list
    :param node: head node of a list
    :return: head node of the list with removed values
    """
    if node is None:

        return node

    if node.next_node is not None:

        if node.value == value:

            temp = node.next_node
            node.next_node = None
            return remove_all(value, temp)

        if node.next_node.value == value:

            if node.next_node.next_node is not None:

                temp = node.next_node.next_node
                node.next_node = None
                node.next_node = temp
                remove_all(value, node)
                return node

            else:

                node.next_node = None
                return node

        remove_all(value, node.next_node)
        return node

    else:

        if node.value == value:

            return None

        return node


def search(value, node):
    """
    Searches for first node with value 'value' from a list with head 'node'
    :param value: value to find in list
    :param node: head node of a list
    :return: boolean value if value is present in list
    """
    if node is None:

        return False

    if node.value == value:

        return True

    elif node.next_node is None:

        return False

    else:

        return search(value, node.next_node)


def length(node):
    """
    Calculates and returns length a list with head 'node'
    :param node: head node of a list
    :return: length of list with head 'node'
    """
    if node is None:

        return 0

    if node.next_node is None:

        return 1

    else:

        return 1 + length(node.next_node)


def sum_all(node):
    """
    Calculates and returns sum of all node values in a list with head 'node'
    :param node: head node of a list
    :return: sum of all node values in a list with head 'node'
    """
    if node is None:

        return 0

    if node.next_node is None:

        return node.value

    else:

        return node.value + sum_all(node.next_node)


def count(value, node):
    """
    Calculates and returns amount of nodes with value 'value' from a list with head 'node'
    :param value: value to find in list
    :param node: head node of a list
    :return: amount of nodes with value 'value' from a list with head 'node'
    """
    if node is None:

        return 0

    if node.next_node is not None:

        if node.value == value:

            return 1 + count(value, node.next_node)

        else:

            return count(value, node.next_node)

    else:

        if node.value == value:

            return 1

        else:

            return 0


