#include <reg51.h>
sbit P2_0=P2^0;
void timer0 (void) interrupt 1 {
   P2_0 = !P2_0; 		//P1.0ȡ��
   TH0 = 0xfc; 			//������ֵ��װ��
   TL0 = 0x18;
}
void main (void) {
   TMOD = 0x01;             //T0��ʱ��ʽ1
   P2_0=0;
   TH0=0xfc;         		//Ԥ�ü�����ֵ
   TL0=0x18;
   EA=1; 
   ET0=1; 
   TR0=1;
   do { } while (1);
}
