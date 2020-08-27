sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;

sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;
int key,oldkey,show;
const char number[] = {6,91,79,102,109,125,7,127,111,118,63,70};
void segment (int a ){
PORTA =255;
TRISA=0;
TRISD=0;
PORTD=number[a];
delay_ms(1);
}
void scanning(){
PORTA =0;
TRISB=0b00000000;
PORTB=0b00000000;
TRISD=0b00001111;
PORTD=0b00000000;
PORTB.F0 =0;
if (PORTD.F0 == 0) key =9;
else if (PORTD.F1 == 0) key = 9;
else if (PORTD.F2 == 0) key = 6;
else if (PORTD.F3 == 0) key = 3;
portb.f0=1;
delay_ms(1);
portb.f1=0;
if (PORTD.F0 == 0) key =11;
else if (PORTD.F1 == 0) key = 7;
else if (PORTD.F2 == 0) key = 4;
else if (PORTD.F3 == 0) key = 1;
portb.f1=1;
delay_ms(1);
portb.f2=0;
if (PORTD.F0 == 0) key =10;
else if (PORTD.F1 == 0) key = 8;
else if (PORTD.F2 == 0) key = 5;
else if (PORTD.F3 == 0) key = 2;
portb.f2=1;
delay_ms(1);
if (key!=oldkey){
oldkey=key;
show=key;
}
segment(show);
}
void main() {
LCD_Init();
Lcd_Cmd(_LCD_CLEAR);
Lcd_Cmd(_LCD_CURSOR_OFF);
delay_ms(100);
key=0;
oldkey=0;
do {
scanning();
}while(1);

}
