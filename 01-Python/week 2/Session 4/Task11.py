from pynotifier import Notification
import psutil

battery = psutil.sensors_battery()
percent = battery.percent

print(percent)

Notification(title="Battery %", description=str(percent)+ "% Remaining",duration=10).send()