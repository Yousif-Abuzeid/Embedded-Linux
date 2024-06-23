import webbrowser

def firefox(url,new=False):
    """
    Function that opens firefox with a specific website

    Parameters :
    url(str): Link to website example:www.facebook.com

    Returns:
    None
    """
    firefox=webbrowser.get('firefox')
    if new==False:
        firefox.open(url)
    else:
        firefox.open_new(url)
