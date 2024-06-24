#ifndef UUIDGenerator_h
#define UUIDGenerator_h

#include <Arduino.h>

class UUIDGenerator {
  public:
    UUIDGenerator();
    String generateUUIDv1();
    String generateUUIDv2();
    String generateUUIDv3(String namespaceUUID, String name);
    String generateUUIDv4();

  private:
    String generateUUID(uint8_t version);
    uint32_t getUnixTime();
    uint16_t getClockSequence();
};

#endif
