/* Copyright (c) 2022 Perlatecnica
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/****************************************************
*            RAPID PROTOTYPING WITH NUCLEO          *
* Example Code 05: LCDdisplay                       *
* Author: Mauro D'Angelo                            *
* Organization: Perlatecnica APS ETS			    *
*****************************************************/

#include "mbed.h"
#include "TextLCD.h"

#define SLAVEADDRESS 0x4E 
//#define SLAVEADDRESS 0x7E // Other possible Address

// It creates an instance of the i2c protocol driver assigning the pin SDA and SCL
I2C i2c_lcd(PB_9,PB_8); // SDA, SCL

// It creates the instance of the LCD driver. It needs the reference to I2C driver
TextLCD_I2C lcd(&i2c_lcd,SLAVEADDRESS,  TextLCD::LCD16x2); // I2C exp: I2C bus, PCF8574AT Slaveaddress, LCD Type


int main() {
    // It switches off the cursor
    lcd.setCursor(TextLCD::CurOff_BlkOff);
    
    // It switches On the backlight
    lcd.setBacklight(TextLCD::LightOn);

    // It clens the screen
    lcd.cls();
    
    // It prints on the screen
    lcd.printf("   Welcome to");
    
    // It points to the first column of the second raw
    lcd.setAddress(0, 1);
    
    // It prints on the screen
    lcd.printf("LCD display demo");

    ThisThread::sleep_for(2s);
}
