#include <SPI.h>
#include <GxEPD2_BW.h>

// Connections for Adafruit ESP32 Feather
static const uint8_t EPD_BUSY = 13;  // to EPD BUSY
static const uint8_t EPD_CS   = 27;  // to EPD CS
static const uint8_t EPD_RST  = 12; // to EPD RST
static const uint8_t EPD_DC   = 14; // to EPD DC
static const uint8_t EPD_SCK  = 25; // to EPD CLK
static const uint8_t EPD_MISO = 19; // Master-In Slave-Out not used, as no data from display
static const uint8_t EPD_MOSI = 26; // to EPD DIN

GxEPD2_BW<GxEPD2_583_T8, GxEPD2_583_T8::HEIGHT> display(GxEPD2_583_T8(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));

void setup() {

  // Initialize SPI
  SPI.begin(EPD_SCK, EPD_MISO, EPD_MOSI, EPD_CS);

  // Initialize display and font
  display.init();
  display.setRotation(1);     // landscape orientaion 
  display.setFullWindow();  
  display.setFont();
  display.setTextColor(GxEPD_WHITE, GxEPD_WHITEGxEPD_BLACK); 
  display.setTextSize(4);

  // Write something to display buffer
  display.fillScreen(GxEPD_WHITE); 
  display.setCursor(2, 20); 
  display.print("30 July 2021"); 
  
  display.setCursor(5, 50); 
  display.print("CDE"); 

  // Update display
  display.display();
  display.fillScreen(GxEPD_WHITE); 
  display.display();
}

void loop() {
  // These aren't the droids you're looking for. 
}
