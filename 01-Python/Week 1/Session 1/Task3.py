import os

def getEnvironmentVariable(varName):
    """
    Returns the value of the specified environment variable.
    If the environment variable does not exist, prints an error message.

    Parameters:
    varName(str): the name of environment variable to retrieve

    Returns:
    The value of the specified environment variable

    """
    try :
        value=os.environ[varName]
        return f"{varName}:{value}"
    except KeyError:
        print(f"Environment Variable {varName} is Not Found")
        return None

# Example 
# List of environment variables you want to check
env_vars = ['HOME', 'PATH', 'USER', 'SHELL']
for var in env_vars:
    print(getEnvironmentVariable(var))


