#include "Arduino.h"
#include <Ps3Controller.h>

#ifndef INC_PS3_UART_ESP_H_
#define INC_PS3_UART_ESP_H_


class PS3 {
  public:
    Stream* streamPtr;

    PS3();
    void begin(Stream* streamPtr);
    void notify();
};




#endif
