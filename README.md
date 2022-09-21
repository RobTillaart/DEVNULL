
[![Arduino CI](https://github.com/RobTillaart/DEVNULL/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/DEVNULL/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/DEVNULL/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/DEVNULL/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/DEVNULL/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/DEVNULL/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/DEVNULL.svg?maxAge=3600)](https://github.com/RobTillaart/DEVNULL/releases)


# DEVNULL

Arduino library for a /dev/null stream.


## Description

The library implements a stream class that mimics the **/dev/null**
device of a Linux system. You can write everything to it. 
You can never read data from it as it always returns EOF (end of file);

The 0.1.0 version is a minimal implementation that can be optimized.
it implements the **write(const uint8_t data)** call and e.g. a float is still
converted to individual characters that are send one after another.
Strings and text send every byte.

The advantage is that printing takes time and e.g. one can use it to measure 
the **print** class performance.

Performance can be increased by implementing all methods of the print interface
with only a return 0; (or at least **print(Type)** as the **println(T)** would only 
call once extra for the "\n".


## Versions

#### 0.1.2

- sets the timeout for reading to 0. No need to wait longer with DEVNULL.
  this improves the **find(...)** calls substantially.
- added **size_t write( const uint8_t \*buffer, size_t size)** for faster string processing.

#### 0.1.4

- add **lastByte()** to check last byte written.
- split of .cpp

## Interface

- **DEVNULL()** constructor, sets the timeout to zero.
- **int available()** always return zero.
- **int peek()** always returns EOF.
- **int read()** always return EOF.
- **void flush()** does nothing but keeps some compilers happy.
- **size_t write(const uint8_t data)** implements print interface. returns 1.
- **size_t write( const uint8_t \*buffer, size_t size)** implements print interface.
Returns size.
- **int lastByte()** returns last byte written (debug and test purpose).


## Operation

Use with care.

See examples.

#### about performance

Writing float or numbers to /dev/null takes substantial time as the values 
are converted to individual bytes. To speed this up one would need to implement
a substantial part of the print class.

On the positive side, this gives a good indication of how long this conversion 
to a stream of bytes takes, making it a valuable analysis tool. So for now this
behavior stays "slow".


## Future

#### Could

- add byte counter (uint32_t)
- investigate if DEVNULL can be used to harvest entropy?


#### Wont

- add delay to mimic pause / tune behaviour for simulating devices
  - microseconds
  - delay per byte, esp long arrays might need other performance
  - out of scope for /dev/null => separate class?
- implement Print class to increase performance?
  - derived class?

