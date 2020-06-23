#include <reg51.h>
unsigned char code table[]={0x3f,0x06,0x5b,0x4f,
                  0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char count=0;        //����������ֵ

int0_srv () interrupt 1{	  //T0�жϺ���
	if(++count==100) count=0; //�ж�ѭ���Ƿ���
	P0=table[count/10];	      //��ʾʮλ��
	P2=table[count%10];	      //��ʾ��λ��
}  

main(){
   P0=P2=table[0];			  //��ʾ��ֵ��00��
   TMOD=0x06;				  //T0������ʽ2
   TH0=TL0=0xff;			  //������ֵ
   ET0=1;					  //���ж�
   EA=1;
   TR0=1;					  //����T0
   while(1);
} 


