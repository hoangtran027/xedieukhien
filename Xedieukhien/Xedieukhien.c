// 4 dong co
#include <Xedieukhien.h>
#include <stdio.h>
#include <string.h>
#fuses nowdt,noput,hs,noprotect
#use delay(clock=20M)
#use RS232(uart1, BAUD=9600,BITS=8,PARITY=N,XMIT=PIN_C6,RCV=PIN_C7)
#define DC1 pin_d0
#define DC2 pin_d1
#define DC3 pin_d2
#define DC4 pin_d3
char VALUE;
#int_RDA
void nhan()
{
  if(kbhit())
  { 
    VALUE=getch();
  }
}

void tien()
{
  output_high(DC1);
  output_low(DC2);
  output_high(DC3);
  output_low(DC4);
}
void lui()
{
   output_low(DC1);
   output_high(DC2);
   output_low(DC3);
   output_high(DC4);
}
void trai()
{
   output_high(DC1);
   output_low(DC2);
   output_low(DC3);
   output_high(DC4);
}
void phai()
{
   output_low(DC1);
   output_high(DC2);
   output_high(DC3);
   output_low(DC4);
}


void main()
{
   enable_interrupts(global);
   enable_interrupts(int_RDA);
   output_low(DC1);
   output_low(DC2);
   output_low(DC3);
   output_low(DC4);
   while(TRUE)
   {
       if(VALUE=='1')
       {
         tien();
       }
       if(VALUE=='2')
       {
         lui();     
       }
       if(VALUE=='3')
       {
         trai();    
       }
       if(VALUE=='4')
       {
         phai();   
       }
   }

}
