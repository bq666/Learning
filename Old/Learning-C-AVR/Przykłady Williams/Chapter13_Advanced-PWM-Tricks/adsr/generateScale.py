
## Plik generujący wyrównaną skalę dla syntezatora DDS


import math                     # bo muzyka to matematyka

scale = ['C', 'Cx', 'D', 'Dx', 'E', 'F', 'Fx', 'G', 'Gx', 'A', 'Ax', 'B']

def octave(baseLength):
    pitches = [baseLength * math.exp(x*math.log(2)/12) for x in range(0, 12)]
    pitches = [int(round(x)) for x in pitches]
    return( zip(scale, pitches) )


def writeScaleHeader(basePitch, octaves, filename="scale.h"):
    outfile = open(filename, "w")
    outfile.write('''/*

    Skala używana przez syntezator DDS.

    Przygotowana tak, żeby A2 miało 440Hz,
    przy układzie taktowym częstotliwością 8 MHz
    i 8-bitowej rozdzielczości PWM.

    Możesz zmieniać do woli.

    */

    ''')
    for i in range(0, octaves):
        for note, pitch in octave(basePitch * 2**i):
            if pitch < 30000:
                noteString = note + str(i)
                print("#define  {:<5}{:>6}").format(noteString, pitch)
                outfile.write("#define  {:<5}{:>6}\n".format(noteString, pitch))
    outfile.close()

######################################################################

if __name__ == "__main__":
    
    writeScaleHeader(basePitch=130, octaves=5)


