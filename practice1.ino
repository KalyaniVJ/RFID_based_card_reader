#include <SPI.h>
#include <MFRC522.h>
#include <stdlib.h>

#define RST_PIN         9
#define SS_PIN          10

String inStringHex = "";

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}
void loop() {
  // Look for new cards
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
  {
    //Serial.print("Card UID:");
    for (byte i = 0; i < 4; i++) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      inStringHex += String(mfrc522.uid.uidByte[i], HEX);
    }

    Serial.println();
    Serial.println(F("Hex normal"));
    Serial.print(inStringHex);
    Serial.println();
    Serial.println();

    inStringHex = "";
    delay(5000);
  }
}
