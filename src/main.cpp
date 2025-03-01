#include "config.h"
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <BlynkSimpleEsp32.h>
#include <WiFi.h>

DHT dht(16, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define BALL_SWITCH_PIN 17

#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

void setup() {
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);

    Serial.begin(9600);
    Serial.println("DHT11 dan Ball Switch Monitoring");

    dht.begin();
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Monitoring...");
    delay(2000);

    pinMode(BALL_SWITCH_PIN, INPUT);

    // Mulai koneksi ke Blynk
    WiFi.begin(ssid, pass);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
    Blynk.run(); 

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Gagal membaca dari sensor DHT!");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("DHT Error!");
        delay(2000);
        return;
    }

    int ballState = digitalRead(BALL_SWITCH_PIN);

    if (ballState == HIGH) {
        Serial.println("⚠️ Benda Jatuh! ⚠️");

        lcd.clear();
        lcd.setCursor(3, 0);
        lcd.print("Benda Jatuh!");
        lcd.setCursor(0, 1);
        lcd.print("Cek kondisi!");

        // Kirim notifikasi ke Blynk
        Blynk.logEvent("plant_notification_", "Periksa tanaman anda!");

        delay(3000);
    }

    Serial.print("🌡 Suhu: ");
    Serial.print(temperature);
    Serial.print("°C | 💧 Kelembaban: ");
    Serial.print(humidity);
    Serial.print("% | Ball Switch: ");
    Serial.println(ballState == HIGH ? "⚠️ Jatuh ⚠️" : "✅ Stabil");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Suhu: ");
    lcd.print(temperature);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("Kelembaban: ");
    lcd.print(humidity);
    lcd.print("%");

    Blynk.virtualWrite(V0, temperature);
    Blynk.virtualWrite(V1, humidity);
    Blynk.virtualWrite(V2, ballState);

    delay(2000);
}
