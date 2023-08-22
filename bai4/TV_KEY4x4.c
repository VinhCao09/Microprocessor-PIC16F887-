const unsigned char maquetcot[4]= {0xfe,0xfd,0xfb,0xf7};
unsigned int quet_mt_phim()
{
   signed int8 maphim, hang, cot;
      maphim=hang=0xff;
      for (cot=0; cot<4; cot++)
         {
            output_b(maquetcot[cot]);
            if       (!input(pin_b4)) {hang=0; break;}
            else if (!input(pin_b5)) {hang=1; break;}
            else if (!input(pin_b6)) {hang=2; break;}
            else if (!input(pin_b7)) {hang=3; break;}
         }
         if (hang!=0xff) maphim=cot*4+hang;
         return(maphim);
}
            
unsigned int key_4x4()
{
   unsigned int8 mpt1, mpt2;
      mpt1=quet_mt_phim();
      if (mpt1!=0xff)
      {
         delay_ms(10);
         mpt1=quet_mt_phim();
         do{mpt2=quet_mt_phim();}
         while (mpt2==mpt1);
      }
      return(mpt1);
}
            
                 
