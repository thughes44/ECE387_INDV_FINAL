/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 2;     // the number of the pushbutton pin
const int ledPin1 =  3;      // the number of the LED pin
const int buttonPin2 = 4;
const int ledPin2 =  5;
const int buttonPin3 = 6;
const int ledPin3 =  7;

// variables will change:
int buttonState1 = 0; // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;

int lastButtonState1 = 0;     // previous state of the button
int lastButtonState2 = 0;
int lastButtonState3 = 0;

int correctCount = 0;
int loopCount = 0;
int rnum = 0;
int gamelength = 10;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);

  Serial.begin(9600);

}

void loop() {
  unsigned long time = millis();
  rnum = random(0, 3);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);

  bool hold = true;
  loopCount++;

  // set LED on
  switch (rnum) {
    case 0:
      digitalWrite(ledPin1, HIGH);
      break;
    case 1:
      digitalWrite(ledPin2, HIGH);
      break;
    case 2:
      digitalWrite(ledPin3, HIGH);
      break;
    default:
      digitalWrite(ledPin3, HIGH);
      break;
  }
  while (hold) {
    if(millis()-time > 2000) {
      hold = false;
      Serial.println("out of time");
      delay(100);
    }
    
    // read the state of the pushbutton value:
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
    buttonState3 = digitalRead(buttonPin3);
    // compare the buttonState to its previous state
    if (buttonState1 != lastButtonState1) {
      // if the state has changed, increment the counter
      if (buttonState1 == HIGH) {
        // if the current state is HIGH then the button went from off to on:
        if (rnum == 0) {
          correctCount++;
          hold = false;
          Serial.println("Correct");
        } else {
          hold = false;
          Serial.println("Incorrect");
        }
      } else {
        // if the current state is LOW then the button went from on to off:
      }
      // Delay a little bit to avoid bouncing
      delay(50);
    }
    // save the current state as the last state, for next time through the loop
    lastButtonState1 = buttonState1;


    // compare the buttonState to its previous state
    if (buttonState2 != lastButtonState2) {
      // if the state has changed, increment the counter
      if (buttonState2 == HIGH) {
        // if the current state is HIGH then the button went from off to on:
        if (rnum == 1) {
          correctCount++;
          hold = false;
          Serial.println("Correct");
        } else {
          hold = false;
          Serial.println("Incorrect");
        }
      } else {
        // if the current state is LOW then the button went from on to off:
      }
      // Delay a little bit to avoid bouncing
      delay(50);
    }
    // save the current state as the last state, for next time through the loop
    lastButtonState2 = buttonState2;


    // compare the buttonState to its previous state
    if (buttonState3 != lastButtonState3) {
      // if the state has changed, increment the counter
      if (buttonState3 == HIGH) {
        // if the current state is HIGH then the button went from off to on:
        if (rnum == 2) {
          correctCount++;
          hold = false;
          Serial.println("Correct");
        } else {
          hold = false;
          Serial.println("Incorrect");
        }
      } else {
        // if the current state is LOW then the button went from on to off:
      }
      // Delay a little bit to avoid bouncing
      delay(50);
    }
    // save the current state as the last state, for next time through the loop
    lastButtonState3 = buttonState3;

    // check what button pressed and update count

  }

  if (loopCount == gamelength) {
    for (int j = 0; j < 5; j++) {
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(100);
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      delay(100);
    }
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    Serial.println("GAME FINISHED!");
    Serial.print("Number of correct situps: ");
    Serial.println(correctCount);
    Serial.print("Number of situps attempted: ");
    Serial.println(gamelength);
    float correctpercent = (correctCount / gamelength) * 100;
    Serial.print("Percentage of correct reps: ");
    Serial.print(correctpercent);
    Serial.println("%");
    delay(1000);
    exit(0);
  }
}
