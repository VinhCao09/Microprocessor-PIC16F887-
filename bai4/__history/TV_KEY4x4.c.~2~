unsigned int8 key_4x4()
{
   const unsigned int8 maquet[]={0xef,0xdf,0xbf,0x7f};
   unsigned int8 mp=0xff,cot;
   for(cot=0;cot<4;cot++)
   {
   output_b(maquet[cot]);
   while(input(pin_b0)==0) mp=cot*4;
   while(input(pin_b1)==0) mp=cot*4+1;
   while(input(pin_b2)==0) mp=cot*4+2;
   while(input(pin_b3)==0) mp=cot*4+3;
   }
   return mp;
}
