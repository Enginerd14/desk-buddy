#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DHT.h>

const int potPin = 35;
const int buttonPin = 14;
const int tempPin = 4;
const int motionPin = 27;
const int obstaclePin = 26;

#define width 128
#define height 64

bool awake = false;

Adafruit_SSD1306 display(width, height, &Wire, -1);

DHT dht(tempPin, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(motionPin, INPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C ))
  {
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Desk Buddy");
  display.display();
  delay(250);
}

void loop() {

  int LeyeMoveX = random(38,42);
  int ReyeMoveX = LeyeMoveX + 48;
  int YeyeMove = random(33,37);

  
  if (digitalRead(buttonPin) == LOW || digitalRead(motionPin) == HIGH)
  {
    awake = true;
  }
  

  if (awake == false)
  {
    display.clearDisplay();
    display.drawLine(30,32,50,32, WHITE);
    display.drawLine(78,32,98,32, WHITE);
    display.display();
  }


  float temp = dht.readTemperature();

  int sensitivity = analogRead(potPin);
  int tempThreshold = map(sensitivity, 0,4095,20,35);

  bool sweat = false;
  if (temp > tempThreshold)
  {
    sweat = true;
  }

  if (awake == true)
  {
    display.clearDisplay();
    display.fillCircle(40,32,10,WHITE);
    display.fillCircle(88,32,10,WHITE);
    display.fillCircle(LeyeMoveX,YeyeMove,5,BLACK);
    display.fillCircle(ReyeMoveX,YeyeMove,5,BLACK);
    display.display();
  }

  if (awake == true && sweat == true)
  {
    display.clearDisplay();
    display.fillCircle(40,32,10,WHITE);
    display.fillCircle(88,32,10,WHITE);
    display.fillCircle(LeyeMoveX,YeyeMove,5,BLACK);
    display.fillCircle(ReyeMoveX,YeyeMove,5,BLACK);
    display.fillCircle(random(0,40),random(0,15),3,WHITE);
    display.fillCircle(random(0,40),random(0,15),4,WHITE);
    display.fillCircle(random(88,128),random(0,15),2,WHITE);
    display.fillCircle(random(88,128),random(0,15),3,WHITE);
    display.display();
  }
}
