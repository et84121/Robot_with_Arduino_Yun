#include <Servo.h> 
#include <IRremote.h>                    // 引用 IRRemote 函式庫

Servo servo_1;                           // create servo object to control a servo 
Servo servo_2;
Servo servo_3;  
Servo servo_4;
Servo servo_5;  
Servo servo_6;
Servo servo_7;  
Servo servo_8;

int status_now = 0 ;                     //表示目前從遙控器取得之狀態  1 = walk ;
                                         //0 = stop ; 2 = Transformer


const int irReceiverPin = 12;             // 紅外線接收器 OUTPUT 訊號接在 pin 12

IRrecv irrecv(irReceiverPin);            // 定義 IRrecv 物件來接收紅外線訊號
decode_results results;                  // 解碼結果將放在 decode_results 結構的 result 變數裏


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

  servo_1.write(90);  //初使化servo
  servo_2.write(90); 
  servo_3.write(90); 
  servo_4.write(90); 
  servo_5.write(90); 
  servo_6.write(90); 
  servo_7.write(90); 
  servo_8.write(90);
  delay(300);

  Serial.begin(9600);                     // 開啟 Serial port, 通訊速率為 9600 bps
  irrecv.enableIRIn();                   // 啟動紅外線解碼
  Serial.println("Here 1");
} 

void loop() 
{ 
  Serial.println("Here 2");
  if (irrecv.decode(&results)) {         // 解碼成功&#65292;收到一組紅外線訊號
    Serial.println("this");               // 顯示紅外線協定種類
    if (results.value == 0xFF609F){      //行走  遙控按鍵 向上
      status_now = 1;
      Serial.println("1");
      }
    if(results.value == 0xFFE01F){        //停止  遙控按鍵 播放
      status_now = 0;
      Serial.println("0");
      }
    if(results.value == 0xFF906F){        //變形  遙控按鍵1
      status_now = 2;
      Serial.println("2");
      }
    if(results.value == 0xFFB847){        //爬行  遙控按鍵 2
      status_now = 3;
      Serial.println("3");
      }
    irrecv.resume();
  }      
  else{
    if (status_now == 1){  //walk
      ation_2();
      delay(150);
      ation_5();
      delay(150);
      ation_4();
      delay(150);
      ation_3();
      delay(150);
    }
    if (status_now == 0){
      Stop();
      Serial.println("Here 4");
    }
    if (status_now == 2){
      Transformer();
    }
    if (status_now == 3){
      Crawl();
    }
  }
} 

void Transformer(){
  servo_1.write(180);  //初使化servo
  servo_2.write(90); 
  servo_3.write(0); 
  servo_4.write(90); 
  servo_5.write(0); 
  servo_6.write(90); 
  servo_7.write(180); 
  servo_8.write(90);
  delay(300);
}
void Stop(){
  servo_1.write(90);  //初使化servo
  servo_2.write(90); 
  servo_3.write(90); 
  servo_4.write(90); 
  servo_5.write(90); 
  servo_6.write(90); 
  servo_7.write(90); 
  servo_8.write(90);
  delay(300);
}
void walk(){
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
void Crawl(){
  servo_1.write(60);
  servo_2.write(30);
  servo_5.write(120);
  servo_6.write(150);
  delay(300);
  servo_1.write(90);
  servo_5.write(90);
  servo_2.write(90);
  servo_6.write(90);
  delay(300);
}
void ation_2() {
  servo_1.write(60);
  servo_7.write(60);
  servo_2.write(90);
  servo_3.write(90);
  servo_4.write(90);
  servo_5.write(90);
  servo_6.write(90);
  servo_8.write(90);
}
void ation_3() {
  servo_2.write(30);
  servo_1.write(90);
  
  servo_6.write(30);
  servo_5.write(90);
  
  servo_4.write(150);
  servo_3.write(90);
  
  servo_8.write(150);
  servo_7.write(90);
}
void ation_4() {
  servo_3.write(120);
  servo_5.write(120);
  servo_1.write(90);
  servo_2.write(90);
  servo_4.write(90);
  servo_6.write(90);
  servo_7.write(90);
  servo_8.write(90);
}
void ation_5(){
  servo_2.write(150);
  servo_1.write(90);
  
  servo_6.write(150);
  servo_5.write(90);
  
  servo_4.write(30);
  servo_3.write(90);
  
  servo_8.write(30);
  servo_7.write(90);
}
void ation_6(){
  servo_2.write(150);
  servo_4.write(30);
  servo_6.write(150);
  servo_8.write(150);
  servo_1.write(90);
  servo_3.write(90);
  servo_5.write(90);
  servo_7.write(90);
}
void ation_7(){
  servo_2.write(30);
  servo_4.write(150);
  servo_6.write(150);
  servo_8.write(150);
  servo_1.write(90);
  servo_3.write(90);
  servo_5.write(90);
  servo_7.write(90);
}
  
