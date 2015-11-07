

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

Servo servo1;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.
int state = 0;
int ST_SEARCH = 0;
int ST_BUSY = 1;
int servo_angle = 40;
int servo_angle1 = 80;

void setup() {
  Serial.begin(9600); // Initialize serial communications with the PC
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card
  Serial.println("Scan PICC to see UID and type...");
  servo1.attach(14);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  if(state == ST_SEARCH){
    servo1.write(servo_angle1);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
    }
    
    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
    }
    // Dump debug info about the card. PICC_HaltA() is automatically called.
    //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
    Serial.println("Nueva tarjeta");
    state = ST_BUSY;
  }else if(state == ST_BUSY){
    digitalWrite(5, LOW);
    for(int i = 0; i < 5; i++){
        digitalWrite(6, HIGH);
        servo1.write(servo_angle1);
        delay(100);
        digitalWrite(6, LOW);
        delay(100);
        digitalWrite(6, HIGH);
        delay(100);
        digitalWrite(6, LOW);
        delay(100);
        digitalWrite(6, HIGH);
        servo1.write(servo_angle);
        delay(100);
        digitalWrite(6, LOW);
        delay(100);
        digitalWrite(6, HIGH);
        delay(100);
        digitalWrite(6, LOW);
        delay(100);
        digitalWrite(6, HIGH);
        delay(100);
        digitalWrite(6, LOW);
    }
    state = ST_SEARCH;
  }
  
}
