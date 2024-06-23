import requests
import pprint
def getYourLocation():
    """
    Function to get your geographical location using your public ip

    Parameters:
    None

    Returns:
    json with your location and data
    """
    ip=requests.get("https://api.ipify.org/?format=json")
    dict_ip=ip.json()
    print(dict_ip['ip'])
    Geo_loc=requests.get(f"https://ipinfo.io/{dict_ip['ip']}/geo")
    return Geo_loc.json();


loc=getYourLocation()
print(loc)
# pprint(getYourLocation())

