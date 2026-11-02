#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include<WiFi.h>
#include<time.h>
#include "sprites.h"

//display pins
#define TFT_CS     4
#define TFT_RST    3
#define TFT_DC     2
#define TFT_SCK    8
#define TFT_MOSI   10

// Create an instance of the display
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

//Wifi info
const char* ssid = "your_SSID"; // Wi-Fi name
const char* password = "your_PASSWORD"; // Wi-Fi password

//timezone
const char* timezone = "PST8PDT,M3.2.0,M11.1.0"; // PST

void drawCenteredText(const char* text, int y, uint8_t size, uint16_t color) {
  tft.setTextSize(size);
  tft.setTextColor(color);
  int16_t x1, y1;
  uint16_t w, h;
  tft.getTextBounds(text, 0, y, &x1, &y1, &w, &h);

  int x =(240 - w) / 2; // Center horizontally
  tft.setCursor(x, y);
  tft.print(text);
}
void setup() {
  Serial.begin(115200);
  
  SPI.begin(TFT_SCK, -1, TFT_MOSI, TFT_CS); 

  //display
  tft.init(240,320);
  tft.setRotation(0);
  tft.fillScreen(ST77XX_BLACK);
  drawCenteredText("PokéClock", 35, 2, ST77XX_YELLOW);
  drawCenteredText("Connecting to Wi-Fi...", 140, 1, ST77XX_WHITE);
  tft.drawRGBBitmap(100, 80, pickachu, 32, 32);
  tft.drawRGBBitmap(100, 120, pokemon_sprite, 32, 32);
  tft.drawRGBBitmap(100, 120, charmander, 32, 32);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
}

  Serial.println("WiFi connected");
  drawCenteredText("Wi-Fi Connected!", 140, 1, ST77XX_WHITE);

  setenv("TZ", timezone, 1);
  tzset();

  //set time with internet
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  struct tm timeinfo;

  while (!getLocalTime(&timeinfo)) {
    delay(500);
    Serial.println("waiting for time...");
  }
  Serial.println("Time synchronized");
  drawCenteredText("Time synchronized!", 140, 1, ST77XX_WHITE);
  delay(2000);
  tft.fillScreen(ST77XX_BLACK);
}

void loop(){

  struct tm timeinfo;

  //Get the time
  if (!getLocalTime(&timeinfo)) {
    return;
}

char timeText[20];
char dateText[30];
char dayText[20];

strftime (timeText, sizeof(timeText), "%H:%M:%S", &timeinfo);

strftime (dateText, sizeof(dateText), "%B %d, %Y", &timeinfo);

strftime (dayText, sizeof(dayText), "%A", &timeinfo);
// Clear the screen
tft.fillScreen(ST77XX_BLACK);

drawCenteredText("PokéClock", 5, 2, ST77XX_YELLOW);
drawCenteredText(dayText, 35, 2, ST77XX_WHITE);
drawCenteredText(dateText, 80, 1, ST77XX_WHITE);
drawCenteredText(timeText, 125, 2, ST77XX_WHITE);
delay(1000); 

}