#include <Wire.h>  
#include <LiquidCrystal_I2C.h>  // include the library for the I2C LCD display

LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address and dimensions
int sensorPin = A0;  // connect the output of the turbidity sensor to analog pin A0
int sensorValue = 0; // variable to store the sensor value

void setup() {
  lcd.init();                      // initialize the LCD
  lcd.backlight();                 // turn on the backlight
  lcd.setCursor(0,0);              // set the cursor to the first position on the first line
  lcd.print("Turbidity Sensor");   // display a message on the first line
  lcd.setCursor(0,1);              // set the cursor to the first position on the second line
  lcd.print("Reading:");           // display a message on the second line
}

void loop() {
  sensorValue = analogRead(sensorPin);  // read the sensor value
  lcd.setCursor(8,1);                  // set the cursor to the ninth position on the second line
  lcd.print(sensorValue);              // display the sensor value on the second line
  delay(1000);                          // wait for a second before taking another reading
}
