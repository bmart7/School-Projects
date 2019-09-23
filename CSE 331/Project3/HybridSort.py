"""
PROJECT 3 - Hybrid Sort
Name: Brian Martin
PID: A56350183
"""


def merge_sort(unsorted, threshold, reverse):
    """
    Splits list 'unsorted' recursively until 'threshold' is met, then insertion sorts and returns the sorted list.
    :param unsorted: list of unsorted objects
    :param threshold: length of list to stop splitting at
    :param reverse: boolean causing sorting in decreasing order if True, increasing otherwise
    :return: list 'unsorted' in sorted order
    """
    if threshold < 1:

        threshold = 1

    if len(unsorted) > threshold:

        mid = len(unsorted) // 2
        first = unsorted[:mid]
        second = unsorted[mid:]
        first = merge_sort(first, threshold, reverse)
        second = merge_sort(second, threshold, reverse)

        result = merge(first, second, reverse)
        unsorted[:] = result

        return unsorted

    else:

        insertion_sort(unsorted, reverse)
        return unsorted


def merge(first, second, reverse):
    """
    Merges and sorts two lists 'first' and 'second' into one list that is returned.
    :param first: list of sorted object
    :param second: list of sorted objects
    :param reverse: boolean causing sorting in decreasing order if True, increasing otherwise
    :return: new sorted list containing all objects from lists 'first' and 'second'
    """
    first_pos = 0
    second_pos = 0
    result = []

    while first_pos < len(first) and second_pos < len(second):

        if first[first_pos] > second[second_pos]:

            if reverse:

                result.append(first[first_pos])
                first_pos += 1

            else:

                result.append(second[second_pos])
                second_pos += 1

        else:

            if reverse:

                result.append(second[second_pos])
                second_pos += 1

            else:

                result.append(first[first_pos])
                first_pos += 1

    while first_pos < len(first):

        result.append(first[first_pos])
        first_pos += 1

    while second_pos < len(second):

        result.append(second[second_pos])
        second_pos += 1

    return result


def insertion_sort(unsorted, reverse):
    """
    Sorts list 'unsorted' by iterating over the list and inserting the next object in the correct position behind the
    iterator position.
    :param unsorted: list of unsorted objects
    :param reverse: boolean causing sorting in decreasing order if True, increasing otherwise
    :return: list 'unsorted' in sorted order
    """
    for i in range(1, len(unsorted)):

        j = i

        if reverse:

            while j > 0 and unsorted[j] > unsorted[j-1]:

                temp = unsorted[j-1]
                unsorted[j-1] = unsorted[j]
                unsorted[j] = temp
                j -= 1

        else:

            while j > 0 and unsorted[j] < unsorted[j-1]:

                temp = unsorted[j-1]
                unsorted[j-1] = unsorted[j]
                unsorted[j] = temp
                j -= 1

    return unsorted
