#ifndef TT_Buttons
#define TT_Buttons

//The defines
#define BTNU    PORTBbits.RB1
#define BTNL    PORTBbits.RB0
#define BTNC    PORTFbits.RF0
#define BTNR    PORTBbits.RB8
#define BTND   PORTAbits.RA15

#define bounceC 0
#define bounceU 1
#define bounceL 2
#define bounceR 3
#define bounceD 4

//Functions
char debounce(char btn);

#endif
