import myModule


favWebSites=["www.facebook.com","www.google.com","www.youtube.com","www.drive.com","www.fotmob.com","www.anghami.com"]

print(favWebSites)
Website=int(input("please enter the needed website 0>>>>5"))
myModule.firefox(favWebSites[Website],new=True)
