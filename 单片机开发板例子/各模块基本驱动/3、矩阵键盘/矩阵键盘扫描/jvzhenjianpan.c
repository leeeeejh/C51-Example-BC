//4*4���̼�����,���¼�����Ӧ�Ĵ�����ʾ���������
#include<reg51.h>
sbit beep=P2^3;
sbit dula=P2^6;
sbit wela=P2^7;
         unsigned char i=100;
unsigned char j,k,temp,key;
void delay(unsigned char i)
{
  for(j=i;j>0;j--)
    for(k=112;k>0;k--);
}
unsigned char code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,
                        0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void display(unsigned char num)
{
         P0=table[num];
         dula=1;
         dula=0;
         P0=0xc0;	//11000000	��λȫ��
         wela=1;
         wela=0;
}
void main()
{
  dula=0;
  wela=0;
  while(1)
  {

    P3=0xfe;	//P.0=0;��һ�����1
    temp=P3;
    temp=temp&0xf0;	 //��P3����λ ,��������λ����
	 if(temp!=0xf0)
// 	 if((temp==0xe0)||(temp==0xd0)||(temp==0xb0)||(temp==0x70))			   
    {
      delay(10);
      if(temp!=0xf0)  //ȥ��
 // 	 if((temp==0xe0)||(temp==0xd0)||(temp==0xb0)||(temp==0x70))			   
     {	
        temp=P3;	 //��P3	����
        switch(temp)
        {
          case 0xee:  //1110 1 110 ,1��1��
               key=0;
               break;

          case 0xde:  //1101 1110  ��1��2��
               key=1;
               break;

          case 0xbe:   //1011 1110  ��1��3��
               key=2;
               break;

          case 0x7e:   //0111 1110  ��1��4��
               key=3;
               break;
         }
 /*        while(temp!=0xfe)
         {
           temp=P3;
           temp=temp&0xfe;
           beep=0;
         } 
         beep=1; */
        display(key);
         P1=0xfe;
      }
    }

    P3=0xfd;		//1111 1101��ɨ��ڶ���
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
// 	 if((temp==0xed)||(temp==0xdd)||(temp==0xbd)||(temp==0x7d))			   
    {
      delay(10);
      if(temp!=0xf0)	 //������
// 	 if((temp==0xed)||(temp==0xdd)||(temp==0xbd)||(temp==0x7d))			   
      {
        temp=P3;
        switch(temp)
        {
          case 0xed:
               key=4;
               break;

          case 0xdd:
               key=5;
               break;

          case 0xbd:
               key=6;
               break;

          case 0x7d:
               key=7;
               break;
         }
   /*      while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
           beep=0;
         }
         beep=1;  */
         display(key); 	
         P1=0xfd;
      }
      }

    P3=0xfb;	 //1111 1011ɨ������
    temp=P3;
    temp=temp&0xf0;
    if(temp!=0xf0)
//  	 if((temp==0xeb)||(temp==0xdb)||(temp==0xbb)||(temp==0x7b))			   
   { 
      delay(10);
      if(temp!=0xf0)
//  	 if((temp==0xeb)||(temp==0xdb)||(temp==0xbb)||(temp==0x7b))			   
      {	  
        temp=P3;
        switch(temp)
        {
          case 0xeb:
               key=8;
               break;

          case 0xdb:
               key=9;
               break;

          case 0xbb:
               key=10;
               break;

          case 0x7b:
               key=11;
               break;
         }
 /*        while(temp!=0xf0)
         {
           temp=P3;
           temp=temp&0xf0;
           beep=0;
        }
         beep=1; */
         display(key);
         P1=0xfb;  
      }
      }

 	   P3=0xff;	  //1111 0111ɨ������
	   temp=P3;
	   temp=temp&0xf0;	 //0xf0
	    if(temp!=0xf0)	 //0xf0
// 	 if((temp==0xef)||(temp==0xdf)||(temp==0xbf)||(temp==0x7f))			   
    {
      delay(10);
      if(temp!=0xf0)  // 0xf0
// 	 if((temp==0xef)||(temp==0xdf)||(temp==0xbf)||(temp==0x7f))			   
 
      {	
        temp=P3;
        switch(temp)
        {
          case 0xef:
               key=12;
               break;

          case 0xdf:
               key=13;
               break;

          case 0xbf:
               key=14;
               break;

          case 0x7f:
               key=15;
               break;
         }
        while(temp!=0xf0)
 // 		while	((temp==0xef)||(temp==0xdf)||(temp==0xbf)||(temp==0x7f))
         { P3=0xff;
           temp=P3;
           temp=temp&0xf0;
           beep=0;
	        display(key);
 	        P1=0xf7;	
         } 
         beep=1; 
      }
    }

  }
}
