﻿# ARM-Cortex-Hex-Display

 
## Overview
This project involves programming an ARM Cortex A9 processor on a DE10-Standard platform. The primary function is to control a seven-segment hex display, reading binary values from slide switches and displaying the corresponding hexadecimal digits. 

## Hardware Requirements
- DE10-Standard platform
- ARM Cortex A9 processor
- Slide switches and a seven-segment display

## Setup and Installation
1. Ensure all hardware is correctly connected.
2. Configure the DE10-Standard platforms.
3. Load and compile the code using the Intel FPGA Monitor program.

## Usage
- Adjust the binary values using the first four slide switches.
- The corresponding hexadecimal digit will be displayed on the seven-segment display (HEX0).
- The display blinks, showing the value set by the slide switches when on and turning off in intervals.

## Features
- Reading a 4-bit binary value from slide switches.
- Displaying a corresponding hex digit on the HEX0 display.
- Blinking display functionality with adjustable delay.
