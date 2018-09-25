#define BTNU    PORTBbits.RB1
#define BTNL    PORTBbits.RB0
#define BTNC    PORTFbits.RF0
#define BTNR    PORTBbits.RB8
#define BTND   PORTAbits.RA15

typedef enum {
    C = 0,
    U = 1,
    L = 2,
    R = 3,
    D = 4
} BTN;

