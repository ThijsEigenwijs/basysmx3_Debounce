char debounce(BTN btn) {

    //Make the static variables so we can store the values
    static char BTN_release[5];
    static char BTN_pressed[5];
    static char BTN_press[5];

    //Set a value to zero, so it only changes if its pressed
    char BTN_Value = 0;

    //Make the BTN_Value the value of the selected button
    switch (btn) {
        case BTN.C:
            BTN_Value = BTNC;
            break;
        case BTN.U:
            BTN_Value = BTNU;
            break;
        case BTN.L:
            BTN_Value = BTNL;
            break;
        case BTN.R:
            BTN_Value = BTNR;
            break;
        case BTN.D:
            BTN_Value = BTND;
            break;
    }

    //If the button is pressed
    if (BTN_Value == 1) {
        //Increase the value of time that the button is pressed
        BTN_press[btn]++;
        //Make the release value 0
        BTN_release[btn] = 0;

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
    }
        //If the button isn't pressed
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

    //Return the pressed state of the selected buttton
    return BTN_pressed[btn];
}