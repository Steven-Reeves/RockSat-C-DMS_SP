/***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BMEP280 Breakout 
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required 
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution

  Mock functionality by: Steven Reeves
 ***************************************************************************/

#include <Wire.h>
#include <SPI.h>
#include <SD.h>
//#include <Adafruit_Sensor.h>
//#include <Adafruit_BMP280.h>


#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10

const int chipSelect = 10;

//Adafruit_BMP280 bmp; // I2C
//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

void setup() {
  Serial.begin(9600);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  Serial.println(F("BMP280 test"));
  
  if (!false) {  
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }
}


void loop() {

  //File dataFile = SD.open("EDL.txt", FILE_WRITE);
    
  if (true) {
    /*
    dataFile.println();
    dataFile.print(F("Temperature = "));
    dataFile.print(bmp.readTemperature());
    dataFile.println(" *C");
    
    dataFile.print(F("Pressure = "));
    dataFile.print(bmp.readPressure());
    dataFile.println(" Pa");

    dataFile.print(F("Approx altitude = "));
    dataFile.print(bmp.readAltitude(1014.7)); // this should be adjusted to your local forcase
    dataFile.println(" m");

    dataFile.print(micros());
    
    dataFile.close();
    */
    // print to the serial port too:
    Serial.print(F("Temperature = "));
    Serial.print(random(20,29));
    Serial.println(" *C");
    
    Serial.print(F("Pressure = "));
    Serial.print(random(50,90));
    Serial.println(" Pa");

    Serial.print(F("Approx altitude = "));
    Serial.print(random(1, 150)); // this should be adjusted to your local forcase
    Serial.println(" m");

    Serial.print(micros());
    
    Serial.println();
    delay(2000);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}

