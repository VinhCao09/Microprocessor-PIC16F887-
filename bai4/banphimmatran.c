#include<16f887.h>
#include<TV_PICKIT2_SHIFT_KEY4X4_138.c>
#fuses intrc_io
#use delay(clock=8M)
int32 i,LED,a,j,LED1,mp,m;
//chuong trinh quet phim
      
          




//chuong trinh check phim va kiem tra trong chuong trinh con
//chong doi phim
void check()
{
mp=key_4x4();
if (mp==0) m=0;
if (mp==1) m=1;
if (mp==2) m=2;
if (mp==3) m=3;
if (mp==4) m=4;
if (mp==5) m=5;
if (mp==6) m=6;
if (mp==7) m=7;
if (mp==8) m=8;
if (mp==9) m=9;
}
   

void choptat()
{
   for(i=0;i<3;i++)
   {
   
   led=0xFFFFFF; //1111 1111 1111 1111 1111 1111
   output_d(LED);
   output_c(LED>>8);
   output_a(LED>>16);
   delay_ms(50);
   check();
   led=0x000000; //0000 0000 0000 0000 0000 0000
   output_d(LED);
   output_c(LED>>8);
   output_a(LED>>16);
   delay_ms(50);
   check();
 
   }
}

void sangdanpst()
{
LED=0x000001; //0000 0000 0000 0000 0000 0001
   for(i=0;i<=24;i++)
   {

 
   LED=(LED<<1)+0x01;
   output_d(LED);
   output_c(LED>>8);
   output_a(LED>>16);
   delay_ms(50);
   check();
   }
}
void sangdantsp()
{
   for(i=0;i<=24;i++)
   {

   LED=~(0xffffff>>i);
 
    output_d(LED);
   output_c(LED>>8);
   output_a(LED>>16);
   delay_ms(50);
   check();
   }
 }
   
void tatdanpst()
{
   for(i=0;i<=24;i++)
   {

 
   LED=0xffffff<<i; //1111 1111 1111 1111 1111 1111
   output_d(LED);
   output_c(LED>>8);
   output_a(LED>>16);
   delay_ms(50);
   check();
   }
}

void tatdantsp()
{
   for(i=0;i<=24;i++)
   {


   LED=0xffffff>>i;
   output_d(LED);
   output_c(LED>>8);
   output_a(LED>>16);
   delay_ms(50);
 check();
   }
}
 
void sangdichpst()
{
   for(i=0;i<=24;i++)
   {


   LED=0x000001<<i; 
   output_d(LED);
   output_c(LED>>8);
   output_a(LED>>16);
   delay_ms(50);
  check();
   }
}

void sangdichtsp()
{
   for(i=0;i<=24;i++)
   {
   LED=0x800001>>i;  
   output_d(LED);
   output_c(LED>>8);
   output_a(LED>>16);
   delay_ms(50);
   check();
   }
}

void sangdich3ledpst()
{
   for(i=0;i<=24;i++)
   {

   check();
   LED=0x000007<<i;
   output_d(LED);
   output_c(LED>>8);
   output_a(LED>>16);
   delay_ms(50);

   }
}

void sangdich3ledtsp()
{
   for(i=0;i<=24;i++)
   { 


   LED=0xE00000>>i;
   output_d(LED);
   output_c(LED>>8);
   output_a(LED>>16);
   delay_ms(50);
   check();

   }
} 

void sangdontsp()
{
a=0;
for(i=0;i<24;i++)
   {
   
   LED1=0x800000; 
   for(j=0;j<24-i;j++)
   {
      LED=LED1|a;
      
      output_d(LED);
      output_c(LED>>8);
      output_a(LED>>16);
      delay_ms(50);
      LED1=LED1>>1;
      check();
   }
   a=LED; 
   }
}



void main()
{
set_tris_d(0);
set_tris_c(0);
set_tris_a(0);
set_tris_b(0xff);
set_tris_e(1);



while(true)
{
    switch (m) 
         {
    case 0:
      choptat();
      break;
    case 1:
      sangdanpst();
      break;
    case 2:
   tatdantsp();
         
         break;
     case 3:
         sangdantsp();  
         
        break;
     case 4: 
         tatdanpst();
             
        break;
      case 5:
         sangdichpst();
            
        break;
      case 6:
         sangdichtsp();    
         break;
        case 7:
         sangdich3ledpst();    
         break;
       case 8:
       sangdich3ledtsp();    
       break;
        case 9:
       sangdontsp();    
       break;
    default:
        // default statements
         }
   
}
   
}
