import time
import serial

def readTime(serialPort):
    '''Odczytuje czas z ukladu AVR przez port szeregowy'''
    serialPort.flushInput()
    character = ""
    while(not character == "\n"):     # czekaj w pętli na znak końca wiersza
        character = serialPort.read(1)
    ## Ciąg znaków z czasem ma następujący format: '011:045:023\r\n'
    timeString = serialPort.read(13) 
    hms = timeString.split(":")
    hms = [int(x) for x in hms] # zapisz liczbowo godziny, minuty i sekundy
    return(hms)

def setTime(serialPort, hours, minutes, seconds):
    '''Wysyła nastawę czasu przez port szeregowy'''
    serialPort.flushOutput()
    serialPort.write("S")
    time.sleep(0.1)             # czekaj podczas gdy układ AVR nadaje
    serialPort.write(str(hours) + "\r")
    time.sleep(0.2)             # czekaj podczas gdy układ AVR nadaje
    serialPort.write(str(minutes) + "\r")
    time.sleep(0.2)             # czekaj podczas gdy układ AVR nadaje
    serialPort.write(str(seconds) + "\r")
    
def setTimeNow(serialPort):
    '''Ustala aktualny czas w zegarze mikroprocesorowym'''
    hours, minutes, seconds = time.localtime()[3:6]    
    setTime(serialPort, hours, minutes, seconds)
    return(time.time())

def calculateTimeDelay(serialPort):
    '''Pobiera czas z układu AVR i odejmuje od niego aktualny czas (z komputera)'''
    avrHMS = readTime(serialPort)
    hms = time.localtime()[3:6]
    hmsDifference = [x - y for x,y in zip(avrHMS, hms)]
    out = "AVR spieszy o: {x[0]} godzin, {x[1]} minut, and {x[2]} sekund"
    print out.format(x=hmsDifference)
    return(hmsDifference)

def calculateTimeDrift(serialPort, startTime):
    '''Wylicza współczynnik do pomnożenia wartości OVERFLOWS_PER_SECOND 
    przyjmując czas początkowy i aktualną różnicę'''
    h, m, s = calculateTimeDelay(serialPort)
    driftSeconds = 60*60*h + 60*m + s
    elapsed = time.time() - startTime
    print "Po {:.0f} sekundach, ".format(elapsed)
    return (driftSeconds / elapsed + 1)
 

if __name__ == "__main__":
    
    ## Automatycznie ustawia czas, zapamiętuje czas uruchomienia, 
    ##  i cyklicznie wylicza współczynnik korygujący
    OVERFLOWS_PER_SECOND = 31250 # tutaj wpisz wartość ze swojego kodu
    
    SLEEP_TIME = 10            
    ratioLog = []

    s = serial.Serial("/dev/ttyUSB0", 9600, timeout=5)
    print "Ustalanie czasu na aktualny...."
    ratio = 0
    while not ratio == 1:       # Upewnij się, że czas uruchomienia jest właściwy
        startTime = setTimeNow(s) 
        ratio = calculateTimeDrift(s, startTime)

    ## Uwaga: możesz pozwolić programowi pracować albo
    ## w dowolnym momencie uruchomić ponownie funkcję calculateTimeDrift(), 
    ## pod warunkiem, że nie zmienić początkowej wartości zmiennej startTime 
    while(True):
        ratio = calculateTimeDrift(s, startTime)
        ratioLog.append([time.time()-startTime, ratio])
        newOverflow = int(OVERFLOWS_PER_SECOND * ratio)
        print "Zmienna OVERFLOWS_PER_SECOND powinna mieć wartość {}\n\n".format(newOverflow)
        time.sleep(SLEEP_TIME)
        
    ## Po uruchomieniu tego programu zobaczysz, że na początku często zmienia
	##  podawaną wartość, ale po kilku godzinach powinna się ona ustabilizwać.
	##  Co ciekawe, znacznie szybciej przyjmie swoją ostateczną wartośc, jeżeli
	##  początkowo zegar był mocno rozsynchronizowany. (Skoro ma większą odchyłkę,
	##  to można szybciej wyznaczyć jej wielkość.)
	## Pozwól programowi działać przez 24 godziny, a uzyskasz dokładność zegara
	##  do jednej sekundy dziennie.