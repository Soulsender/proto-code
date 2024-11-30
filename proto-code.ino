 /*
  Version 3.1   Last update: 11-02-2020
  This code will control the Left and right of the protogen helmet matrices.

  The library for controlling the matrices has to be added to the Arduino IDE before the code can work. The library
  that comes with this code has been modified so that you can link up to 14 matrices instead of 10.

  If you ever need help or something doesn't work, send me an e-mail to feronium128@gmail.com
  or contact me on twitter @Feronium

  Below are the pieces of code listed to show the icons. A '0' means the LED is turned off,
  a '1' means the LED will be turned on.
  I'd recommend using the website linked below to make custom icons if you want
  and then copy the code below here, replacing the icons that are already listed.
  https://xantorohara.github.io/led-matrix-editor
  you can also easily turn the icons 90 or 180 degrees on this website if the matrix does not show the right orientation.

  Also please contact me if you something isn't working properly so it can be fixed in the next update.


  Have fun!

*/
#include <MaxMatrix.h>

/* If you would like to use a hall effect sensor (magnet sensor) to turn off the LED-matrices when the
   visor is taken off, you can uncomment the line below by deleting the 2 slashes. */
//#define visorSensor

//Right side of the helmet
char noseRight[] =  {8, 8, B00000000, B00000000, B10000000, B11000000, B11000000, B11111100, B01111110, B00000000};
char icon01[] =     {8, 8, B00100000,B01111000,B11011110,B11000111,B11111111,B00000000,B00000000,B00000000};
char icon02[] =     {8, 8, B00000000,B00000000,B00000000,B10000000,B11100000,B01111000,B00011110,B00000111};
char icon03[] =     {8, 8,  B00000000,B00000000,B00000000,B00000000,B00000111,B00011110,B01111000,B11100000};
char icon04[] =     {8, 8, B00000000,B00000000,B00000000,B11100000,B11111000,B00011110,B00000111,B00000001};
char Glitch01[] =   {8, 8, B00001100, B00000000, B11010100, B10001001, B00010100, B01000111, B11010001, B10100101};
char Glitch011[] =  {8, 8, B00000000, B00000000, B00000000, B11010101, B10000101, B11101010, B00010111, B00000100};
char Glitch02[] =   {8, 8, B01110100, B00000000, B01001011, B10010110, B00010010, B00000000, B00000000, B00000000};
char Glitch022[] =  {8, 8, B10100010, B01010100, B10000110, B00010010, B00000101, B00000000, B00000000, B00000000};
char Glitch03[] =   {8, 8, B00101001, B10101001, B01001011, B00101100, B01110100, B00000000, B00000000, B00000000};
char Glitch033[] =  {8, 8, B01001101, B10011010, B01101001, B10100000, B00001000, B00000000, B00000000, B00000000};
char Glitch04[] =   {8, 8, B00000000, B00000000, B10010101, B10011010, B10010111, B11101010, B10111010, B11010000};
char Glitch044[] =  {8, 8, B00000000, B00000000, B10001000, B10101010, B00011011, B10010101, B00000001, B00000000};
char Eye02[] =      {8, 8, B00000000, B00000000, B00000110, B00001111, B11111111, B11111110, B11111100, B11110000};
char Eye01[] =      {8, 8, B00000000, B00000000, B10000000, B11100000, B01111111, B00011111, B00000111, B00000000};
char Angry1[] =     {8, 8, B00000000, B11000000, B11110000, B11111000, B11111100, B11111100, B11111000, B00000000};
char Angry2[] =     {8, 8, B00000000, B00000001, B00000111, B00011111, B00111111, B01111111, B00111111, B00000000};
char Spooked1[] =   {8, 8, B00000001, B00000111, B00000111, B00001111, B00001111, B00000111, B00000111, B00000001};
char Spooked2[] =   {8, 8, B10000000, B11100000, B11100000, B11110000, B11110000, B11100000, B11100000, B10000000};

