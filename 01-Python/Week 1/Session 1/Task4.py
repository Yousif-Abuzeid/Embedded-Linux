import math
def CalcArea(radius):
    """
    Function to calculate the area of a circle

    Parameters:
    radius(float): radius of the circle to calculate the area

    Returns:
    float: Returns the area of the circle

    """
    

    return math.pi*radius**2

# Example

r=3
print(CalcArea(r))
