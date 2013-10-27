#define yellow1 0
#define yellow2 4
#define red 1

// let's declare some integer variables!
int yellowBright;     // will hold brightness of Yellow LED
int redBright;        // will hold brightness of Red LED
int hold;             // will hold time delay between flicks
int pause;            // will hold pause between the flicker cycle
int low_fadeUp = 0;   // will hold a value from which to start the fadeUp loop
int low_fadeDown = 0;  // will hold a value for the fadeDown loop to stop
int high_fade = 0;    // will hold the highest value in both fade loops


// these next two variables help define the range of low values, where the candle will start from or end at
static int flicker_low_MIN = 75;    // absolute lowest value for the bottom threshhold of the flicker brightness
static int flicker_low_MAX = 100;   // maximum value for the bottom threshhold of the flicker brightness

// these next two variables help define the range of high values, where the candle will fade up to or fade down from 
static int flicker_high_MIN = 230;   // minimum value for the top thresh hold of flicker brightness 
static int flicker_high_MAX = 256;   // maximum value for the top thresh hold of flicker brightness

// these next two variables help define the speed of each loops
static int speed_min = 100;   // microseconds
static int speed_max = 500; // microseconds



void setup()
{
pinMode(yellow1, OUTPUT);
pinMode(yellow2, OUTPUT);
pinMode(red, OUTPUT);
}

void loop()
{
  digitalWrite(yellow2, HIGH);  // turns one Yellow LED on. This will remain on as the other two fade in and out creating the flicker effect. 
  
  hold = random(0, 200);                       // selects a random time for a delay between the fadeUP and fadeDown cycles
  pause = random(0, 200);
  int fadeUp_time = random(speed_min, speed_max);     // selects a random speed for the fadeUp loop
  int fadeDown_time = random(speed_min, speed_max);   // selects a random speed for the fadeDown loop
  
  low_fadeUp = random(flicker_low_MIN, flicker_low_MAX);   // selects a random amount in the low range variable for the start of the fadeUp loop
  low_fadeDown = random(flicker_low_MIN, flicker_low_MAX);  // selects a random amount in the low range for the end of the fadeDown loop
  
  high_fade = random(flicker_high_MIN, flicker_high_MAX);  // selects a random amount in the high range for both fade loops
  
  // here comes the fadeUp loop
  for(int x = low_fadeUp;  x < high_fade; x++)   
  { 
    analogWrite(yellow1, x);
    analogWrite(red, x);
    delayMicroseconds(fadeUp_time); 
  }
  
   delay(hold); // random delay before high value fades to lowest value 
   
  // here comes the fadeDown loop
  for(int x = high_fade; x>low_fadeDown; x--)
  {
    analogWrite(yellow1, x);
    analogWrite(red, x);
    delayMicroseconds(fadeDown_time); //make this a random number to create an arbitrary time for this loop
  }

    delay(pause); // random delay before high value fades to lowest value 
}
