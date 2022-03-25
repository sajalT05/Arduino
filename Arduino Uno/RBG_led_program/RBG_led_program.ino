int redPin=8;         // Set red LED pin to 8
int greenPin=10;       // Set green LED pin to 9
int bluePin=9;         // Set blue LED pin to 10
int bright = 255;  // Set brightness to full
int dim = 0;           // Set dimness
String msg = "Please input your color choice:"; //Message to be displayed
String prompt = "Your colour is ";
String color;    // Set up variable to hold user input

void setup() {
  Serial.begin(9600);  // Turn on Serial port to 9600 baud
  pinMode (redPin, OUTPUT);     // Set pinmodes to output
  pinMode (greenPin, OUTPUT);   // Set pinmodes to output
  pinMode (bluePin, OUTPUT);    // Set pinmodes to output

}

void loop() {
  
  Serial.println(msg);  // prompting user for input
  while (Serial.available()==0) { }
  color = Serial.readString ();    // read string from serial port

  Serial.println(prompt + color); //print input colour

  if (color == "red") {
    analogWrite (redPin, bright);    // Turn red on
    analogWrite (bluePin, 0);            // Turn blue off
    analogWrite (greenPin, 0);           // Turn green off
  }

  if (color == "green") {
   analogWrite (redPin, 0);             // Turn red on
    analogWrite (bluePin, 0);            // Turn blue off
    analogWrite (greenPin, bright);  // Turn green off
  }

  if (color == "blue") {
    analogWrite (redPin, 0);             // Turn red on
    analogWrite (bluePin, bright);   // Turn blue off
    analogWrite (greenPin, 0);           // Turn green off
  }

    if (color == "white") {
    analogWrite (redPin, bright);             // Turn red on
    analogWrite (bluePin, bright);   // Turn blue on
    analogWrite (greenPin, bright);           // Turn green on
  }

  if (color != "red" && color != "green" && color != "blue") {
    Serial.println ("");
    Serial.println ("You have not entered a valid color, please enter red, green or blue");
    Serial.println ("");
  }
}
