#include <SoftwareSerial.h>
SoftwareSerial myserial(5,6);
int red = 8 ; 
int blue=9;
int green=10;
void setup() {
 myserial.begin(9600);
 pinMode(red, OUTPUT); 
  pinMode(blue, OUTPUT);
   pinMode(green, OUTPUT);
  myserial.write("Hello in Bluetooth");
}
char val='x';
void loop() {
 if (myserial.available())
 {

char s=myserial.read();
if(s=='r'||s=='g'||s=='b'||s=='0'){
  val=s;
  }
  switch(val){
    case 'r':
                 play(1,0,0);
              break; 
           case 'g':
                 play(0,1,0);
              break; 
              
         case 'b':      
                 play(0,0,1);
              break;  
       default:
       play(0,0,0);                

    }




}}
void play(int r,int g,int b){
     digitalWrite(red,r);
     digitalWrite(blue,b);
        digitalWrite(green,g);
  }
