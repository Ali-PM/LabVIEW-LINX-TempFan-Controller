#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2     // پایه اتصال DATA سنسور DS18B20
#define FAN_PIN 9          // پایه PWM برای فن یا موتور (مثلاً 9)

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float tempC;
char Serialdata;

void setup() {
  Serial.begin(9600);
  sensors.begin();              
  pinMode(FAN_PIN, OUTPUT);     
  analogWrite(FAN_PIN, 0);      // در ابتدا فن خاموش باشد
}

void loop() {
  sensors.requestTemperatures();              
  tempC = sensors.getTempCByIndex(0);         

  // ارسال دما به سریال مانیتور
  Serial.println(tempC);                      

  // شرط دما برای کنترل سرعت فن
  if (tempC > 25) {
    analogWrite(FAN_PIN, 255);   // سرعت زیاد (PWM بین 0 تا 255)
    Serial.println("Fan:FAST");
  } else {
    analogWrite(FAN_PIN, 100);   // سرعت کم
    Serial.println("Fan:SLOW");
  }

  // دریافت فرمان سریال برای کنترل دستی فن
  if (Serial.available()) {
    Serialdata = Serial.read();

    if (Serialdata == '1') {
      analogWrite(FAN_PIN, 255); // فن سریع
      Serial.println("Fan forced FAST");
    }

    if (Serialdata == '2') {
      analogWrite(FAN_PIN, 0);   // فن خاموش
      Serial.println("Fan forced OFF");
    }
  }

  delay(1000); 
}
