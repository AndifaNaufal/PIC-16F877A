int key,oldkey,show,j,b,i;
const char number[] = {6,91,79,102,109,125,7,127,111,118,63,70};
const char numbercount []={111,127,7,125,109,102,79,91,6,118,63,70};
void turun ();
void segment (int a ){
PORTA=7;
TRISA=0;
TRISD=0;
PORTD=number[a];
delay_ms(1);

}

void turun (int b) {
do {
   j++;
    PORTA.F2 =0;
    PORTA.F2=1;
    PORTD = key;
    Delay_ms(1);
    PORTA.F2=0;

}while(j<=100);
j=0;}

void scanning(){
PORTA=0b00000000;
TRISB=0b00000000;
PORTB=0b00000000;
TRISD=0b00001111;
PORTD=0b00000000;
PORTB.F0 =0;
if (PORTD.F0 == 0) key =9;
else if (PORTD.F1 == 0) key = 6;
else if (PORTD.F2 == 0) key = 3;
else if (PORTD.F3 == 0) key = 0;
portb.f0=1;
delay_ms(1);
portb.f1=0;
if (PORTD.F0 == 0) key =10;
else if (PORTD.F1 == 0) key = 7;
else if (PORTD.F2 == 0) key = 4;
else if (PORTD.F3 == 0) key = 1;
portb.f1=1;
delay_ms(1);
portb.f2=0;
if (PORTD.F0 == 0) key =11;
else if (PORTD.F1 == 0) key = 8;
else if (PORTD.F2 == 0) key = 5;
else if (PORTD.F3 == 0) key = 2;
portb.f2=1;
delay_ms(1);
if (key!=oldkey){
oldkey=key;
show=key;

}
segment (show);
}
void main() {
key=0;
oldkey=0;
do {
scanning();
if (key == 11){
for (i=0;i<=9;i++){
turun (numbercount[b]);
}
}
}while(1);
}