#include<Servo.h>

//Servo used:MG995
Servo Servo_1,Servo_2,Servo_3,Servo_4;

char SerialFeed; //Command

void setup(){
  Servo_1.attach(3); //D3
  Servo_2.attach(5); //D5
  Servo_3.attach(6); //D6
  Servo_4.attach(9); //D9
  Serial.begin(9600);
  //SerialConn initialise
}

void loop(){
  if(Serial.available()>0){
    SerialFeed=Serial.read();
    delay(10);//Wait 10 miliseconds!
    if(SerialFeed=='B'){
     Servo_1.write(0);
     //Servo-1:Anti-clk
    }
    else if(SerialFeed=='A'){
     Servo_1.write(180);
     //Servo-1:Clk-wise
    }
    else if(SerialFeed=='D'){
     Servo_2.write(0);
     //Servo-2:Anti-clk
    }
    else if(SerialFeed=='C'){
     Servo_2.write(180);
     //Servo-2:Clk-wise
    }
    else if(SerialFeed=='F'){
     Servo_3.write(0);
     //Servo-3:Anti-clk
    }
    else if(SerialFeed=='E'){
     Servo_3.write(180);
     //Servo-3:Clk-wise
    }
    else if(SerialFeed=='L'){
     Servo_4.write(0);
     //Servo-4:Anti-clk
    }
    else if(SerialFeed=='K'){
     Servo_4.write(180);
     //Servo-4:Clk-wise
    }
    else{
     delay(1000);   //Holddown state!
     Servo_1.write(90);
     Servo_2.write(90);
     Servo_3.write(90);
     Servo_4.write(90);
    }
  }
}

