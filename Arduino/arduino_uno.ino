#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Servo.h>
#include <SoftwareSerial.h>

// Pinlar
#define DHTPIN 2       // DHT-22 sensorining pin raqami
#define DHTTYPE DHT22  // DHT-22
#define RELAY_PIN 3    // Relay pin raqami
#define SERVO_PIN 4    // Servo pin raqami
#define SOIL_MOISTURE_PIN A0 // Tuproq namligi sensori pin raqami
#define BLUETOOTH_RX 10 // Bluetooth RX pin
#define BLUETOOTH_TX 11 // Bluetooth TX pin

// O'zgaruvchilar
int soilMoistureThreshold = 300; // Tuproq namligi uchun chegaraviy qiymat

// Ob'ektlar
LiquidCrystal_I2C lcd(0x27, 16, 4);
DHT dht(DHTPIN, DHTTYPE);
Servo myservo;
SoftwareSerial bluetooth(BLUETOOTH_RX, BLUETOOTH_TX);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  dht.begin();
  myservo.attach(SERVO_PIN);
  pinMode(RELAY_PIN, OUTPUT);
  bluetooth.begin(9600);
}

void loop() {
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  lcd.setCursor(0, 0);
  lcd.print("Yer Namligi: ");
  lcd.print(soilMoistureValue);

  lcd.setCursor(0, 1);
  lcd.print("Harorat: ");
  lcd.print(temp);
  lcd.print(" C");

  lcd.setCursor(0, 2);
  lcd.print("Namlik: ");
  lcd.print(hum);
  lcd.print(" %");


  Serial.print("Yer Namligi: ");
  Serial.print(soilMoistureValue);


  Serial.print("Harorat: ");
  Serial.print(temp);
  Serial.print(" C");


  Serial.print("Namlik: ");
  Serial.print(hum);
  Serial.println(" %");
  if (soilMoistureValue > soilMoistureThreshold) {
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    digitalWrite(RELAY_PIN, LOW);
  }

  if (bluetooth.available()) {
    char cmd = bluetooth.read();
    switch (cmd) {
      case '1':
        digitalWrite(RELAY_PIN, HIGH);
        break;
      case '2':
        digitalWrite(RELAY_PIN, LOW);
        break;
      case '3':
        myservo.write(90);
        break;
      case '4':
        myservo.write(0);
        break;
    }
  }

  if (temp > 25) {
    myservo.write(90);
  } else if (temp < 18) {
    myservo.write(0);
  }

  delay(1000);
}
