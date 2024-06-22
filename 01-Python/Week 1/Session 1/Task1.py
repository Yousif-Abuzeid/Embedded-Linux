def countFour(ls):
    """
    Function to count occurrences of the number 4 in a given list.

    Parameters:
    ls (list): A list of integers where occurrences of the number 4 will be counted.

    Returns:
    int: The number of times the integer 4 appears in the list `ls`.
    """
    return ls.count(4)

# Example usage:
ls = [1, 23, 3, 5, 4, 5, 6, 4, 7, 7]
print(countFour(ls))
