
 

#include <LedControl.h>
 
int DIN = 1;
int CS =  0;
int CLK = 2;
int Button = 3;//按键
int Num = 0;
byte L[8]=     {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3E};  //L
byte O[8]=     {0x18,0x24,0x42,0x42,0x42,0x42,0x24,0x18};  //O
byte V[8]=     {0x81,0x81,0x81,0x81,0x81,0x42,0x24,0x18};  //V
byte E[8]=     {0x7E,0x40,0x40,0x7E,0x40,0x40,0x40,0x7E};  //E
byte samllheart[8] = { 0x0,0x24,0x5A,0x42,0x24,0x18,0x0,0x0};  //小心心
byte bigheart[8] = { 0x66,0x99,0x81,0x81,0x81,0x42,0x24,0x18 };  //大心心
byte smile[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};//笑脸
  
LedControl lc=LedControl(DIN,CLK,CS,4);
 //点阵显示函数
void key()
{
   
    if (digitalRead(Button) == LOW)
    {
        delay(30);
        if (digitalRead(Button) == LOW)
        {
            Num++;//按键按下后
            
            
            while (digitalRead(Button) == LOW);
        }
    }
}
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
void setup(){
 lc.shutdown(0,false);       //启动时，MAX72XX处于省电模式
 lc.setIntensity(0,8);       //将亮度设置为最大值
 lc.clearDisplay(0);         //清除显示
 pinMode(Button, INPUT);// 按键引脚设置上拉输入
}
 
void loop(){ 

    key();
    if (Num >1)
        Num=0;
    if (Num==0){
        printByte(samllheart);
        delay(500);
        printByte(bigheart);
        delay(500);
    }
   
     
    if (Num==1)
        printByte(smile);
        
    
   //printByte(smile);
}
 

