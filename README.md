# UUIDGenerator Library

The UUIDGenerator library provides a simple way to generate Version 1, 2, 3, and 4 UUIDs on ESP32 and ESP8266 microcontrollers. UUIDs (Universally Unique Identifiers) are commonly used as unique identifiers in various applications.

## Installation

1. Download the `UUIDGenerator` library folder.
2. Copy the `UUIDGenerator` folder into your Arduino libraries folder. This is typically located at `Documents\Arduino\libraries`.
3. Restart the Arduino IDE.

## Usage

1. Include the `UUIDGenerator` library in your Arduino sketch:

   ```cpp
   #include <UUIDGenerator.h>
   ```

2. Create an instance of the `UUIDGenerator` class:

   ```cpp
   UUIDGenerator uuidGen;
   ```

3. Generate a Version 1, 2, 3, or 4 UUID:

   ```cpp
   // Version 1 (Time-based) UUID
   String uuidv1 = uuidGen.generateUUIDv1();

   // Version 2 (DCE Security) UUID
   String uuidv2 = uuidGen.generateUUIDv2();

   // Version 3 (Name-based, MD5 hash) UUID
   String uuidv3 = uuidGen.generateUUIDv3("namespace", "name");

   // Version 4 (Random) UUID
   String uuidv4 = uuidGen.generateUUIDv4();
   ```

4. Use the generated UUID as needed in your application.

## Example Sketch

```cpp
#include <UUIDGenerator.h>

UUIDGenerator uuidGen;

void setup() {
  Serial.begin(115200);
  Serial.println();
  
  // Version 1 UUID
  Serial.println("Generating UUID v1...");
  String uuidv1 = uuidGen.generateUUIDv1();
  Serial.println(uuidv1);

  // Version 2 UUID
  Serial.println("Generating UUID v2...");
  String uuidv2 = uuidGen.generateUUIDv2();
  Serial.println(uuidv2);

  // Version 3 UUID
  Serial.println("Generating UUID v3...");
  String uuidv3 = uuidGen.generateUUIDv3("namespace", "name");
  Serial.println(uuidv3);

  // Version 4 UUID
  Serial.println("Generating UUID v4...");
  String uuidv4 = uuidGen.generateUUIDv4();
  Serial.println(uuidv4);
}

void loop() {
  // Put your main code here, to run repeatedly:
}
```

## Contributing

Contributions to this library are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request on GitHub.

## License

This library is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
