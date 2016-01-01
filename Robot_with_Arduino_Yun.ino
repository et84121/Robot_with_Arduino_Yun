/**************************************************************
   Blynk is a platform with iOS and Android apps to control
   Arduino, Raspberry Pi and the likes over the Internet.
   You can easily build graphic interfaces for all your
   projects by simply dragging and dropping widgets.

     Downloads, docs, tutorials: http://www.blynk.cc
     Blynk community:            http://community.blynk.cc
     Social networks:            http://www.fb.com/blynkapp
                                 http://twitter.com/blynk_app

   Blynk library is licensed under MIT license
   This example code is in public domain.

 **************************************************************
   This example shows how to use Arduino Yun Bridge
   to connect your project to Blynk.
   Feel free to apply it to any other example. It's simple!

 **************************************************************/
#define servo_delay_time 500
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <Bridge.h>
#include <BlynkSimpleYun.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "86fd41d8f0bb4239bb5e0469272682ae";

Servo myservo[8];  // create servo object to control a servo

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth);
  // Or specify server using one of those commands:
  //Blynk.begin(auth, "server.org", 8442);
  //Blynk.begin(auth, server_ip, port);

  for (int a = 2; a <= 9; a++) {
    myservo[a - 2].attach(a);
  }
}



//make robot Transforme
BLYNK_WRITE(V1)
{
  int pinData = param.asInt();
  //if value is 1 , make robot stand up. Or make robot sit down
  if (pinData == 1) {
    stand();
  }
  else {
    myservo[0].write(180);
    myservo[6].write(180);
    myservo[4].write(0);
    myservo[2].write(0);
    for (int a = 1; a <= 7; a += 2) {
      myservo[a].write(90);
    }
    delay(servo_delay_time);//let motor have enough time to rotate
  }
}

 BLYNK_WRITE(V2)
 {
   int pinData = param.asInt();
   //if value is 1 , make robot stand up. Or make robot sit down
   if (pinData == 1) {

	 //step 1
		//lift foot
     myservo[0].write(60);
	 myservo[6].write(60);
		//�e��}
	 myservo[1].write(30);
	 myservo[7].write(150);
     delay(servo_delay_time);//let motor have enough time to rotate

	 //step 2
	 myservo[0].write(90);
	 myservo[6].write(90);
	 delay(servo_delay_time);//let motor have enough time to rotate

	 //step 3
	 myservo[1].write(90);
	 myservo[7].write(90);
	 delay(servo_delay_time);//let motor have enough time to rotate


	 //step 1
		//lift foot
	 myservo[2].write(120);
	 myservo[4].write(120);
		//�e��}
	 myservo[3].write(30);
	 myservo[5].write(150);
	 delay(servo_delay_time);//let motor have enough time to rotate
	
	 //step 2
	 myservo[2].write(90);
	 myservo[4].write(90);
	 delay(servo_delay_time);//let motor have enough time to rotate

	 //step 3
	 myservo[3].write(90);
	 myservo[5].write(90);
	 delay(servo_delay_time);//let motor have enough time to rotate
   }
   else{
     stand();
   }
 }
 
//make robot stand up
void stand(){
  for (int a = 0; a <= 8; a++) {
    myservo[a].write(90);
  }
  delay(servo_delay_time);//let motor have enough time to rotate
}

void loop()
{
  Blynk.run();
}
