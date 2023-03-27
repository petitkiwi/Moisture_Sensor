#include <Wire.h> // I2C communication
#include <Adafruit_SSD1306.h> // for the type of screen used, here SSD1306
// #include <Adafruit_GFX.h> // to write on the screen as well
// #include <SD.h> // for writing to file

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// display: instance of the Adafruit SSD1206 class
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int SENSOR = A0; // Arduino pin that connects to pin of moisture sensor
int LED = 4;

void setup() {
  // Arduino to pc com
  Serial.begin(9600);
  // define LED io
  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT);

  // check that Arduino communicates properly with the right screen
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){ 
    Serial.println("Allocation failed");
    for(;;);
  }

  // // initialize USB serial connection
  // while (!Serial) {
  //   ; // wait for serial port to connect
  // }
}

void loop() {
  int value = analogRead(SENSOR); // read the analog value from the sensor
  int moisture = map(value, 760,480,0,100);

  Serial.print("Humidity: ");
  Serial.print(moisture);
  Serial.println("%");

  // // write moisture data to CSV file on USB drive
  // File dataFile = SD.open("moisture.csv", FILE_WRITE);
  // if (dataFile) {
  //   dataFile.print(millis());
  //   dataFile.print(",");
  //   dataFile.println(moisture);
  //   dataFile.close();
  // } else {
  //   Serial.println("Error opening file");
  // }

  // setup: clear, color and size of text 
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);

  // setCursor: where the text starts in the screen coordinates
  display.setCursor(0,1);
  display.println("Hello Kiwi!");

  display.setTextSize(1);
  display.setCursor(0,23);
  display.print("Humidity Status: ");

  int ledIntensity = map(moisture, 0, 100, 0, 255); // Map the moisture value to LED brightness
  analogWrite(LED, ledIntensity); // Set the LED brightness
    
  if (moisture > 50)
  {
    //digitalWrite(LED, HIGH);
    display.print("WET");    
  }
  else
  {
    //digitalWrite(LED, LOW);
    display.print("DRY");
  }

  // Print moisture percentage at the bottom of the screen
  display.setCursor(0,44);
  display.setTextSize(2);
  display.print(moisture);
  display.print("%");

  display.display(); // update display

  delay(500); 
}
