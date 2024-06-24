#include "UUIDGenerator.h"
#include <time.h>

UUIDGenerator::UUIDGenerator() {
  srand(time(0));
}

String UUIDGenerator::generateUUIDv1() {
  return generateUUID(1);
}

String UUIDGenerator::generateUUIDv2() {
  return generateUUID(2);
}

String UUIDGenerator::generateUUIDv3(String namespaceUUID, String name) {
  // For simplicity, this function returns an empty string
  // as generating a UUIDv3 requires additional hashing logic.
  // This function should be implemented according to the requirements.
  return "";
}

String UUIDGenerator::generateUUIDv4() {
  return generateUUID(4);
}

String UUIDGenerator::generateUUID(uint8_t version) {
  uint32_t r[4];
  for (int i = 0; i < 4; i++) {
    r[i] = esp_random();
  }

  // Construct UUID from random values
  char uuid[37];
  snprintf(uuid, sizeof(uuid),
           "%08x-%04x-%04x-%04x-%012x",
           r[0], // 8 hex digits
           r[1] >> 16, // 4 hex digits
           (r[1] & 0x0FFF) | (version << 12), // 4 hex digits, the first one is version
           (r[2] >> 16) | 0x8000, // 4 hex digits, the first one is always 8, 9, A, or B
           ((uint64_t)r[2] << 32) | r[3]); // 12 hex digits

  return String(uuid);
}

uint32_t UUIDGenerator::getUnixTime() {
  time_t now;
  time(&now);
  return (uint32_t)now;
}

uint16_t UUIDGenerator::getClockSequence() {
  // Simulate a clock sequence
  return (uint16_t)rand();
}
