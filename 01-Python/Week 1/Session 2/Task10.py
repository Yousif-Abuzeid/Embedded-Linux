import pyautogui
import time
import myModule

# Function to press a combination of keys
def press_keys(*keys):
    for key in keys:
        pyautogui.keyDown(key)
    time.sleep(0.1)
    for key in keys:
        pyautogui.keyUp(key)


# Open Gmail using Firefox
myModule.firefox("www.gmail.com", new=True)

pyautogui.keyDown('alt')
pyautogui.press('tab')
pyautogui.keyUp('alt')

# Keyboard shortcut to select all emails
time.sleep(5)
selectAll = ['*', 'a']
press_keys(*selectAll)
time.sleep(1)

# Mark all selected emails as read
markAsRead = ['shift', 'i']
press_keys(*markAsRead)