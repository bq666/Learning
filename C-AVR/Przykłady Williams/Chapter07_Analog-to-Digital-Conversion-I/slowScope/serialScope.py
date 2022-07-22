import serial

def readValue(serialPort):
    return(ord(serialPort.read(1)))

def plotValue(value):
    """ Wyświetla wartość na skalowanych i przewijanych słupkach"""
    leadingSpaces = " " * (value*(SCREEN_WIDTH-3) / 255)
    print "%s%3i" % (leadingSpaces, value)

def cheapoScope(serialPort):
    while(1):
	newValue = readValue(serialPort)
	plotValue(newValue)
        

if __name__ == "__main__":
    
    PORT = '/dev/ttyUSB0'
    BAUDRATE =  9600
    TIMEOUT = None
    SCREEN_WIDTH = 80

    ## Parametry wiersza poleceń zastępują domyślne wartości
    import sys
    if len(sys.argv) == 3:
        port = sys.argv[1]
        baudrate = int(sys.argv[2])
    else:            # brak parametrów, używamy wartości domyślnych
	print ("Domyślne wartości dla opcjonalnych parametrów nazwy portu i szybkości transmisji.")
	port, baudrate = (PORT, BAUDRATE)
        
    serialPort = serial.Serial(port, baudrate, timeout=TIMEOUT)
    serialPort.flush()
    cheapoScope(serialPort)



    



  

