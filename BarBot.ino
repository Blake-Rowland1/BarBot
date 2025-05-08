// Bar-Bot
// Blake Rowland

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


//buttons
const int scrollbutton = 3;
const int selectbutton = 2;

int buttonState1 = 0;
int buttonState2 = 0;

//ingredients - relay 1
int Vodka = 4;
int Rum = 5;
int Grenadine = 6;
int Sprite = 7;

//ingredients - relay 2
int Coke = 8;
int CranberryJuice = 9;
int LemonJuice = 10;
int Gin = 11;

//Misc variables
int TimeBetweenPours = 500;
bool debounce = false;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int page = 0;

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  //buttons
  pinMode(scrollbutton, INPUT_PULLUP);
  pinMode(selectbutton, INPUT_PULLUP);

  //relays
  pinMode(Vodka, OUTPUT);
  pinMode(Rum, OUTPUT);
  pinMode(Grenadine, OUTPUT);
  pinMode(Sprite, OUTPUT);

  pinMode(Coke, OUTPUT);
  pinMode(CranberryJuice, OUTPUT);
  pinMode(LemonJuice, OUTPUT);
  pinMode(Gin, OUTPUT);

  //make sure pumps are off
  digitalWrite(Vodka, HIGH);
  digitalWrite(Rum, HIGH);
  digitalWrite(Grenadine, HIGH);
  digitalWrite(Sprite, HIGH);
  digitalWrite(Coke, HIGH);
  digitalWrite(CranberryJuice, HIGH);
  digitalWrite(LemonJuice, HIGH);
  digitalWrite(Gin, HIGH);

  // Title Screen
  delay(100);
  display.clearDisplay();
  display.setTextSize(3.75);
  display.setTextColor(WHITE);
  display.setCursor(11, 20);
  display.println("BarBot");
  display.display();
  delay(4000);
  display.clearDisplay();
  //
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(10, 10);
  display.println("Select your drink:");
  display.display();
}

