/*
 * Simple data logger.
 * 
 * Stubbed out for testing with RockSat-C DMS
 */
#include <SPI.h>
// Commented out for testing
// #include "SdFat.h"

// SD chip select pin.  Be sure to disable any other SPI devices such as Enet.
const uint8_t chipSelect = 10;

// Interval between data records in milliseconds.
// The interval must be greater than the maximum SD write latency plus the
// time to acquire and write data to the SD to avoid overrun errors.
// Run the bench example to check the quality of your SD card.
const uint32_t SAMPLE_INTERVAL_MS = 50;

// Log file base name.  Must be six characters or less.
#define FILE_BASE_NAME "Data"
//------------------------------------------------------------------------------
// File system object.
// Commented out for testing
//SdFat sd;

// Log file.
// Commented out for testing
//SdFile file;

// Time in micros for next data record.
uint32_t logTime;

//==============================================================================
// User functions.  Edit writeHeader() and logData() for your requirements.

const uint8_t ANALOG_COUNT = 2;
//------------------------------------------------------------------------------
// Write data header.
void writeHeader() {
  Serial.print(F("micros"));
  //file.print(F("micros"));
  for (uint8_t i = 0; i < ANALOG_COUNT; i++) {
    // file.print(F(",adc"));
    // Serial for testing
    Serial.print(i, DEC);
    // Serial for testing
    // file.print(F(",adc"));
    Serial.print(i, DEC);
  }
  // Serial for testing
  // file.println();
  Serial.println();
}
//------------------------------------------------------------------------------
// Log a data record.
void logData() {
  uint16_t data[ANALOG_COUNT];

  // Read all channels to avoid SD write latency between readings.
  for (uint8_t i = 0; i < ANALOG_COUNT; i++) {
    data[i] = analogRead(i);
  }
  // Write data to file.  Start with log time in micros.
  // Commented out for testing
  //file.print(logTime);
  Serial.print(logTime);

  // Write ADC data to CSV record.
  for (uint8_t i = 0; i < ANALOG_COUNT; i++) {
    // Serial for testing
    // file.write(',');
    Serial.print(',');
    // file.print(data[i]);
    Serial.print(data[i]);
  }
  // Serial for testing
  // file.println();
  Serial.println();
}
//==============================================================================
// Error messages stored in flash.
  // Commented out for testing
// #define error(msg) sd.errorHalt(F(msg))
//------------------------------------------------------------------------------
void setup() {
    const uint8_t BASE_NAME_SIZE = sizeof(FILE_BASE_NAME) - 1;
  char fileName[13] = FILE_BASE_NAME "00.csv";

  // Uncommented for testing
  Serial.begin(9600);
  
  // Wait for USB Serial 
  //while (!Serial) {
    //SysCall::yield();
  //}
  //delay(1000);

  //Serial.println(F("Type any character to start"));
  //while (!Serial.available()) {
    //SysCall::yield();
  //}
  
  // Initialize at the highest speed supported by the board that is
  // not over 50 MHz. Try a lower speed if SPI errors occur.
  /*
  if (!sd.begin(chipSelect, SD_SCK_MHZ(50))) {
    sd.initErrorHalt();
  }

  // Find an unused file name.
  if (BASE_NAME_SIZE > 6) {
    error("FILE_BASE_NAME too long");
  }

  while (sd.exists(fileName)) {
    if (fileName[BASE_NAME_SIZE + 1] != '9') {
      fileName[BASE_NAME_SIZE + 1]++;
    } else if (fileName[BASE_NAME_SIZE] != '9') {
      fileName[BASE_NAME_SIZE + 1] = '0';
      fileName[BASE_NAME_SIZE]++;
    } else {
      error("Can't create file name");
    }
  }
  */
  // Commented out for testing
  /*
  if (!file.open(fileName, O_CREAT | O_WRITE | O_EXCL)) {
    error("file.open");
  }
  */
  // Read any Serial data.
  do {
    delay(10);
  } while (Serial.available() && Serial.read() >= 0);

  Serial.print(F("Logging to: "));
  Serial.println(fileName);
  Serial.println(F("Type any character to stop"));

  // Write data header.
  writeHeader();

  // Start on a multiple of the sample interval.
  logTime = micros()/(1000UL*SAMPLE_INTERVAL_MS) + 1;
  logTime *= 1000UL*SAMPLE_INTERVAL_MS;
}
//------------------------------------------------------------------------------

void loop() {
  // Time for next record.
  logTime += 1000UL*SAMPLE_INTERVAL_MS;

  // Wait for log time.
  int32_t diff;
  do {
    diff = micros() - logTime;
  } while (diff < 0);

  // Check for data rate too high.
  if (diff > 10) {
    Serial.print("Missed data record");
    // Commented out for testing
    //error("Missed data record");
  }

  logData();

  // Force data to SD and update the directory entry to avoid data loss.
  // Commented out for testing
  /*
  if (!file.sync() || file.getWriteError()) {
    error("write error");
  }
  */
  if (Serial.available()) {
//    // Close file and stop.
//    file.close();
    Serial.println(F("Done"));
//    SysCall::halt();
      }

}
