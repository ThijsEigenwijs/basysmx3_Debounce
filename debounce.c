
char debounce(char btn) {

    //Make the static variables so we can store the values
    static char BTN_release[5];
    static char BTN_pressed[5];
    static char BTN_last[5];
    static char BTN_press[5];

    //Set a value to zero, so it only changes if its pressed
    char BTN_Value = 0;
    char returnVal = 0;

    //Make the BTN_Value the value of the selected button
    switch (btn) {
        case bounceC:
            BTN_Value = BTNC;
            break;
        case bounceU:
            BTN_Value = BTNU;
            break;
        case bounceL:
            BTN_Value = BTNL;
            break;
        case bounceR:
            BTN_Value = BTNR;
            break;
        case bounceD:
            BTN_Value = BTND;
            break;
        default:
            break;
    };





    //If the button is pressed
    if (BTN_Value == 1) {
        //Increase the value of time that the button is pressed
        BTN_press[btn]++;

        //If the button is pressed longer then the predefined value
        if (BTN_press[btn] > BounceValue) {

            //If the button isn't pressed before
            if (BTN_pressed[btn] == 0) {
                //Make it pressed
                BTN_pressed[btn] = 1;
            }

            //Set the time pressed back to zero
            BTN_press[btn] = 0;
        }
    }//If the button isn't pressed
    else {
        // Increase the time its released
        BTN_release[btn]++;
        //Set the time pressed to zero
        BTN_press[btn] = 0;

        //If the time is longer then the predefined value
        if (BTN_release[btn] > BounceValue) {
            //Reset everything!
            BTN_pressed[btn] = 0;
            BTN_release[btn] = 0;
        }
    }

    if (BTN_last[btn] != BTN_pressed[btn]) {
        if (BTN_pressed[btn] == 1)
            returnVal = 1;
    }

    BTN_last[btn] = BTN_pressed[btn];

    //Return the pressed state of the selected buttton
    return returnVal;
}

char debounceTest(char btn) {
    //Make the static variables so we can store the values
    static char BTN_release[5];
    static char BTN_pressed[5];
    static char BTN_last[5];
    static char BTN_press[5];

    //Set a value to zero, so it only changes if its pressed
    char BTN_Value = 0;
    char returnVal = 0;


    switch (btn) {
        case bounceC:
            BTN_Value = BTNC;
            break;
        case bounceU:
            BTN_Value = BTNU;
            break;
        case bounceL:
            BTN_Value = BTNL;
            break;
        case bounceR:
            BTN_Value = BTNR;
            break;
        case bounceD:
            BTN_Value = BTND;
            break;
        default:
            break;
    };

    // check to see if you just pressed the button
    // (i.e. the input went from LOW to HIGH), and you've waited long enough
    // since the last press to ignore any noise:

    // If the switch changed, due to noise or pressing:
    if (BTN_Value != BTN_last[btn]) {
        // reset the debouncing timer
        BTN_pressed[btn] = 0;
    }

    if (BTN_pressed[btn] > BounceValue) {
        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state:

        // if the button state has changed:
        if (BTN_Value != BTN_last[btn]) {
            BTN_last[btn] = BTN_Value;
       }
    }


    // save the reading. Next time through the loop, it'll be the lastButtonState:
    BTN_last[btn] = BTN_Value;
}