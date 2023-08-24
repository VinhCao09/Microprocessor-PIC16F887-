#include<16f887.h>
#device adc=10
#fuses hs
#use delay(clock=20M)
#define       lcd_e        pin_c7
#define       lcd_rw       pin_c6
#define       lcd_rs       pin_c5
#define       output_lcd   output_d
#include<TV_LCD.c>
unsigned int8 bdn0=0,bdn1=0,bdn2=0,giay0=0,giay1=0,giay2=0,KQ;
#int_ad
void ngat_adc()
{
kq=read_adc(adc_read_only)/2.046;
}
#int_timer0 
void ngatt0()
{
 bdn0++;
 set_timer0(3);
}
#int_timer1 
void ngatt1()
{
 bdn1++;
 set_timer1(3036);
}
#int_timer2 
void ngatt2()
{
 bdn2++;
}

void TIME()
{
          if(bdn0>=77)
          {
                bdn0=bdn0-77;
                giay0++;
                if (giay0==60) giay0=0;
          }
          if(bdn1>=10)
          {
                bdn1=bdn1-10;
                giay1++;
                if (giay1==60) giay1=0;
          }
          if(bdn2>=77)
          {
                bdn2=bdn2-77;
                giay2++;
                if (giay2==60) giay2=0;
          }
}
void XUAT_LCD()
{
    lcd_command(0x80);
  printf(lcd_data,"Timer0: %u ",giay0);
    lcd_command(0xc0);
  printf(lcd_data,"Timer1: %u ",giay1);
    lcd_command(0x94);
  printf(lcd_data,"Timer2: %u ",giay2);
      lcd_command(0xd4);
  printf(lcd_data,"NHIET DO: %u  ",kq);
}
void main()
{
   set_tris_a(0xff);
   set_tris_c(0);
   set_tris_d(0);
   lcd_setup();
       setup_timer_0(T0_internal|T0_DIV_256); 
       set_timer0(3); 
       enable_interrupts(int_timer0); 
       setup_timer_1(T1_internal|T1_DIV_BY_8);
       set_timer1(3036);
       enable_interrupts(int_timer1); 
       setup_timer_2(T2_DIV_BY_16,254,16); 
       set_timer2(254); 
       enable_interrupts(int_timer2); 
       setup_adc(ADC_CLOCK_DIV_32);
       setup_adc_ports(sAN0|VSS_VDD);
       set_adc_channel(0);
       enable_interrupts(int_ad); 
       enable_interrupts(global); 
 while(true)
 {
  TIME();
  read_adc(adc_start_only);       
  XUAT_LCD();

 }
}
