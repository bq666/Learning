## Prosty program demonstracyjny
## W nieskończoność nasłuchuje na porcie szeregowym
## Po naciśnięciu przycisku, otwiera wybraną stronę WWW.
## Rozbuduj go o obslugę wielu przycisków, a uzyskasz fizyczny
## sposób otwierania różnych stron internetowych.

BOSS_SITE = "http://www.cartalk.com/content/boss-redirect"
## a może coś bardziej w temacie...
XKCD = "http://xkcd.com/353/"

SERIAL_PORT = "/dev/ttyUSB0"
BAUD_RATE = 9600

import serial
import webbrowser

sp = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout = 5)
sp.flush()
print ("Boss Button")

while(1):                       # czekaj w nieskończoność
    response = sp.read(1)       # pobierz jeden bajt
    if response == "O":
        print "Odebrano potwierdzenie, czekam na przycisk."
    elif response == "X":
        print "Uwaga Szef!  Alarm!"
        webbrowser.open(BOSS_SITE)
    else:
        print "Nic nie ma.  Czekam dalej."


