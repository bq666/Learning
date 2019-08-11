
// Dołącz ten plik, jeżeli chcesz używać półkroków
// Być może konieczne będzie dopasowanie połączeń silnika
//   albo zmiana programu tak, żeby dopasować go do fizycznych połączeń.

const uint8_t stepOrder[] = {
  (1 << PB0) | (1 << PB2),
  (1 << PB0),
  (1 << PB0) | (1 << PB3),
  (1 << PB3),
  (1 << PB1) | (1 << PB3),
  (1 << PB1),
  (1 << PB1) | (1 << PB2),
  (1 << PB2)
};

#define LAST_PHASE_IN_CYCLE  7
