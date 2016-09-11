# PC-Starter
A usefull system to launch a computer with a smartphone using bluetooth comunication

# Arduino :

I used :
* Arduino UNO
* Bluetooth module HC-06
* 220 Ohm resistance
* Blue LED

Input of the button of your computer :
* Pin 2 = + of button
* Pin GND = - of button

Input of Bluetooth module :
* Pin 9 = RX of the arduino ( put the TX of the HC-06 )
* Pin 10 = TX of the arduino ( put the RX of the HC-06 )
* Pin GND = GND
* Pin 5V = VCC

Output :
* Pin 5 = Power switch + ( JPF1 of motherboard )
* Pin GND = Power switch - ( JPF1 of motherboard )
