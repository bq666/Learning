/* Sterowany serwomotorem laserowy zegar słoneczny, prawie czasu rzeczywistego. */

// ------- Dołączane pliki -------- //
#include <avr/io.h>

// ------- Definicje -------- //
#define PULSE_MIN         1000             /* eksperymentuj z tymi wartościami */
#define PULSE_MAX         2000            /* dopasuj je do swojego serwomotoru */
#define PULSE_RANGE       (PULSE_MAX - PULSE_MIN)
#define PULSE_OVER        3000               /* Musi być większe niż PULSE_MAX */

#define START_TIME        10                                /* godzina 10 rano */
#define STOP_TIME     22                                         /* godzina 22 */
#define HOURS_RANGE        (STOP_TIME - START_TIME - 1)

#define LASER             PB2
#define LASER_PORT        PORTB
#define LASER_DDR         DDRB

#define SERVO             PB1
#define SERVO_PORT        PORTB
#define SERVO_DDR         DDRB

#define OVERFLOWS_PER_SECOND   31250   /* wartość nominalna, wymaga kalibracji */

// -------- Zmienne globalne --------- //
volatile uint16_t ticks;
volatile uint8_t hours = 15;                 /* dowolnie wybrany czas domyślny */
volatile uint8_t minutes = 42;
volatile uint8_t seconds = 57;

// Funkcje wejścia i wyjścia szeregowego
void pollSerial(void);
void printTime(uint8_t hours, uint8_t minutes, uint8_t seconds);

// Funkcje konfiguracji i sterowania serwomotorem
void initTimer1_Servo(void);
void enableServo(void);
void disableServo(void);
void setServoPosition(void);

// Funkcje obsługi zegara czasu rzeczywistego
// Używają globalnych zmiennych ticks, hours, minutes i seconds
void initTimer0_Clock(void);
void everyHour(void);
void everyMinute(void);
void everySecond(void);
