#include <reg51.h>
#define uchar unsigned char
uchar time;			 //�жϴ���
uchar period=250;	 //1�����ڵĴ���
uchar high=50;		 //20%�ߵ�ƽ�Ĵ���

timer0() interrupt 1{//T0�жϺ���
	TH0=0xd1;		 //��װ�ؼ�����ֵ
	TL0=0x20;
	if (++time==high) P2=0;//�ߵ�ƽʱ�䵽��P2���
	else if (time==period)
		{time=0;P2=1;}//����ʱ�䵽��P2���
}

void main (){
   TMOD = 0x01; 	//T0��ʱ��ʽ1
   TH0 = 0xd1;		//�״�װ�������ֵ
   TL0 = 0x20;		
   EA=ET0=1;		
   TR0 = 1;			//����������
   do { }while (1);
}