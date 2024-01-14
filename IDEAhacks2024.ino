#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

DFRobotDFPlayerMini myDFPlayer;

const int button1 = 8;  // the number of the pushbutton pin
const int button2 = 9;
const int button3 = 10;
const int button4 = 11;
const int button5 = 12;
const int button6 = 13;


int State1 = 0;  // variable for reading the pushbutton status
int State2 = 0;
int State3 = 0;
int State4 = 0;
int State5 = 0;
int State6 = 0;

int x = 0;
int y = 0;


void setup() 
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  Serial.begin(9600);
  Serial1.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) 
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  delay(200); // Pause for 2 seconds
  display.clearDisplay();

  myDFPlayer.begin(Serial1);
  myDFPlayer.volume(20);
}


void loop() 
{
  State1 = digitalRead(button1);
  delay(25);
  State2 = digitalRead(button2);
  delay(25);
  State3 = digitalRead(button3);
  delay(25);
  State4 = digitalRead(button4);
  delay(25);
  State5 = digitalRead(button5);
  delay(25);
  State6 = digitalRead(button6);
  delay(25);

  if(x >= 120)
  {
    x = 0;
    y += 16;
  }

  display.setCursor(x, y);
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);

  char c = '0';
  int fileNum = 0;

  if (State1 == HIGH && State2 == LOW &&  State3 == LOW &&  State4 == LOW &&  State5 == LOW &&  State6 == LOW) 
  {
    c = 'A';
    /* myDFPlayer.play(fileNum + (c-'A'));
    Serial.print(c);
    display.println(F(c));
    x += 12;
    display.display();      // Show initial text
    delay(100); */
  } 
  else if ( State1 == HIGH &&  State2 == HIGH &&  State3 == LOW &&  State4 == LOW &&  State5 == LOW &&  State6 == LOW) 
  {
    c = 'B';
  } 
  else if ( State1 == HIGH &&  State2 == LOW &&  State3 == LOW &&  State4 == HIGH &&  State5 == LOW &&  State6 == LOW) 
  {
    c = 'C';
  } 
  else if ( State1 == HIGH &&  State2 == LOW &&  State3 == LOW &&  State4 == HIGH &&  State5 == HIGH &&  State6 == LOW) 
  {
    c ='D';
  } 
  else if ( State1 == HIGH &&  State2 == LOW &&  State3 == LOW &&  State4 == LOW &&  State5 == HIGH &&  State6 == LOW) 
  {
    c = 'E';
  }
  else if ( State1 == HIGH &&  State2 == HIGH &&  State3 == LOW &&  State4 == HIGH &&  State5 == LOW &&  State6 == LOW) 
  {
    c = 'F';
  }
  else if ( State1 == HIGH &&  State2 == HIGH &&  State3 == LOW &&  State4 == HIGH &&  State5 == HIGH &&  State6 == LOW) 
  {
    c = 'G';
  }
  else if ( State1 == HIGH &&  State2 == HIGH &&  State3 == LOW &&  State4 == LOW &&  State5 == HIGH &&  State6 == LOW) 
  {
    c = 'H';
  }
  else if ( State1 == LOW &&  State2 == HIGH &&  State3 == LOW &&  State4 == HIGH &&  State5 == LOW &&  State6 == LOW) 
  {
    c = 'I';
  }
  else if ( State1 == LOW &&  State2 == HIGH &&  State3 == LOW &&  State4 == HIGH &&  State5 == HIGH &&  State6 == LOW) 
  {
    c = 'J';
  }
  else if ( State1 == HIGH &&  State2 == LOW &&  State3 == HIGH &&  State4 == LOW &&  State5 == LOW &&  State6 == LOW) 
  {
    c = 'K';
  }
  else if ( State1 == HIGH &&  State2 == HIGH &&  State3 == HIGH &&  State4 == LOW &&  State5 == LOW &&  State6 == LOW) 
  {
    c = 'L';
  }
  else if ( State1 == HIGH &&  State2 == LOW &&  State3 == HIGH &&  State4 == HIGH &&  State5 == LOW &&  State6 == LOW) 
  {
    c = 'M';
  }
  else if ( State1 == HIGH &&  State2 == LOW &&  State3 == HIGH &&  State4 == HIGH &&  State5 == HIGH &&  State6 == LOW) 
  {
    c = 'N';
  }
  else if ( State1 == HIGH &&  State2 == LOW &&  State3 == HIGH &&  State4 == LOW &&  State5 == HIGH &&  State6 == LOW) 
  {
    c = 'O';
  }
  else if ( State1 == HIGH &&  State2 == HIGH &&  State3 == HIGH &&  State4 == HIGH &&  State5 == LOW &&  State6 == LOW) 
  {
    c = 'P';
  }
  else if ( State1 == HIGH &&  State2 == HIGH &&  State3 == HIGH &&  State4 == HIGH &&  State5 == HIGH &&  State6 == LOW) 
  {
    c = 'Q';
  }
  else if ( State1 == HIGH &&  State2 == HIGH &&  State3 == HIGH &&  State4 == LOW &&  State5 == HIGH &&  State6 == LOW) 
  {
    c = 'R';
  }
  else if ( State1 == LOW &&  State2 == HIGH &&  State3 == HIGH &&  State4 == HIGH &&  State5 == LOW &&  State6 == LOW) 
  {
    c = 'S';
  }
  else if ( State1 == LOW &&  State2 == HIGH &&  State3 == HIGH &&  State4 == HIGH &&  State5 == HIGH &&  State6 == LOW) 
  {
    c = 'T';
  }
  else if ( State1 == HIGH &&  State2 == LOW &&  State3 == HIGH &&  State4 == LOW &&  State5 == LOW &&  State6 == HIGH) 
  {
    c = 'U';
  }
  else if ( State1 == HIGH &&  State2 == HIGH &&  State3 == HIGH &&  State4 == LOW &&  State5 == LOW &&  State6 == HIGH) 
  {
    c = 'V';
  }
  else if ( State1 == LOW &&  State2 == HIGH &&  State3 == LOW &&  State4 == HIGH &&  State5 == HIGH &&  State6 == HIGH) 
  {
    c = 'W';
  }
  else if ( State1 == HIGH &&  State2 == LOW &&  State3 == HIGH &&  State4 == HIGH &&  State5 == LOW &&  State6 == HIGH) 
  {
    c = 'X';
  }
  else if ( State1 == HIGH &&  State2 == LOW &&  State3 == HIGH &&  State4 == HIGH &&  State5 == HIGH &&  State6 == HIGH) 
  {
    c = 'Y';
  }
  else if ( State1 == HIGH &&  State2 == LOW &&  State3 == HIGH &&  State4 == LOW &&  State5 == HIGH &&  State6 == HIGH) 
  {
    c = 'Z';
  }
  else if ( State1 == LOW &&  State2 == LOW &&  State3 == LOW &&  State4 == LOW &&  State5 == LOW &&  State6 == HIGH) 
  {
    c = ' ';
  }
  else if ( State1 == LOW &&  State2 == LOW &&  State3 == LOW &&  State4 == LOW &&  State5 == HIGH &&  State6 == LOW) 
  {
    c = '.';
  }
  else if (State1 == HIGH &&  State2 == HIGH &&  State3 == HIGH &&  State4 == HIGH &&  State5 == HIGH &&  State6 == HIGH) 
  {
    display.clearDisplay();
    display.display();   
    x = y = 0;
    delay(100);
    return;
  }
  else
  {
    delay(100);
    return;
  }

  fileNum = c -'A' + 18;
  if(fileNum >= 27)
  {
    fileNum -= 26;
  }
  myDFPlayer.play(fileNum);
  Serial.print(c);
  display.print(c);
  x += 12;
  display.display();      // Show initial text
  delay(100);
}

