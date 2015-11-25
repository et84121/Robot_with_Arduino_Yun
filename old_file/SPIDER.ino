    #include <Servo.h> 
 
    
    Servo servo_1;                           // create servo object to control a servo 
    Servo servo_2;
    Servo servo_3;  
    Servo servo_4;
    Servo servo_5;  
    Servo servo_6;
    Servo servo_7;  
    Servo servo_8;
    
    void setup() 
    { 
      servo_1.attach(2);  
      servo_2.attach(3);  
      servo_3.attach(4);  
      servo_4.attach(5);
      servo_5.attach(6);  
      servo_6.attach(7);  
      servo_7.attach(8);  
      servo_8.attach(9);
      
      servo_1.write(180);  //初使化servo
      servo_2.write(90); 
      servo_3.write(0); 
      servo_4.write(90); 
      servo_5.write(0); 
      servo_6.write(90); 
      servo_7.write(180); 
      servo_8.write(90);
      delay(5000);
      
      servo_1.write(90);  //初使化servo
      servo_2.write(90); 
      servo_3.write(90); 
      servo_4.write(90); 
      servo_5.write(90); 
      servo_6.write(90); 
      servo_7.write(90); 
      servo_8.write(90);
      delay(1000);
     } 
    

    void loop() {
      servo_1.write(60);
      servo_2.write(30);
      delay(150);
      servo_1.write(90);
      delay(150);
      //右前跨出
      servo_7.write(60);
      servo_8.write(150);
      delay(150);
      servo_7.write(90);
      delay(150);
      //左後跨出
      servo_5.write(120);
      servo_6.write(150);
      delay(150);
      servo_5.write(90);
      delay(150);
      //左前跨出
      servo_3.write(120);
      servo_4.write(30);
      delay(150);
      servo_3.write(90);
      delay(150);
      //右後跨出
      servo_2.write(90);
      servo_4.write(90);
      servo_6.write(90);
      servo_8.write(90);
      delay(250);
  
    } 

