/*
 * Modified from original library and examples by big12boy 2017
 * https://github.com/big12boy/TEA5767
 * 
 * Mostly reformat and recomment and simplification.
 * 
 * Signal strength only updates if you do a reset. Use Arduino Reset button
 * 
 * Tested on Arduino Uno connected to TEA5767 module. 
 * 
 * This used to test TEA5767 basic operation and measure signal strength for various antenna.
 * 
 * See blog post here for more detail: 
 * https://www.doctormonk.com/2025/04/accessible-fm-radio-case-study-part-1.html
 * 
 */

#include <TEA5767.h>
TEA5767 radio = TEA5767();

float frequency = 93.0; // Enter your own Frequency in MHz. Look up the frequency of a station near you. 
long baud = 9600;       //Enter your own Baudrate. I always use 9600.

void setup() {
  Serial.begin(baud);
  Wire.begin();
}

void loop() {
  radio.setFrequency(frequency);
  printReady();
  printStereo();
  printSignalLevel();
  
  Serial.println();
  delay(1000); 
}

void printReady(){
  int rdy = radio.getReady();
  Serial.print("Ready: ");
  Serial.println(rdy);
}

void printStereo(){
  bool stereo = radio.isStereo(); 
  Serial.print("Stereo: ");
  Serial.println(stereo);
}

void printSignalLevel(){
  short level = radio.getSignalLevel(); 
  Serial.print("Signal (0-15): ");
  Serial.println(level);
}
