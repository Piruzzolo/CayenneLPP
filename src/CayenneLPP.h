// Adapted from https://developer.mbed.org/teams/myDevicesIoT/code/Cayenne-LPP/

// Copyright © 2017 The Things Network
// Use of this source code is governed by the MIT license that can be found in the LICENSE file.

#ifndef CAYENNE_LPP_H
#define CAYENNE_LPP_H

#include <Arduino.h>

#define LPP_DIGITAL_INPUT               0     // 1 byte
#define LPP_DIGITAL_OUTPUT              1     // 1 byte
#define LPP_ANALOG_INPUT                2     // 2 bytes, 0.01 signed
#define LPP_ANALOG_OUTPUT               3     // 2 bytes, 0.01 signed
#define LPP_GENERIC_SENSOR              100   // 4 bytes, unsigned
#define LPP_LUMINOSITY                  101   // 2 bytes, 1 lux unsigned
#define LPP_PRESENCE                    102   // 1 byte, bool
#define LPP_TEMPERATURE                 103   // 2 bytes, 0.1°C signed
#define LPP_RELATIVE_HUMIDITY           104   // 1 byte, 0.5% unsigned
#define LPP_ACCELEROMETER               113   // 2 bytes per axis, 0.001G
#define LPP_BAROMETRIC_PRESSURE         115   // 2 bytes 0.1hPa unsigned
#define LPP_VOLTAGE                     116   // 2 bytes 0.01V unsigned
#define LPP_CURRENT                     117   // 2 bytes 0.001A unsigned
#define LPP_FREQUENCY                   118   // 4 bytes 1Hz unsigned
#define LPP_PERCENTAGE                  120   // 1 byte 1-100% unsigned
#define LPP_ALTITUDE                    121   // 2 byte 1m signed
#define LPP_POWER                       128   // 2 byte, 1W, unsigned
#define LPP_DISTANCE                    130   // 4 byte, 0.001m, unsigned
#define LPP_ENERGY                      131   // 4 byte, 0.001kWh, unsigned
#define LPP_DIRECTION                   132   // 2 bytes, 1deg, unsigned
#define LPP_UNIXTIME                    133   // 4 bytes, unsigned
#define LPP_GYROMETER                   134   // 2 bytes per axis, 0.01 °/s
#define LPP_GPS                         136   // 3 byte lon/lat 0.0001 °, 3 bytes alt 0.01 meter
#define LPP_SWITCH                      142   // 1 byte, 0/1

// Only Data Size
#define LPP_DIGITAL_INPUT_SIZE          1
#define LPP_DIGITAL_OUTPUT_SIZE         1
#define LPP_ANALOG_INPUT_SIZE           2
#define LPP_ANALOG_OUTPUT_SIZE          2
#define LPP_GENERIC_SENSOR_SIZE         4
#define LPP_LUMINOSITY_SIZE             2
#define LPP_PRESENCE_SIZE               1
#define LPP_TEMPERATURE_SIZE            2
#define LPP_RELATIVE_HUMIDITY_SIZE      1
#define LPP_ACCELEROMETER_SIZE          6
#define LPP_BAROMETRIC_PRESSURE_SIZE    2
#define LPP_VOLTAGE_SIZE                2
#define LPP_CURRENT_SIZE                2
#define LPP_FREQUENCY_SIZE              4
#define LPP_PERCENTAGE_SIZE             1
#define LPP_ALTITUDE_SIZE               2
#define LPP_POWER_SIZE                  2
#define LPP_DISTANCE_SIZE               4
#define LPP_ENERGY_SIZE                 4
#define LPP_DIRECTION_SIZE              2
#define LPP_UNIXTIME_SIZE               4
#define LPP_GYROMETER_SIZE              6
#define LPP_GPS_SIZE                    9
#define LPP_SWITCH_SIZE                 1

// Multipliers
#define LPP_DIGITAL_INPUT_MULT          1
#define LPP_DIGITAL_OUTPUT_MULT         1
#define LPP_ANALOG_INPUT_MULT           100
#define LPP_ANALOG_OUTPUT_MULT          100
#define LPP_GENERIC_SENSOR_MULT         1
#define LPP_LUMINOSITY_MULT             1
#define LPP_PRESENCE_MULT               1
#define LPP_TEMPERATURE_MULT            10
#define LPP_RELATIVE_HUMIDITY_MULT      2
#define LPP_ACCELEROMETER_MULT          1000
#define LPP_BAROMETRIC_PRESSURE_MULT    10
#define LPP_VOLTAGE_MULT                100
#define LPP_CURRENT_MULT                1000
#define LPP_FREQUENCY_MULT              1
#define LPP_PERCENTAGE_MULT             1
#define LPP_ALTITUDE_MULT               1
#define LPP_POWER_MULT                  1
#define LPP_DISTANCE_MULT               1000
#define LPP_ENERGY_MULT                 1000
#define LPP_DIRECTION_MULT              1
#define LPP_UNIXTIME_MULT               1
#define LPP_GYROMETER_MULT              100
#define LPP_GPS_LAT_LON_MULT            10000
#define LPP_GPS_ALT_MULT                100
#define LPP_SWITCH_MULT                 1

class CayenneLPP {

public:

  CayenneLPP(uint8_t size);
  ~CayenneLPP();

  void reset(void);
  uint8_t getSize(void);
  uint8_t *getBuffer(void);
  uint8_t copy(uint8_t *buffer);

  // Original LPPv1 data types
  uint8_t addDigitalInput(uint8_t channel, uint8_t value);
  uint8_t addDigitalOutput(uint8_t channel, uint8_t value);
  uint8_t addAnalogInput(uint8_t channel, float value);
  uint8_t addAnalogOutput(uint8_t channel, float value);
  uint8_t addLuminosity(uint8_t channel, uint16_t value);
  uint8_t addPresence(uint8_t channel, uint8_t value);
  uint8_t addTemperature(uint8_t channel, float value);
  uint8_t addRelativeHumidity(uint8_t channel, float value);
  uint8_t addAccelerometer(uint8_t channel, float x, float y, float z);
  uint8_t addBarometricPressure(uint8_t channel, float value);
  uint8_t addGyrometer(uint8_t channel, float x, float y, float z);
  uint8_t addGPS(uint8_t channel, float latitude, float longitude, float altitude);

  // Added by Electronic Cats
  uint8_t addUnixTime(uint8_t channel, uint32_t value);

  // Added by Xose Pérez
  uint8_t addGenericSensor(uint8_t channel, float value);
  uint8_t addVoltage(uint8_t channel, float value);
  uint8_t addCurrent(uint8_t channel, float value);
  uint8_t addFrequency(uint8_t channel, uint32_t value);
  uint8_t addPercentage(uint8_t channel, uint8_t value);
  uint8_t addAltitude(uint8_t channel, float value);
  uint8_t addPower(uint8_t channel, uint16_t value);
  uint8_t addDistance(uint8_t channel, float value);
  uint8_t addEnergy(uint8_t channel, float value);
  uint8_t addDirection(uint8_t channel, float value);
  uint8_t addSwitch(uint8_t channel, uint8_t value);

protected:

  template <typename T> uint8_t addValue(uint8_t channel, uint8_t type, T value, uint32_t multiplier, uint8_t size, bool is_signed = false);
  
  uint8_t * _buffer;
  uint8_t _maxsize;
  uint8_t _cursor;

};

#endif