//Left side of the helmet
char noseLeft[] =   {8, 8, B00000000, B00000000, B00000001, B00000011, B00000011, B00111111, B01111110, B00000000};
char icon01L[] =    {8, 8, B00001000, B00011110, B01111011, B11100011, B11111111, B00000000, B00000000, B00000000};
char icon02L[] =    {8, 8, B00000000, B00000000, B00000000, B00000001, B00000111, B00011110, B01111000, B11100000};
char icon03L[] =    {8, 8, B00000000, B00000000, B00000000, B00000000, B11100000, B01111000, B00011110, B00000111};
char icon04L[] =    {8, 8, B00000000, B00000000, B00000000, B00000111, B00011111, B01111000, B11100000, B10000000};
char Glitch01L[] =  {8, 8, B10100101, B11010001, B01000111, B00001010, B10001001, B11010100, B00001100, B00000000};
char Glitch011L[] = {8, 8, B00000000, B00000000, B00000000, B10101011, B10100001, B01010111, B11101000, B00100000};
char Glitch02L[] =  {8, 8, B00000000, B00000000, B00000000, B00000000, B00010010, B10010110, B01001011, B01110100};
char Glitch022L[] = {8, 8, B00000000, B00000000, B00000000, B00000101, B00010010, B10000110, B01010100, B10100010};
char Glitch03L[] =  {8, 8, B00000000, B00000000, B00000000, B01110100, B00101100, B01001011, B10101001, B00101001};
char Glitch033L[] = {8, 8, B00000000, B00000000, B00000000, B00001000, B10100000, B01101001, B10011010, B01001101};
char Glitch04L[] =  {8, 8, B00000000, B00000000, B10101001, B01011001, B11101001, B01010111, B01011101, B00001011};
char Glitch044L[] = {8, 8, B00000000, B00000000, B00010001, B00000110, B01010101, B11011000, B10101001, B10000000};
char Eye02L[] =     {8, 8, B00000000, B00000000, B01100000, B11110000, B11111111, B01111111, B00111111, B00001111};
char Eye01L[] =     {8, 8, B00000000, B00000000, B00000001, B00000111, B11111110, B11111000, B11100000, B00000000};
char Angry2L[] =    {8, 8, B00000000, B00000011, B00001111, B00011111, B00111111, B00111111, B00011111, B00000000};
char Angry1L[] =    {8, 8, B00000000, B10000000, B11100000, B11111000, B11111100, B11111110, B11111100, B00000000};
char Spooked1L[] =  {8, 8, B00000001, B00000111, B00000111, B00001111, B00001111, B00000111, B00000111, B00000001};
char Spooked2L[] =  {8, 8, B10000000, B11100000, B11100000, B11110000, B11110000, B11100000, B11100000, B10000000};

// same on both sides
char Sad1[] = {8, 8, B00000001, B00000111, B00001110, B00011100, B00111000, B01110000, B11100000, B11000000};
char Sad2[] = {8, 8, B10000000, B11100000, B01110000, B00111000, B00011100, B00001110, B00000111, B00000011};
char Blush1[] = {8, 8, B00000000, B00000001, B00000011, B00000110, B00001100, B00011000, B00010000, B00000000};
char Blush2[] = {8, 8, B10000000, B11000000, B01100000, B00110000, B00011000, B00001100, B00000100, B00000000};

int redPin = 5; //These pins are used for the expression indicating rgb LED.
int greenPin = 11;
int bluePin = 9;

//The terms DIN, CLK and CS state where you should connect the the cables from the matrix to the Arduino,
//so DIN is connected to digital pin 6 on the arduino and the CLK on digital pin 7
int DIN = 6;   // DIN pin of MAX7219 module
int CLK = 7;   // CLK pin of MAX7219 module
int CS = 8;    // CS pin of MAX7219 module
int maxInUse = 14; //Change this number to the amount of matrixes you linked together
byte counter = 0;
byte counter2 = 0;
int column1L = 104;
int column2L = 112;
int column3L = 95;
int column4L = 103;
int column1 = 8;
int column2 = 16;
int column3 = -1;
int column4 = 7;
int state = 0;
int state2;
int stateSerial;

const int rfRxPin = 13;
const int thresholdCount = 5;  // Number of LOW signals to detect
const unsigned long timeout = 5000; // Time window in milliseconds (3 seconds)
unsigned long startTime = 0;   // To track the time window
int lowSignalCount = 0;        // Count of detected LOW signals

MaxMatrix m(DIN, CS, CLK, maxInUse);

// on arduino bootup
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
  randomSeed(analogRead(0));
  m.init();
  m.setIntensity(0);   // You can change the brightness of the matrices within a range of 0-15
  m.clear();
}


void loop() {
  detectRfRx();

  // set default mouth and nose
  noseMouth();
  
  // default happy expression
  if (state == 0) {
    eyeBlink();
    mouthGlitch();
    m.writeSprite(104, 0, Angry1L);
    m.writeSprite(96, 0, Angry2L);
    m.writeSprite(8, 0, Angry1);
    m.writeSprite(0, 0, Angry2);
  } else if (state == 1) {
    mouthGlitch();
    m.writeSprite(104, 0, Blush2);
    m.writeSprite(96, 0, Blush1);
    m.writeSprite(8, 0, Blush2);
    m.writeSprite(0, 0, Blush1);
  } else if (state == 2) {
    eyeBlink();
    mouthGlitch();
    m.writeSprite(104, 0, Eye01L);
    m.writeSprite(96, 0, Eye02L);
    m.writeSprite(8, 0, Eye02);
    m.writeSprite(0, 0, Eye01);
  }
  //  else if (state == 3) {
  //   m.writeSprite(104, 0, Sad1);
  //   m.writeSprite(96, 0, Sad2);
  //   m.writeSprite(8, 0, Sad1);
  //   m.writeSprite(0, 0, Sad2);
  //   setColor(16, 0, 0);
  // } else if (state == 4) {
  //   eyeBlink();
  //   m.writeSprite(104, 0, Spooked2L);
  //   m.writeSprite(96, 0, Spooked1L);
  //   m.writeSprite(8, 0, Spooked2);
  //   m.writeSprite(0, 0, Spooked1);
  //   setColor(0, 0, 8);              //Makes the colour of the LED blue
  // } 
  else {
    state = 0;
  }
}

