// Automatic light sensing 

#define echoPin 9 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED
#define LEDPin1 36
#define LEDPin2 38
#define LEDPin3 40
#define LEDPin4 42
#define LEDPin5 44

int maximumRange = 150; // Maximum range needed
int minimumRange = 5; // Minimum range needed
int range1 = 30;
int range2 = 60;
int range3 = 90;
int range4 = 120;
int range5 = 150;

long duration;   //, distance; // Duration used to calculate distance
float distance;
int count=0;
int count_5=0;
int count_4=0;
int count_3=0;
int count_2=0;
int count_1=0;

int LDRPin = A0; // select the input pin for ldr
int LDRValue = 0; // variable to store the value coming from the sensor

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)

  pinMode(LEDPin1, OUTPUT);
  pinMode(LEDPin2, OUTPUT);
  pinMode(LEDPin3, OUTPUT);
  pinMode(LEDPin4, OUTPUT);
  pinMode(LEDPin5, OUTPUT);
 
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(LEDPin,HIGH);

  LDRValue = analogRead(LDRPin); // read the value from the sensor
//  Serial.println(LDRValue); //prints the values coming from the sensor on the screen
  if(LDRValue>=0 && LDRValue<=3)
  {
    //The light if off as the outside light or the sun’s intensity is greater than the threshold
    digitalWrite(LEDPin1,LOW);
    digitalWrite(LEDPin2,LOW);
    digitalWrite(LEDPin3,LOW);
    digitalWrite(LEDPin4,LOW);
    digitalWrite(LEDPin5,LOW);
    goto X;
   }
   


 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(20); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(100); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn light OFF
 to indicate "out of range" */
 Serial.println("-1");
 digitalWrite(LEDPin, HIGH); 
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn Light OFF to indicate successful reading. */
// Serial.println(distance);
 Serial.println("Value: ");
 Serial.println(distance/150);
 
 //digitalWrite(LEDPin, LOW); 
 }

 if (distance >= minimumRange && distance <= range1 ){
  // light glowing at 100% intensity
  count_5++;
  count=0;
  count_4=0;
  count_3=0;
  count_2=0;
  count_1=0;
 }
 else if(distance > range1 && distance <= range2){
  // Light glowing at intensity less than 100%
  count_4++;
  count=0;
  count_5=0;
  count_3=0;
  count_2=0;
  count_1=0;
 }
  else if(distance > range2 && distance <= range3){
  // Light glowing at intensity less than 100%

  count_3++;
  count=0;
  count_5=0;
  count_4=0;
  count_2=0;
  count_1=0;
 }
  else if(distance > range3 && distance <= range4){
    // Light glowing at intensity less than 100%
  count_2++;
  count=0;
  count_5=0;
  count_4=0;
  count_3=0;
  count_1=0;
 }
  else if(distance > range4 && distance <= range5){
  // Light glowing at intensity less than 100%
  count_1++;
  count=0;
  count_5=0;
  count_4=0;
  count_3=0;
  count_2=0;
 }
else{
  count ++;
  count_5=0;
  count_4=0;
  count_3=0;
  count_2=0;
  count_1=0;
  
}


if(count_5==3){
  count_5=0;
  digitalWrite(LEDPin1,HIGH);
  digitalWrite(LEDPin2,HIGH);
  digitalWrite(LEDPin3,HIGH);
  digitalWrite(LEDPin4,HIGH);
  digitalWrite(LEDPin5,HIGH);
}
if(count_4==3){
  count_4=0;
  digitalWrite(LEDPin1,HIGH);
  digitalWrite(LEDPin2,HIGH);
  digitalWrite(LEDPin3,HIGH);
  digitalWrite(LEDPin4,HIGH);
  digitalWrite(LEDPin5,LOW);
}
if(count_3==3){
  count_3=0;
  digitalWrite(LEDPin1,HIGH);
  digitalWrite(LEDPin2,HIGH);
  digitalWrite(LEDPin3,HIGH);
  digitalWrite(LEDPin4,LOW);
  digitalWrite(LEDPin5,LOW);
}
if(count_2==3){
  count_2=0;
  digitalWrite(LEDPin1,HIGH);
  digitalWrite(LEDPin2,HIGH);
  digitalWrite(LEDPin3,LOW);
  digitalWrite(LEDPin4,LOW);
  digitalWrite(LEDPin5,LOW);
}

if(count_1==3){
  count_1=0;
  digitalWrite(LEDPin1,HIGH);
  digitalWrite(LEDPin2,LOW);
  digitalWrite(LEDPin3,LOW);
  digitalWrite(LEDPin4,LOW);
  digitalWrite(LEDPin5,LOW);
}

if(count==3){
  count=0;
  digitalWrite(LEDPin1,LOW);
  digitalWrite(LEDPin2,LOW);
  digitalWrite(LEDPin3,LOW);
  digitalWrite(LEDPin4,LOW);
  digitalWrite(LEDPin5,LOW);
}
 
 //Delay 50ms before next reading.
 X:
 delay(500);
}
