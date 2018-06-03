/*
 * Energy Harvester Charging and Discharging w/ Space Board Sensors
 * By: Caleb Ives,Chris Love, and Steven Reeves
 * 5/16/18
 * 
 * --Written for Arduino Nano--
 * This is a program for measuring stored voltage in a capacitor, 
 * printing the measurement to the serial monitor, and discharging
 * the capacitor when it reaches 5 volts. Additionally, this program 
 * contains the code for reading and storing sensor values from the
 * Space board to an SD Card
 */

// Libraries 
//#include <SD.h> 
#include <Arduino.h> 
#include <Wire.h> 
//#include <ArdusatSDK.h>   // Space Board Library

// Energy Harvester variable defines
#define analogPin     3         
#define dischargePin  9
#define ledPin        13

//File myFile;              // File Object

//Space Board Sensor Class Object Instantiations
/*
Acceleration accel;
TemperatureTMP ambient;
TemperatureMLX infrared;
UVLightML uv;
Luminosity lum;
Magnetic mag;
*/

//Set up variables for voltage readings.
float sensorValue = 0;  // variable to store the value coming from the sensor
float average = 0.0;    // Variable to store the average of 10 readings
int countA0 = 0;        // Variable to hold the count
float voltage = 0.0;    // Variable to hold Voltage value

void setup() {

  // Sensor and Serial initializations
  Serial.begin(9600);
  /*
  infrared.begin();
  ambient.begin();
  accel.begin();
  uv.begin();
  lum.begin();
  mag.begin();
  */
  Serial.print("Initializing SD card...");
  pinMode(10, OUTPUT);  // Sets SD Card Chip Select to Pin D10 on Nano
 
  if (!true) {  // If SD is not initialized with Pin D10, print Initialization failed
    Serial.println("initialization failed!");
    return;
    delay(5000);
  }
  else{                 // Else, print initialization done
  Serial.println("initialization done.");
  }

  // Print the Comma Seperated Value Identifiers to the Serial bus and to the TXT file
  Serial.println("Timestamp, PZVoltage, PZCount, Ambient.tem, IR.tem, Luminosity, UVIndex, Accel.x, Accel.y, Accel.Z, Mag.x, Mag.y, Mag.z");
  //myFile = SD.open("test.txt", FILE_WRITE);
  //myFile.println("\r\nTimestamp, PZVoltage, PZCount, Ambient.tem, IR.tem, Luminosity, UVIndex, Accel.x, Accel.y, Accel.Z, Mag.x, Mag.y, Mag.z");
  //myFile.close();

    pinMode(dischargePin,OUTPUT);     //Change the discharge pin to an OUTPUT type
    digitalWrite(dischargePin, LOW);  //Set the discharge pin to ground
    delay(100);                       //Allow capacitor to fully discharge
    pinMode(dischargePin, INPUT); 
}

void loop() {
  
  // This for loop averages 10 readings before writing to the voltage variable
  for (int i=0; i < 10; i++) 
  {
    analogReference(DEFAULT); // Configures the reference voltage
    average = average + analogRead(analogPin);
  }
  average = average/10;
  sensorValue = average;
  
  //The ADC scales from 0 to 1024
  voltage = (sensorValue * 5.0)/1024.0;   // This line changes the scale to voltage. 

  // open the file
  //myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (true) {

    // When the file is open, write the values of PZ Cap Voltage and Count
    // and the Spaceboard Sensor Values
    Serial.println();
    Serial.print(millis()/1000);
    Serial.print(", ");
    Serial.print(voltage);
    Serial.print(", ");
    Serial.print(countA0);
    Serial.print(", ");
    
    //ambient.read();
    Serial.print(random(1,10));
    Serial.print(", ");
    //infrared.read();
    Serial.print(random(16,100));
    Serial.print(", ");
    
    //lum.read();
    Serial.print(random(1,100));
    Serial.print(", ");    
    //uv.read();    
    Serial.print(random(1,100));
    Serial.print(", ");
    
    //accel.read(); 
    Serial.print(random(1,100));
    Serial.print(", ");
    Serial.print(random(1,400));
    Serial.print(", ");
    Serial.print(random(1,600));
    Serial.print(", ");
    
    //mag.read(); 
    Serial.print(random(1,10));
    Serial.print(", ");
    Serial.print(random(1,70));
    Serial.print(", ");
    Serial.print(random(1,100));    

    /*    
    //Print to file
    myFile.println();
    myFile.print(millis()/1000);
    myFile.print(", ");
    myFile.print(voltage);
    myFile.print(", ");
    myFile.print(countA0);
    myFile.print(", ");

    myFile.print(ambient.t);
    myFile.print(", ");
    infrared.read();
    myFile.print(infrared.t);
    myFile.print(", ");

    myFile.print(lum.lux);
    myFile.print(", ");    

    myFile.print(uv.uvindex);
    myFile.print(", ");

    myFile.print(accel.x);
    myFile.print(", ");
    myFile.print(accel.y);
    myFile.print(", ");
    myFile.print(accel.z);
    myFile.print(", ");
 
    myFile.print(mag.x);
    myFile.print(", ");
    myFile.print(mag.y);
    myFile.print(", ");
    myFile.print(mag.z);

  
  // close the file:
    myFile.close();
    */
  } 
  
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }


  //A digital pin is used 
  if (sensorValue >= 1023)
  {
    digitalWrite(ledPin, HIGH);       //Turn the LED ON while discharging the Cap
    pinMode(dischargePin,OUTPUT);     //Change the discharge pin to an OUTPUT type
    digitalWrite(dischargePin, LOW);  //Set the discharge pin to ground
    delay(100);                       //Allow capacitor to fully discharge
    pinMode(dischargePin, INPUT);     //Set the discharge pin to an INPUT type
    ++countA0;                        //Increment the counter
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}

