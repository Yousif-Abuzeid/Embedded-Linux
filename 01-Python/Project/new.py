import os
import time

def switch_to_application(app_name):
    os.system(f"xdotool search --onlyvisible --classname '{app_name}' windowactivate --sync")
    time.sleep(0.5)  # Optional: add a small delay to ensure activation
    print(f"Switched to {app_name}.")

# Example usage
switch_to_application("code")   # Replace with the actual class name for VSCode
switch_to_application("firefox")   # Replace with the actual class name for Firefox
