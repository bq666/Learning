
// ------------- Prototypy funkcji -------------- //

// Odtwarza dźwięk przez zadany czas. Żaden z tych czasów nie jest 
//  kalibrowany do rzeczywistych nut i tempa.  Wszystko wyznaczane jest 
// względem parameteru TIMEBASE.
void playNote(uint16_t wavelength, uint16_t duration);

// Przez podany w parametrze czas nie robi nic.
void rest(uint16_t duration);