void detectRfRx() {
  // If the signal is LOW
  if (digitalRead(rfRxPin) == 0) {
    if (lowSignalCount == 0) {
      // Start the timing window
      startTime = millis();
    }
    
    lowSignalCount++;
    Serial.println("LOW signal detected");
    
    // If the count reaches the threshold within the time window
    if (lowSignalCount >= thresholdCount) {
      if (millis() - startTime <= timeout) {
        state++;
        // Reset the count and timing window
        lowSignalCount = 0;
      } else {
        // Reset if time window is exceeded
        lowSignalCount = 0;
      }
    }
  }

  // Reset the count if the time window is exceeded
  if (millis() - startTime > timeout && lowSignalCount > 0) {
    lowSignalCount = 0;
  }
}

// default mouth and nose
// used on all expressions
void noseMouth() {
  m.writeSprite(88, 0, icon01L);
  m.writeSprite(80, 0, icon02L);
  m.writeSprite(72, 0, icon03L);
  m.writeSprite(64, 0, icon04L);
  m.writeSprite(56, 0, noseLeft);
  m.writeSprite(48, 0, noseRight);
  m.writeSprite(40, 0, icon04);
  m.writeSprite(32, 0, icon03);
  m.writeSprite(24, 0, icon02);
  m.writeSprite(16, 0, icon01);
}

// blink animation
// used on all expressions
void eyeBlink() {
   if (counter2 > 17) {
      for (int i = 0; i < 5; i++) {
        column1L = column1L - 1;
        column2L = column2L - 1;
        column1 = column1 - 1;
        column2 = column2 - 1;
        column3L = column3L + 1;
        column4L = column4L + 1;
        column3 = column3 + 1;
        column4 = column4 + 1;
        m.setColumn(column1L, 00000000);
        m.setColumn(column2L, 00000000);
        m.setColumn(column3L, 00000000);
        m.setColumn(column4L, 00000000);
        m.setColumn(column1, 00000000);
        m.setColumn(column2, 00000000);
        m.setColumn(column3, 00000000);
        m.setColumn(column4, 00000000);
        delay(15);
        counter2++;
      }
      column1L = 104;
      column2L = 112;
      column3L = 95;
      column4L = 103;
      column1 = 8;
      column2 = 16;
      column3 = -1;
      column4 = 7;
      counter2 = 0;
    }
    counter2++;
}

void mouthGlitch() {
  counter++;

  if (counter == 16) {
    m.writeSprite(64, 0, Glitch044L);
    m.writeSprite(72, 0, Glitch033L);
    m.writeSprite(80, 0, Glitch022L);
    m.writeSprite(88, 0, Glitch011L);
    m.writeSprite(16, 0, Glitch011);
    m.writeSprite(24, 0, Glitch022);
    m.writeSprite(32, 0, Glitch033);
    m.writeSprite(40, 0, Glitch044);
    delay(75);
    counter++;
  }
  if ((counter >= 17) && (counter < 18)) {
    m.writeSprite(88, 0, icon01L);
    m.writeSprite(80, 0, icon02L);
    m.writeSprite(72, 0, icon03L);
    m.writeSprite(64, 0, icon04L);
    m.writeSprite(40, 0, icon04);
    m.writeSprite(32, 0, icon03);
    m.writeSprite(24, 0, icon02);
    m.writeSprite(16, 0, icon01);
    delay(200);
    counter++;
  }
  if (counter >= 18) {
    m.writeSprite(64, 0, Glitch04L);
    m.writeSprite(72, 0, Glitch03L);
    m.writeSprite(80, 0, Glitch02L);
    m.writeSprite(88, 0, Glitch01L);
    m.writeSprite(16, 0, Glitch01);
    m.writeSprite(24, 0, Glitch02);
    m.writeSprite(32, 0, Glitch03);
    m.writeSprite(40, 0, Glitch04);
    delay(75);
    counter = 0;
  }
}


void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
