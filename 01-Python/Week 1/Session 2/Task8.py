import pyautogui
import time
import os

# Function to press a combination of keys
def press_keys(*keys):
    for key in keys:
        pyautogui.keyDown(key)
    time.sleep(0.1)
    for key in keys:
        pyautogui.keyUp(key)

# Function to type text
def type_text(text):
    pyautogui.typewrite(text)
    time.sleep(2)  # Wait for 2 seconds to ensure the text is typed

# Function to locate an image on the screen with confidence level
def locate_image(image_path, confidence_level=0.7):
    return pyautogui.locateOnScreen(image_path, confidence=confidence_level)

# Function to click on the center of the located image
def click_on_image(image_path, confidence_level=0.7, offset=(0, 0)):
    image_location = locate_image(image_path, confidence_level)
    if image_location:
        center_x, center_y = pyautogui.center(image_location)
        pyautogui.click(center_x + offset[0], center_y + offset[1])
        return center_x, center_y
    else:
        print(f"Cannot find image: {image_path}")
        return None

# Main script execution
def main():
    # Get the directory of the current script
    script_dir = os.path.dirname(os.path.realpath(__file__))

    # Press Ctrl+Shift+X
    press_keys('ctrl', 'shift', 'x')

    # Select all and delete
    pyautogui.hotkey('ctrl', 'a')
    pyautogui.press('backspace')

    # Type "clangd"
    type_text("clangd")

    # Locate and click on 'clangd.png'
    clangd_image_path = os.path.join(script_dir, 'clangd.png')
    clangd_location = click_on_image(clangd_image_path, confidence_level=0.7)

    if clangd_location:
        print(f"Clangd image found at: {clangd_location}")
        time.sleep(1)  # Wait for 1 second

        # Locate and click on 'install.png' with an offset adjustment
        install_image_path = os.path.join(script_dir, 'install.png')
        install_location = click_on_image(install_image_path, confidence_level=0.6, offset=(-114, 63))

        if install_location:
            print(f"Install image found at: {install_location}")
    else:
        print("Cannot find clangd image")

# Run the main function
if __name__ == "__main__":
    main()
