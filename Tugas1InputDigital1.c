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
int u;
void lcdr (char a[5]){
TRISD=0;
Lcd_Out(1,u,a);
TRISD=255;
u++;
delay_ms(100);

}
void main() {
LCD_Init();
Lcd_Cmd(_LCD_CLEAR);
Lcd_Cmd(_LCD_CURSOR_OFF);
delay_ms(100);
TRISB=0b00000000;
PORTB=0b00000000;
TRISD=0b00001111;
PORTD=0b00000000;
do {
PORTB.F0=0;
if (PORTD.F0 == 0) lcdr("#");
else if (PORTD.F1 == 0) lcdr("9");
else if (PORTD.F2 == 0) lcdr("6");
else if (PORTD.F3 == 0) lcdr("MODE3 : SERVO");
delay_ms (10);
PORTB.F0=1;
PORTB.F1=0;
if (PORTD.F0 == 0) lcdr("*");
else if (PORTD.F1 == 0) lcdr("7");
else if (PORTD.F2 == 0) lcdr("MODE 4 : ADC ");
else if (PORTD.F3 == 0) lcdr("MODE1 : 7SEGMENT ");
delay_ms (10);
PORTB.F1= 1;
PORTB.F2= 0;
if (PORTD.F0 == 0) lcdr("0");
else if (PORTD.F1 == 0) lcdr("8");
else if (PORTD.F2 == 0) lcdr("5");
else if (PORTD.F3 == 0) lcdr("MODE2 : LED");
delay_ms(10);
PORTB.F2=1;
}while(1);
}