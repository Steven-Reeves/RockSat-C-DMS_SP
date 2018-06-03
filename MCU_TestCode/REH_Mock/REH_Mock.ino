/*
 * Rocket Energy Harvester Sketch
 * By Caleb Ives and Steven Reeves
 */

//Libraries
#include <Wire.h>                 // Communication
//#include <SD.h>                   // For SD card
//#include <Adafruit_L3GD20.h>      // Gyro
//#include "RTClib.h"               // Real Time Clock

//File myFile;                      // File on SD card

//Defenitions
#define USE_I2C                   //GYRO and RTC use I2C
//#define analogPin3     3          //ADC3
//#define analogPin4     4          //ADC4
//#define analogPin5     5          //...
//#define analogPin6     6
//#define analogPin7     7
//#define analogPin8     8
#define dischargePin3  11           // 
//#define dischargePin4  10
#define dischargePin4  12
#define dischargePin5  9
#define dischargePin6  8
#define dischargePin7  7
#define dischargePin8  6
#define ledPin        13


//Adafruit_L3GD20 gyro;
//RTC_DS1307 rtc;


//Accelerometer
const int xInput = A0;
const int yInput = A1;
const int zInput = A2;
const int sampleSize = 1; 
const int analogPin3 = A3;
const int analogPin4 = A4;
const int analogPin5 = A5;
//const int analogPin6 = A6;
//const int analogPin7 = A7;
//const int analogPin8 = A8;

//Energy Variables
float sensorValue = 0;  // variable to store the value coming from the sensor
float average3 = 0.0;
float average4 = 0.0;
float average5 = 0.0;
float average6 = 0.0;
float average7 = 0.0;
float average8 = 0.0;

float sensorValue3 = 0;  // variable to store the value coming from the sensor
float sensorValue4 = 0;
float sensorValue5 = 0;
float sensorValue6 = 0;
float sensorValue7 = 0;
float sensorValue8 = 0;

float voltage3 = 0;
float voltage4 = 0;
float voltage5 = 0;
float voltage6 = 0;
float voltage7 = 0;
float voltage8 = 0;

int countA3 = 0;
int countA4 = 0;
int countA5 = 0;
int countA6 = 0;
int countA7 = 0;
int countA8 = 0;
float voltage = 0.0;

void setup() {
  
//**************************************************************************
//************************  SENSORS  ***************************************
//**************************************************************************
  //analogReference(EXTERNAL);
  Serial.begin(9600);
  /*
  if (!gyro.begin(gyro.L3DS20_RANGE_250DPS))
  //if (!gyro.begin(gyro.L3DS20_RANGE_500DPS))
  //if (!gyro.begin(gyro.L3DS20_RANGE_2000DPS))
  {
    Serial.println("Unable to initialize Gyro!");
    while (1);
  }
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date 
    // & time this sketch was compiled
    */
//    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line   sets the RTC with an explicit
    // date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));

//***************************************************************************
//**************************** SD CARD **************************************
//***************************************************************************
/*
  Serial.print("Initializing SD card...");
  pinMode(ledPin, OUTPUT);
  pinMode(53, OUTPUT);

  /*
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }
  */
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  //myFile = SD.open("test.txt", O_CREAT | O_WRITE);
 
  // if the file opened okay, write to it:
  /*
  if (myFile) {
    Serial.print("Writing to test.txt on local...");
    myFile.println("New Material....");
  // close the file:
  myFile.flush();  

  myFile.close();
    Serial.println("done.");
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
*/
}

