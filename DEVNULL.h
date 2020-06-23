#pragma once
//
//    FILE: DEVNULL.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: Arduino library for a /dev/null stream - usefull for testing
//     URL: https://github.com/RobTillaart/DEVNULL
//
// HISTORY:
// 0.1.0    2020-06-23 initial version

#include "Arduino.h"

class DEVNULL : public Stream
{
public:
  DEVNULL() {};

  int available() { return 0; };
  int peek()      { return EOF; };
  int read()      { return EOF; };
  size_t write(const uint8_t data) { bottomLessPit = data; return 0; };

private:
  uint8_t bottomLessPit;
};

// -- END OF FILE --
