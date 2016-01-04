#define servo_delay_time 500
#define delaytime 100
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <Bridge.h>
#include <BlynkSimpleYun.h>
#include <Servo.h>
#include <LedControl.h>

int step[2][4];

int step_stand[2][4] = { {90,90,90,90} , {90,90,90,90} };
int step_shutdown[2][4] = { { 180,0,0,180 } ,{ 90,90,90,90 } };

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "86fd41d8f0bb4239bb5e0469272682ae";

Servo myservo[8];  // create servo object to control a servo

/*
 Now we need a LedControl to work with.
***** These pin numbers will probably not work with your hardware *****
	  pin 10 is connected to the DataIn
	  pin 12 is connected to the CLK
	  pin 11 is connected to LOAD
	  We have only a single MAX72XX.
 */
LedControl lc = LedControl(10, 12, 11, 2);

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

  /*
  The MAX72XX is in power-saving mode on startup,
  we have to do a wakeup call
  */
  lc.shutdown(0, false);
  lc.shutdown(1, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 2);
  lc.setIntensity(1, 2);
  /* and clear the display */
  lc.clearDisplay(0);
  lc.clearDisplay(1);
}

/*
This function will light up every Led on the matrix.
The led will blink along with the row-number.
row number 4 (index==3) will blink 4 times etc.
*/
void single() {
	for (int a = 0; a < 2; a++)
	{
		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {
				delay(delaytime);
				lc.setLed(a, row, col, true);
				delay(delaytime);
				for (int i = 0; i < col; i++) {
					lc.setLed(a, row, col, false);
					delay(delaytime);
					lc.setLed(a, row, col, true);
					delay(delaytime);
				}
			}
		}
	}
}

void update_servo(int step[2][4]) {
	for (int i = 0; i < 4; i++){
		myservo[i*2].write(step[0][i]);
		myservo[i*2-1].write(step[1][i]);
	}
	delay(servo_delay_time);
}

//make robot Transforme
BLYNK_WRITE(V1)
{
  int pinData = param.asInt();
  //if value is 1 , make robot stand up. Or make robot sit down
  if (pinData == 1) {
	  update_servo(step_stand);
  }
  else {
	  update_servo(step_shutdown);
  }
}

 BLYNK_WRITE(V2){
   int pinData = param.asInt();
   //if value is 1 , make robot stand up. Or make robot sit down
   if (pinData == 1) {
	 //step 1
		//lift foot
     myservo[0].write(60);
	 myservo[6].write(60);
		//前轉腳
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
		//前轉腳
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
	   update_servo(step_stand);
   }
 }
 

void loop()
{
  //single();
  Blynk.run();
}