void loop() {
  
//***********************************************************************************
//*****************************  SENSORS  *******************************************
//***********************************************************************************
  //myFile = SD.open("test.txt", O_CREAT | O_WRITE);
  
  int xRaw = ReadAxis(xInput);
  int yRaw = ReadAxis(yInput);
  int zRaw = ReadAxis(zInput);
//  gyro.read();
  //DateTime now = rtc.now();

  //RTC output
   char dateBuffer[12];

  Serial.print("\t");
  sprintf(dateBuffer,"%02u-%02u-%04u ",6,6,2018);
  Serial.print(dateBuffer);
  sprintf(dateBuffer,"%02u:%02u:%02u ",12,56,13);
  Serial.print(dateBuffer);

  //myFile.print("\t");
  //sprintf(dateBuffer,"%02u-%02u-%04u ",now.month(),now.day(),now.year());
  //myFile.print(dateBuffer);
  //sprintf(dateBuffer,"%02u:%02u:%02u ",now.hour(),now.minute(),now.second());
  //myFile.print(dateBuffer);
/*
  //Gyro output
  myFile.print("\t");
  myFile.print("| Gyro-> X: "); 
  myFile.print("\t");
  myFile.print ((int)gyro.data.x);  
  myFile.print("\t");
  myFile.print("Y: ");
  myFile.print("\t");
  myFile.print((int)gyro.data.y); 
  myFile.print("\t");
  myFile.print("Z: ");
  myFile.print("\t");
  myFile.print((int)gyro.data.z);

  //Acceleromter Output
  myFile.print("\t");
  myFile.print("| Accel-> X:");
  myFile.print("\t");
  myFile.print(xRaw);
  myFile.print("\t");
  myFile.print("Y:");
  myFile.print("\t");
  myFile.print(yRaw);
  myFile.print("\t");
  myFile.print("Z:");
  myFile.print("\t");
  myFile.print(zRaw);
  //delay(10);
*/
  for (int i=0; i < 10; i++)
  {
    analogReference(DEFAULT);
    average3 = average3 + random(800,900);
    average4 = average4 + random(500,1000);
    average5 = average5 + random(100,800);
    average6 = average6 + random(789,2000);
    average7 = average7 + random(1,20);
    average8 = average8 + random(1,20);
  }
  
  average3 = average3/10;
  average4 = average4/10;
  average5 = average5/10;
  average6 = average6/10;
  average7 = average7/10;
  average8 = average8/10;

  sensorValue3 = average3;
  sensorValue4 = average4;
  sensorValue5 = average5;
  sensorValue6 = average6;
  sensorValue7 = average7;
  sensorValue8 = average8;
    
  //sensorValue = average3;

  voltage3 = (random(600,800) * 5.0)/1024.0;
  voltage4 = (random(1,20) * 5.0)/1024.0;
  voltage5 = (random(1,30) * 5.0)/1024.0;
  voltage6 = (random(1,40) * 5.0)/1024.0;
  voltage7 = (random(1,50) * 5.0)/1024.0;
  voltage8 = (random(1,80) * 5.0)/1024.0;

  Serial.print("\t");
  //myFile.print("\t");
  Serial.print("Vib.Energy:");
  //myFile.print("Vib.Energy:");
  Serial.print("\t");
  //myFile.print("\t");
  Serial.print("V1 = ");
  //myFile.print("V1 = ");
  Serial.print(voltage3);
  //myFile.print(voltage3);
  Serial.print("\t");
  //myFile.print("\t");
  Serial.print("# = ");
 // myFile.print("# = ");
  Serial.print(countA3);
  //myFile.print(countA3);
  Serial.print("\t");
  //myFile.print("\t");
  Serial.print("V2 = ");
  //myFile.print("V2 = ");
  Serial.print(voltage4);
  //myFile.print(voltage4);
  Serial.print("\t");
  //myFile.print("\t");
  Serial.print("# = ");
  //myFile.print("# = ");
  Serial.print(countA4);
  //myFile.print(countA4);
  Serial.print("\t");
  //myFile.print("\t");
  Serial.print("V3 = ");
  //myFile.print("V3 = ");
  Serial.print(voltage5);
  //myFile.print(voltage5);
  Serial.print("\t");
  //myFile.print("\t");
  Serial.print("# = ");
  //myFile.print("# = ");
  Serial.print(countA5);
  //myFile.print(countA5);
  Serial.print("\t");
  //myFile.print("\t");
  Serial.print("V4 = ");
  //myFile.print("V4 = ");
  Serial.print(voltage6);
  //myFile.print(voltage6);
  Serial.print("\t");
  //myFile.print("\t");
  Serial.print("# = ");
  //myFile.print("# = ");
  Serial.print(countA6);
  //myFile.print(countA6);
  Serial.print("\t");
  //myFile.print("\t");
  Serial.print("V5 = ");
  //myFile.print("V5 = ");
  Serial.print(voltage7);
  //myFile.print(voltage7);
  Serial.print("\t");
  //myFile.print("\t");
  Serial.print("# = ");
  //myFile.print("# = ");
  Serial.print(countA7);
  //myFile.print(countA7);
  Serial.print("\t");
  //myFile.print("\t");
  Serial.print("Grav.Energy:");
  //myFile.print("Grav.Energy:");
  Serial.print("\t");
  //myFile.print("\t");
  Serial.print("V6 = ");
  //myFile.print("V6 = ");
  Serial.print(voltage8);
  //myFile.print(voltage8);
  Serial.print("\t");
  //myFile.print("\t");
  Serial.print("# = ");
  //myFile.print("# = ");
  Serial.println(countA8);
  //myFile.println(countA8);

  if (sensorValue3 >= 717)
  {
    digitalWrite(ledPin, HIGH);
    pinMode(dischargePin3,OUTPUT); 
    digitalWrite(dischargePin3, LOW);
    delay(50);
    pinMode(dischargePin3, INPUT);
    ++countA3;
  }
  else if (sensorValue4 >= 717)
  {
    digitalWrite(ledPin, HIGH);
    pinMode(dischargePin4,OUTPUT); 
    digitalWrite(dischargePin4, LOW);
    delay(50);
    pinMode(dischargePin4, INPUT);
    ++countA4;
  }
  else if (sensorValue5 >= 717)
  {
    digitalWrite(ledPin, HIGH);
    pinMode(dischargePin5,OUTPUT); 
    digitalWrite(dischargePin5, LOW);
    delay(50);
    pinMode(dischargePin5, INPUT);
    ++countA5;
  }
  else if (sensorValue6 >= 717)
  { 
    digitalWrite(ledPin, HIGH);
    pinMode(dischargePin6,OUTPUT); 
    digitalWrite(dischargePin6, LOW);
    delay(50);
    pinMode(dischargePin6, INPUT);
    ++countA6;
  }
  else if (sensorValue7 >= 717)
  {
    digitalWrite(ledPin, HIGH);
    pinMode(dischargePin7,OUTPUT); 
    digitalWrite(dischargePin7, LOW);
    delay(50);
    pinMode(dischargePin7, INPUT);
    ++countA7;
  }
  else if (sensorValue8 >= 717)
  {
    digitalWrite(ledPin, HIGH);
    pinMode(dischargePin8,OUTPUT); 
    digitalWrite(dischargePin8, LOW);
    delay(50);
    pinMode(dischargePin8, INPUT);
    ++countA8;
  } 
  else
  {
    digitalWrite(ledPin, LOW);
  }
  //myFile.flush();  

  //myFile.close();

} // END OF LOOP


//***********************************************************************************
//********************************** FUNCTIONS **************************************
//***********************************************************************************

// Read "sampleSize" samples and report 
//Random number inserted for reading
int ReadAxis(int axisPin)
{
  long reading = 0;
  analogRead(axisPin);
  delay(1);
  for (int i = 0; i < sampleSize; i++)
  {
    reading = random(1,400);
  }
  return reading/sampleSize;
}


