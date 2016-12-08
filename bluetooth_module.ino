#include <SoftwareSerial.h>//시리얼 통신 라이브러리 호출!!
#include <string.h>

int blueRx=2; //받는쪽 핀
int blueTx=3; //보내는쪽 핀
//블루투스 시리얼 통신을 위한 객체 선언
SoftwareSerial blueSerial(blueTx,blueRx);
String str="";
boolean flag=false;

void setup() {
  blueSerial.begin(9600);
  Serial.begin(9600);
  pinMode(8, INPUT);
}

void loop() {
    while(blueSerial.available()){  //접속자가 보낸 데이터가 존재한다면...
      int data=blueSerial.read();  //   안녕하세요         
      str+=(char)data;
    }
    
    if(!str.equals("")){
      Serial.println(str);  
      blueSerial.print(str+"\n"); //접속자에게 데이터 출력!!
      
      if(str.equals("on")){
          flag=true;
      }else if(str.equals("off")){
          flag=false;
      }          
    }
    (flag)?digitalWrite(8, HIGH):digitalWrite(8, LOW); 
      
    delay(100);
    str="";                                        
}

