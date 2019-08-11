## Skrypt w języku Python do sterowania organami przez port szeregowy

## Sam "protokół" jest prosty.
## Python wysyła nutę, czeka na potwierdzenie, wysyła następną itd.
## Organy nasłuchują kolejnych nut, a po ich otrzymaniu wysyłają znak 'N' oznaczający gotowość.
 
import serial

def playString(noteString, serialPort):
  for letter in noteString:
    print letter
    serialPort.write(letter)
    returnValue = serialPort.read(1)
    
if __name__ == "__main__":

  import time, urllib2

  ## Inne ustawienia są niezbędne w systemach Mac / Windows
  PORT = "/dev/ttyUSB0"
  BAUD = 9600

  s = serial.Serial(PORT, BAUD)
  s.flush()                     
  ## Instrukcja flush czyści bufor, co pozwala na czysty start
  ## Więcej o buforach portu szeregowego za chwilę.

  ## Przykład międzynarodowy. Możesz z niego skorzystać do celowego odtwarzania muzyki.
  playString("f g h j k l ; ]'[", s)
  raw_input("Naciśnij enter, żeby odtworzyć kolejną melodię\n")

  ## Trochę niemądry przykład. Możesz wpisać dowolny tekst i sprawdzić jak zabrzmi.
  playString("witam wszystkicj, to dowolny ciag znakow zmieniony w 'muzyke'", s)
  raw_input("Naciśnij enter, żeby odtworzyć kolejną melodię\n")

  ## Dość frywolny przykład.  Odtwarzanie stron WWW!
  ## Dodatkowe punkty dla pierwszej osoby, która sobie tweetnie piosenkę.
  print ("Pobieranie danych ze strony http://serialorgansongs.jottit.com/...")
  import re
  contentFilter = re.compile(r'<p>(.*?)</p>')
  songSite = urllib2.urlopen("http://serialorgansongs.jottit.com/").read()
  songText = contentFilter.findall(songSite)[0]
  playString(songText, s)
 
  ## albo praca interaktywna
  mySong = raw_input("\nWpisz swój własny utwór: ")
  playString(mySong, s)
  
  

 

  
  
  
