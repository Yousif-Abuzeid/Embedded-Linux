import calendar
from datetime import datetime
def printCal(year=datetime.now().year,month=datetime.now().month):
    """
    Function to print the calender of specific year and month

    Parameters:
    year(int) :  year wanted. if not defined it will have a default value of current year
    month(int):  month wanted. if not defined it will have a default value of current month

    Return:
    None
    """
    if month<0 or month>12:
        raise ValueError("Month should be between 0 and 12")
    if year<0:
        raise ValueError("Year can't be negative")
    print(calendar.month(year,month))

# Example
printCal(2000,11)

# Example with default values
printCal()