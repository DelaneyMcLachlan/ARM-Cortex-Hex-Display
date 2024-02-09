	#define HEX3_HEX0_BASE        0xFF200020 //base address for the 7-segment display
	#define SW_BASE               0xFF200040

void DisplayHex(int value) {
    volatile int *seg7_display_ptr = (int *)HEX3_HEX0_BASE;
    int display_value;

    if (value == 0) {
        display_value = 0b00111111; //0 = ABCDEF_ 0b00111111 Turns on all but not G or DP
    } else if (value == 1) {
        display_value = 0b00000110; //1	= _BC_____ = 0b00000110	
    } else if (value == 2) {
        display_value = 0b01011011; //2 = AB_DE_G_ = 0b01011011
    } else if (value == 3) {
        display_value = 0b01001111; //3 = ABCD__G_ = 0b01001111	
    } else if (value == 4) {
        display_value = 0b01100110; //4 = _BC__FG_ = 0b01100110	
    } else if (value == 5) {
        display_value = 0b01101101; //5 = A_CD_FG_ = 0b01101101 
    } else if (value == 6) {
        display_value = 0b01111101; //6 = A_CDEFG_ = 0b01111101 
    } else if (value == 7) {
        display_value = 0b00000111; //7 = ABC_____ = 0b00000111 
    } else if (value == 8) {
        display_value = 0b01111111; //8 = ABCDEFG_ = 0b01111111 
    } else if (value == 9) {
        display_value = 0b01101111; //9 = ABCD_FG_ = 0b01101111 	
     } else if (value == 10) {
        display_value = 0b01110111; // A = 0b01110111
    } else if (value == 11) {
        display_value = 0b01111100; // b = 0b01111100
    } else if (value == 12) {
        display_value = 0b00111001; // C = 0b00111001
    } else if (value == 13) {
        display_value = 0b01011110; // d = 0b01011110
    } else if (value == 14) {
        display_value = 0b01111001; // E = 0b01111001
    } else if (value == 15) {
        display_value = 0b01110001; // F = 0b01110001	
    } else {
        display_value = 0; // Blank display for values not in range 0-15
    }

    *seg7_display_ptr = display_value;
}

void delay() {
    volatile unsigned int j;
    for (j = 0; j < 500000; j++); // delay loop
}

int main(void) {
    while(1) {
        int switchValue = ReadSwitches(); // Get the current switch value
        DisplayHex(switchValue);          // Display the corresponding hex digit
		delay();                          //Delay time 
		DisplayHex(16);                   //Display other condition (no number)		
		delay();                          //Delay again
    }
}
		
int ReadSwitches(void)
{
	//define volatile, changeable
	volatile int *readValue_ptr = (int *)SW_BASE;    //pointer to the slide switches memory address, defined above
	int readValue = *readValue_ptr; //dereference the pointer to get value from switches
	readValue = readValue & 0x0F; //mask four lowest bits from switch address
	return readValue;
}		

	
