import pyautogui
import keyboard
import time

def auto_clicker():
    """Clicks the mouse rapidly until 'q' is pressed."""
    clicking = False
    print("Press 's' to start clicking, 'q' to stop.")

    while True:
        if keyboard.is_pressed('s'):
            if not clicking:
              clicking = True
              print("Clicking started!")
              time.sleep(0.5) # small delay to prevent rapid start/stop

        if keyboard.is_pressed('q'):
            if clicking:
              clicking = False
              print("Clicking stopped!")
              time.sleep(0.5)  # small delay to prevent rapid start/stop

        if clicking:
            pyautogui.click()  # Perform a mouse click
            time.sleep(0.1) # Adjust for click speed (smaller = faster)

        time.sleep(0.001) # tiny delay to reduce cpu load.

if __name__ == "__main__":
    auto_clicker()