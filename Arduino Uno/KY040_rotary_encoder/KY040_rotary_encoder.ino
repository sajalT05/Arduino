int val; 
int PinCLK = 4;
int PinDT = 5;
int PinSW = 0;
static long encoderPos = -1;    // Au 1er démarrage, il passera à 0
int PinCLKLast = LOW;
int nbPas = 20;                 // Résolution de l'encodeur
int n = LOW;

void setup() { 
  pinMode (PinCLK,INPUT);
  pinMode (PinDT,INPUT);
  pinMode (PinSW,INPUT);
  Serial.begin (9600);
} 

void loop() { 
   if (!(digitalRead(PinSW))) {      
     encoderPos = 0;
     
   }
   
   n = digitalRead(PinCLK);
   
   if ((PinCLKLast == LOW) && (n == HIGH)) {
     
     if (digitalRead(PinDT) == LOW) {
       encoderPos--;
       if ( encoderPos < 0 ) {
         encoderPos = nbPas;
       }
     } else {
       encoderPos++;
       if ( encoderPos > ( nbPas - 1 ) ) {
         encoderPos = 0;
       }
     }
     Serial.print (encoderPos); 
     Serial.print(", angle "); 
     Serial.println( abs ( encoderPos * ( 360 / nbPas ) ) );
     
   } 
   PinCLKLast = n;
 }
