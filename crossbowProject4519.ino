 
 #include <Servo.h>

// Some variables are not used. I will refactor the code in the future to eliminate unwanted/unneeded redundancies 
// Be carefull with your servos! my code needs a swift servo action and I DO NOT delay between index incrementations. my servo on this project is fine but research the proper way on how to program a servo without risking damage to the device. THANK YOU
 
 int servoPin=9; //specify the positioning of the servo through this pin
 int pirPin=13; //anticipating a voltage from the sensor. this pin will recieve the voltage
 int calibrationTime=2000; //wait for environment to settle down/user to stop moving device upon boot
 long unsigned int lowIn; // the time when the sensor outputs LOW
 long unsigned int pause = 5000;  //remember 1000ms is 1 second
 int startPos=130; //change the starting position if you plan on using this code for your own project. THESE POSITIONS ARE BUILD SPECIFIC!
 int endPos=40; //the servo will write to this position once the sensor has been triggered, just keep following along with the code, it will all make sence
 int pullTrigger;
 int servoDelay=25;  //this SHOULD be a delay that is executed whenever a servo is moving positions. It's not coded like this in my code but dont run your servos to the max.
 int butPin=12;  // i added a button on mine to override the motion sensor. delete this line of code if its not needed
 
 boolean lockLow = true;  // pirPin has been outputting LOW for a while?
 boolean takeLowTime; //the option of taking LOW time from pirPin

 Servo trigServo; //name the servo(s) only one in this case

void setup() {

// The stuff inside this code block only runs once. Telling the arduino what to expect/do and non looping functions
  
  Serial.begin(9600); // initialize serial monitor
  pinMode(butPin,INPUT); //pinMode tells the arduino what to expect at a certain pin. such as outputting a voltage or inputting a voltage (taking readings).
  pinMode(pirPin,INPUT);
  pinMode(servoPin,OUTPUT);
  digitalWrite(pirPin,LOW); // setting the pin low(0 volts). This is the pin that will be taking a reading from the motion sensor. 
  trigServo.attach(servoPin);

// Honestly, this last part of the function (the bit of code below this comment) is to give the user time before the void loop is called. 

  Serial.print("calibrating sensor ");
    for(int j=0; j< calibrationTime; j++){  // for loop printing a "." every second after calibrating sensor string
      Serial.print(".");  // print a period
      delay(1000); //delay and repeat until it reaches the < value of calibrationTime
    }
    Serial.println(" done"); //prints done after the foor loop is done
    Serial.println("***SENSOR ACTIVE***");  // prints sensor active right after done because of no delay
    delay(50);  //miniscule delay before the void loop is called
}

void loop() {

  delay(1000); //delaying 1 second for a reason i dont know. most likely going to get removed
  trigServo.write(startPos); //make the servo move to startPos(integer defined in top of code)
  if(digitalRead(pirPin)== HIGH){ //if when the arduino reads the pirPin(defined above) and it is equal to HIGH(5v)
    trigServo.write(endPos);  // servo move to this position
    delay(servoDelay);  // delay this function so whatever is shot has enough time to move out of the way of the detection scope of the servo. Dont want to shoot our victim with two q-tips now do we? lol
  }
 
/*if (digitalRead(butPin)== HIGH) {
  trigServo.write(endPos);
  delay(servoDelay);
  trigServo.write(startPos);
  }
  */
  

}