void loop() {
  buttonState1 = digitalRead(scrollbutton);
  buttonState2 = digitalRead(selectbutton);

  // select and dispense
  if (buttonState2 == LOW) {
    switch (page) {
      case 1:
        Mix(2000, 0, 1500, 4300, 0, 0, 0, 0);
        break;

      case 2:
        Mix(0, 2000, 0, 0, 5000, 0, 0, 0);
        break;
        /*
              case 3:
                Mix(0, 0, 1500, 0, 0, 0, 0, 0);
                break;

              case 4:
                Mix(0, 0, 0, 1500, 0, 0, 0, 0);
                break;

              case 5:
                Mix(0, 0, 0, 0, 1500, 0, 0, 0);
                break;

              case 6:
                Mix(0, 0, 0, 0, 0, 1500, 0, 0);
                break;

              case 7:
                Mix(0, 0, 0, 0, 0, 0, 1500, 0);
                break;

              case 8:
                Mix(0, 0, 0, 0, 0, 0, 0, 1500);
                break;
        */

    }
  }
  //

  //scroll
  if (buttonState1 == LOW) {
    delay(250);
    page++;
  }
  //
  switch (page) {

    case 1:
      display.clearDisplay();
      display.setTextColor(WHITE);
      display.setTextSize(1);
      display.setFont(NULL);
      display.setCursor(10, 10);
      display.println("Select your drink:");
      display.setCursor(33, 23);
      display.setTextSize(2);
      display.println("Dirty");
      display.setCursor(21, 43);
      display.println("Shirley");
      display.display();
      break;

    case 2:
      display.clearDisplay();
      display.setTextColor(WHITE);
      display.setTextSize(1);
      display.setFont(NULL);
      display.setCursor(10, 10);
      display.println("Select your drink:");
      display.setTextSize(2);
      display.setCursor(5, 28);
      display.println("Rum & Coke");
      display.display();
      break;

    case 3:
      page = 0;   // RESET

      /*
          case 3:
            display.clearDisplay();
            display.setTextColor(WHITE);
            display.setTextSize(1);
            display.setFont(NULL);
            display.setCursor(10, 10);
            display.println("Select your drink:");
            display.setCursor(19, 30);
            display.setTextSize(1);
            display.println("Cranberry Juice");
            display.display();
            break;


          case 4:
            display.clearDisplay();
            display.setTextColor(WHITE);
            display.setTextSize(1);
            display.setFont(NULL);
            display.setCursor(10, 10);
            display.println("Select your drink:");
            display.setCursor(45, 30);
            display.setTextSize(1);
            display.println("Sprite");
            display.display();
            //    delay(200);
            break;

          case 5:
            display.clearDisplay();
            display.setTextColor(WHITE);
            display.setTextSize(1);
            display.setFont(NULL);
            display.setCursor(10, 10);
            display.println("Select your drink:");
            display.setCursor(34, 30);
            display.println("Lime Juice");
            display.display();
            break;

          case 6:
            display.clearDisplay();
            display.setTextColor(WHITE);
            display.setTextSize(1);
            display.setFont(NULL);
            display.setCursor(10, 10);
            display.println("Select your drink:");
            display.setCursor(37, 30);
            display.println("Grenadine");
            display.setCursor(21, 43);
            display.println("");
            display.display();
            break;

          case 7:
            display.clearDisplay();
            display.setTextColor(WHITE);
            display.setTextSize(1);
            display.setFont(NULL);
            display.setCursor(10, 10);
            display.println("Select your drink:");
            display.setCursor(32, 30);
            display.println("Lemon Juice");
            display.display();
            break;

          case 8:
            display.clearDisplay();
            display.setTextColor(WHITE);
            display.setTextSize(1);
            display.setFont(NULL);
            display.setCursor(10, 10);
            display.println("Select your drink:");
            display.setCursor(53, 30);
            display.println("Gin");
            display.display();
            break;

          case 9:
            page = 0;   // RESET
      */

  }
}

void Mix(int DelayTimeVodka, int DelayTimeRum, int DelayTimeGrenadine, int DelayTimeSprite, int DelayTimeCoke, int DelayTimeCranberryJuice, int DelayTimeLemonJuice, int DelayTimeGin) {

  //Screen start
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setFont(NULL);
  display.setCursor(27, 23);
  display.println("Mixing");
  display.display();
  //

  delay(800);
  digitalWrite(Vodka, LOW);
  delay(DelayTimeVodka);
  digitalWrite(Vodka, HIGH);
  delay(TimeBetweenPours);

  digitalWrite(Rum, LOW);
  delay(DelayTimeRum);
  digitalWrite(Rum, HIGH);
  delay(TimeBetweenPours);

  digitalWrite(Grenadine, LOW);
  delay(DelayTimeGrenadine);
  digitalWrite(Grenadine, HIGH);
  delay(TimeBetweenPours);

  digitalWrite(Sprite, LOW);
  delay(DelayTimeSprite);
  digitalWrite(Sprite, HIGH);
  delay(TimeBetweenPours);

  digitalWrite(Coke, LOW);
  delay(DelayTimeCoke);
  digitalWrite(Coke, HIGH);
  delay(TimeBetweenPours);

  digitalWrite(CranberryJuice, LOW);
  delay(DelayTimeCranberryJuice);
  digitalWrite(CranberryJuice, HIGH);
  delay(TimeBetweenPours);

  digitalWrite(LemonJuice, LOW);
  delay(DelayTimeLemonJuice);
  digitalWrite(LemonJuice, HIGH);
  delay(TimeBetweenPours);

  digitalWrite(Gin, LOW);
  delay(DelayTimeGin);
  digitalWrite(Gin, HIGH);
  delay(TimeBetweenPours);

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setFont(NULL);
  display.setCursor(7, 30);
  display.println("Your Drink is Ready");
  display.display();
  delay(4000);

}
