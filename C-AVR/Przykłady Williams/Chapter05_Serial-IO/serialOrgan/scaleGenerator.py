# scaleGenerator.py
# Skala wyznaczana jest w powtórzeniach na cykl (długość fali)
#   a nie w wysokości dźwięku.
# 

import math

SCALE = ['C', 'Cx', 'D', 'Dx', 'E', 'F', 'Fx', 'G', 'Gx', 'A', 'Ax', 'B']

def calculateOctave(baseLength):
    wavelengths = [baseLength / math.exp(x*math.log(2)/12) for x in range(0, 12)]
    wavelengths = [int(round(x)) for x in wavelengths]
    return( zip(SCALE, wavelengths) )

def makePitches(basePitch, numOctaves):
    pitchList = []
    for octave in range(0, numOctaves):
        for note, wavelength in calculateOctave(basePitch / 2**octave):
            if wavelength < 65500:
                noteString = note + str(octave)
                pitchList.append((noteString,wavelength))
    return(pitchList)            
    
def makeDefines(basePitch, numOctaves):
    pitchList = makePitches(basePitch, numOctaves)
    defineString = "// Skala dla klucza o wartości {} \n".format(basePitch)
    defineString += "// Automatycznie generowane przez scaleGenerator.py \n\n"
    for (note, length) in pitchList:
        defineString += "#define  {:<5}{:>6}\n".format(note, length)
    return(defineString)

if __name__ == "__main__":
    
    ## Zmień te wartości jeżeli masz ochotę
    BASEPITCH = 25000
    OCTAVES   = 8
    OUTFILE   = "scale16.h"
    
    ## Zapis wszystko do pliku
    out = open(OUTFILE, "w")
    out.write(makeDefines(BASEPITCH, OCTAVES))
    out.close()

    


