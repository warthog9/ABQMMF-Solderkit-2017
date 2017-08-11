// This code does work! yay!

int redLEDPin = 1;   // 
int greenLEDPin = 0; // works
int xmasLEDPin = 4;  //
int whatBtn = 2;

int randSeedPin = 3;

int leds[] = { redLEDPin, greenLEDPin, xmasLEDPin };
int numLEDS = 3;

int maxBrightness = 128;

void setup()
{
  int delaytime = 500;
  
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(xmasLEDPin, OUTPUT);
  
  pinMode(whatBtn, INPUT_PULLUP);

  //sparkle();

  //pinMode(randSeedPin, INPUT);
  randomSeed(analogRead(randSeedPin));
  
  digitalWrite(redLEDPin, HIGH);   // sets the LED on
  delay(delaytime);                  // waits for a second
  digitalWrite(redLEDPin, LOW);    // sets the LED off
  delay(delaytime);                  // waits for a second
  
  digitalWrite(greenLEDPin, HIGH);   // sets the LED on
  delay(delaytime);                  // waits for a second
  digitalWrite(greenLEDPin, LOW);    // sets the LED off
  delay(delaytime);                  // waits for a second
  
  digitalWrite(xmasLEDPin, HIGH);   // sets the LED on
  delay(delaytime);                  // waits for a second
  digitalWrite(xmasLEDPin, LOW);    // sets the LED off
  delay(delaytime);                  // waits for a second
  
  //attachInterrupt(whatBtn, choose, FALLING);
  
  attachInterrupt(0, choose, FALLING);
  
}

void loop()
{ 
  return;
  
  int x = 0;

  if( digitalRead(whatBtn) == LOW ){
/*
    digitalWrite(redLEDPin, HIGH);   // sets the LED on
    digitalWrite(greenLEDPin, HIGH);   // sets the LED on
    digitalWrite(xmasLEDPin, HIGH);   // sets the LED on
    delay(1000);                  // waits for a second
    digitalWrite(redLEDPin, LOW);   // sets the LED on
    digitalWrite(greenLEDPin, LOW);   // sets the LED on
    digitalWrite(xmasLEDPin, LOW);   // sets the LED on
    delay(1000);                  // waits for a second  

    for( x = 0; x <= 255 ; x++ ){
      analogWrite(redLEDPin, x);
      analogWrite(greenLEDPin, x);
      analogWrite(xmasLEDPin, x);
      delay( 5 );
    }
    
    delay( 200 );
*/
    digitalWrite(redLEDPin, HIGH);
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(xmasLEDPin, HIGH);
    
    for( x = 255; x >= 0 ; x = x -1 ){
      analogWrite(redLEDPin, x);
      analogWrite(greenLEDPin, x);
      analogWrite(xmasLEDPin, x);
      delay( 5 );
    }
    digitalWrite(redLEDPin, LOW);
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);
  }
  
  return; 
}

void choose() { 
  int what = LOW;
  int winner = random( 0, 4 );
  if( winner >= 3 ){
    winner = 0;
  }
  
  clear();
  /*
  for( int x = 0; x < 5; x++ ){
    if( x % 2 != 0 ){
      what = LOW;
    } else {
      what = HIGH;
    }
    
     for( int x = 0; x < numLEDS; x++ ){
      digitalWrite(leds[x], what);
    }
    delay( 5000 );
    

  }*/
  for (int sparkletime  = 2000; sparkletime > 0; sparkletime = sparkletime - 500) 
  {
    for (int i = 0; i < numLEDS; i++) {
      digitalWrite(leds[i], HIGH);
      delay(sparkletime);
      digitalWrite(leds[i], LOW);
      delay(sparkletime);
    }
  }
  
  delay(5000);  
  clear();
  
  digitalWrite( leds[winner], HIGH);
  
  delay( 30000 );
  
  clear();
}

void clear() {
  for( int x = 0; x < numLEDS; x++ ){
    digitalWrite(leds[x], LOW);
  }  
}
