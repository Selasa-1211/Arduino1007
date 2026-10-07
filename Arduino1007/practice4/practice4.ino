

const int RledPin = 9;
const int GledPin = 10;
const int BledPin = 11;

int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by
int ledcolor = 0;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(RledPin , OUTPUT);
  pinMode(GledPin , OUTPUT);
  pinMode(BledPin , OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  if(ledcolor==0){
    analogWrite(RledPin,brightness);
    analogWrite(GledPin,255);
    analogWrite(BledPin,255);
  }

  if(ledcolor==1){
    analogWrite(RledPin,255);
    analogWrite(GledPin,brightness);
    analogWrite(BledPin,255);
  }

  if(ledcolor==2){
    analogWrite(RledPin,255);
    analogWrite(GledPin,255);
    analogWrite(BledPin,brightness);
  }

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
    if(brightness>=255){
      ledcolor=ledcolor + 1;
      if(ledcolor > 2)
      ledcolor = 0;
    }
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
