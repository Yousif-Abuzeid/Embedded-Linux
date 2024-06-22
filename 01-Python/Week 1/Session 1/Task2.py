def isVowel(ch):
    """
    Function Checks if a given Character is a vowel

    Parameters:
    ch(char): Character to be checked

    Returns:
    boolean
    """

    if ch in['e','o','a','i','u','E','O','A','I','U']: 
        return True
    else:
        return False
    
print(isVowel('l'))