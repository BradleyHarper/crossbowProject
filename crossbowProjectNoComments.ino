 
 #include <Servo.h>
 
 int servoPin=9;
 int pirPin=13;
 int calibrationTime=5;
 long unsigned int lowIn;
 long unsigned int pause = 5000;  //remember 1000ms is 1 second
 int startPos=130;
 int endPos=40;
 int pullTrigger;
 int servoDelay=25;
 int butPin=12;
 
 boolean lockLow = true;
 boolean takeLowTime;

 Servo trigServo;

void setup() {
  Serial.begin(9600);
  pinMode(butPin,INPUT);
  pinMode(pirPin,INPUT);
  pinMode(servoPin,OUTPUT);
  digitalWrite(pirPin,LOW);
  trigServo.attach(servoPin);

  Serial.print("calibrating sensor ");
    for(int j=0; j< calibrationTime; j++){
      Serial.print(".");
      delay(1000);
    }
    Serial.println(" done");
    Serial.println("***SENSOR ACTIVE***");
    delay(50);
  
}

void loop() {

  delay(1000);
  trigServo.write(startPos);
  
  
  if(digitalRead(pirPin)== HIGH){
    trigServo.write(endPos);
    delay(servoDelay);
  }
 
/*if (digitalRead(butPin)== HIGH) {
  trigServo.write(endPos);
  delay(servoDelay);
  trigServo.write(startPos);
  }
  */
  

}
