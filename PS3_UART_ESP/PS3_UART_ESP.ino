#include"PS3_UART_ESP.h"
#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4
#define TRIANGLE 5
#define CIRCLE 6
#define CROSS 7
#define SQUARE 8
#define L1 9
#define R1 10
#define L2 11
#define R2 12
#define LX 13
#define LY 14
#define RX 15
#define RY 16
#define serial Serial2

uint8_t rxBuffer[35] = {0};
uint8_t txBuffer[20] = {0};
uint8_t dataLength = 0;
uint8_t txdBuffer[35] = {0};

void setup() {
  serial.begin(115200);
  Serial.begin(115200);
  while (serial.available() == 0) {
    Serial.println(serial.available());
  }
  dataLength =  serial.readBytesUntil('0', rxBuffer, 35);
  Serial.println(dataLength);
  char macAddBuffer[18] = {0};
  for (int i = 0; i < 17; i++) {
    macAddBuffer[i] = rxBuffer[i];
    Serial.println(macAddBuffer);
  }
  Ps3.begin(macAddBuffer);
  delay(1000);
}


void loop() {
  txBuffer[0] = Ps3.data.button.up ? txBuffer[0] | 1 << 0 : txBuffer[0] & ~(1 << 0);
  txBuffer[0] = Ps3.data.button.right ? txBuffer[0] | 1 << 1 : txBuffer[0] & ~(1 << 1);
  txBuffer[0] = Ps3.data.button.down ? txBuffer[0] | 1 << 2 : txBuffer[0] & ~(1 << 2);
  txBuffer[0] = Ps3.data.button.left ? txBuffer[0] | 1 << 3 : txBuffer[0] & ~(1 << 3);
  txBuffer[0] = Ps3.data.button.select ? txBuffer[0] | 1 << 4 : txBuffer[0] & ~(1 << 4);
  txBuffer[0] = Ps3.data.button.start ? txBuffer[0] | 1 << 5 : txBuffer[0] & ~(1 << 5);
  txBuffer[1] = Ps3.data.button.triangle ? txBuffer[1] | 1 << 0 : txBuffer[1] & ~(1 << 0);
  txBuffer[1] = Ps3.data.button.circle ? txBuffer[1] | 1 << 1 : txBuffer[1] & ~(1 << 1);
  txBuffer[1] = Ps3.data.button.cross ? txBuffer[1] | 1 << 2 : txBuffer[1] & ~(1 << 2);
  txBuffer[1] = Ps3.data.button.square ? txBuffer[1] | 1 << 3 : txBuffer[1] & ~(1 << 3);
  txBuffer[1] = Ps3.data.button.ps ? txBuffer[1] | 1 << 4 : txBuffer[1] & ~(1 << 4);
  txBuffer[2] = Ps3.data.button.l1 ? txBuffer[2] | 1 << 0 : txBuffer[2] & ~(1 << 0);
  txBuffer[2] = Ps3.data.button.l2 ? txBuffer[2] | 1 << 1 : txBuffer[2] & ~(1 << 1);
  txBuffer[2] = Ps3.data.button.l3 ? txBuffer[2] | 1 << 2 : txBuffer[2] & ~(1 << 2);
  txBuffer[2] = Ps3.data.button.r1 ? txBuffer[2] | 1 << 3 : txBuffer[2] & ~(1 << 3);
  txBuffer[2] = Ps3.data.button.r2 ? txBuffer[2] | 1 << 4 : txBuffer[2] & ~(1 << 4);
  txBuffer[2] = Ps3.data.button.r3 ? txBuffer[2] | 1 << 5 : txBuffer[2] & ~(1 << 5);
  //  Serial.print(txBuffer[0], BIN);
  //  Serial.print(txBuffer[1], BIN);
  //  Serial.println(txBuffer[2], BIN);
  //  Serial.println();
  for (uint8_t i = 0; i < abs(dataLength - 17); i++) {
    switch (rxBuffer[i + 17])
    {
      case UP:
        txBuffer[i + 3] = Ps3.data.analog.button.up;
        break;
      case RIGHT:
        txBuffer[i + 3] = Ps3.data.analog.button.right;
        break;
      case DOWN:
        txBuffer[i + 3] = Ps3.data.analog.button.down;
        break;
      case LEFT:
        txBuffer[i + 3] = Ps3.data.analog.button.left;
        break;
      case TRIANGLE:
        txBuffer[i + 3] = Ps3.data.analog.button.triangle;
        break;
      case CIRCLE:
        txBuffer[i + 3] = Ps3.data.analog.button.circle;
        break;
      case CROSS:
        txBuffer[i + 3] = Ps3.data.analog.button.cross;
        break;
      case SQUARE:
        txBuffer[i + 3] = Ps3.data.analog.button.square;
        break;
      case L1:
        txBuffer[i + 3] = Ps3.data.analog.button.l1;
        break;
      case L2:
        txBuffer[i + 3] = Ps3.data.analog.button.l2;
        break;
      case R1:
        txBuffer[i + 3] = Ps3.data.analog.button.r1;
        break;
      case R2:
        txBuffer[i + 3] = Ps3.data.analog.button.r2;
        break;
      case LX:
        txBuffer[i + 3] = Ps3.data.analog.stick.lx + 128;
        break;
      case LY:
        txBuffer[i + 3] = Ps3.data.analog.stick.ly + 128;
        break;
      case RX:
        txBuffer[i + 3] = Ps3.data.analog.stick.rx + 128;
        break;
      case RY:
        txBuffer[i + 3] = Ps3.data.analog.stick.ry + 128;
        break;

    }
  }

  //  for (int i = 0; i < 20; i++) {
  //    Serial.print(txBuffer[i]);
  Serial.println(abs(dataLength - 14));
  //  }
  bool flag = 0;
  for (uint8_t i = 0; i < abs(dataLength - 14); i++) {

    if (txBuffer[i] == txdBuffer[i]);
    else {
      flag = 1;
    }
    txdBuffer[i] = txBuffer[i];
    Serial.print(txdBuffer[i]);
    Serial.print("  ");
  }
  if (flag == 1) {
//    Serial.println("flag");
    serial.write(txBuffer, 19);
  }
  delay(50);
}
