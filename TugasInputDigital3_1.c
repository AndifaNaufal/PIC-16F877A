int key,oldkey,show;
int k=0;
char temp[5];

const char a[] = {6,91,79,102,109,125,7,127,111,118,63,70};
const char countdown[] = {63,6,91,79,102,109,125,7,127,111,118};

void down(int digit, int turun, int nilaidigit){
 do{
   turun++;

   if (nilaidigit<10) PORTA.F4=0;
   else PORTA.F4=1;
   Delay_ms(1);
   PORTA.F4=0;
   PORTA.F5=1;
   PORTD=digit;
   Delay_ms(1);
   PORTA.F5=0;
 } while(turun<=250);
}

void segment (int keypad,int i){
     int x,l;
     int b[1];
     TRISA=0;
     TRISD=0;
     if (keypad==11){
        if (i==2) x=b[1];
        for (l=x; l>=0; l--){
            down(countdown[l%10], 0, l);
        }
     }
     else {
        if (i==1) {
        PORTA.F5=1;
        PORTD=a[keypad];
        temp[1]=a[keypad];
        if (keypad==10) b[1]=0;
        else if (keypad>=0 && keypad<=8) b[1]=keypad+1;
     }

     Delay_ms(1);
  }
  }


void scanning(){
PORTA=0;
TRISB=0b00000000;
PORTB=0b00000000;
TRISD=0b00001111;
PORTD=0b00000000;

PORTB.F0 =0;
if (PORTD.F0 == 0) key =9;
else if (PORTD.F1 == 0) key = 6;
else if (PORTD.F2 == 0) key = 3;
else if (PORTD.F3 == 0) key = 0;
PORTB.F0=1;
delay_ms(1);

PORTB.F1=0;
if (PORTD.F0 == 0) key =10;
else if (PORTD.F1 == 0) key = 7;
else if (PORTD.F2 == 0) key = 4;
else if (PORTD.F3 == 0) key = 1;
PORTB.F1=1;
delay_ms(1);

PORTB.F2=0;
if (PORTD.F0 == 0) key =11;
else if (PORTD.F1 == 0) key = 8;
else if (PORTD.F2 == 0) key = 5;
else if (PORTD.F3 == 0) key = 2;
PORTB.F2=1;
delay_ms(1);

if (key!=oldkey){
oldkey=key;
show=key;
k++;
}

if (k==0) segment(10,1);
else segment(show,k);
if(key==11) k=0;
}

void main() {
key=10;
oldkey=10;

do {
   scanning();
}while(1);

}