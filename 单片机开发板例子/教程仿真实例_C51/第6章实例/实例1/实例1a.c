#include <reg51.h>
sbit P2_0=P2^0;
void main (void) {
   TMOD = 0x01;          //T0��ʱ��ʽ1
   TR0=1;                //����T0
   for( ; ; ){
      TH0 = 0xfc; 		//װ�ؼ�����ֵ
      TL0 = 0x18;
      do{ } while(!TF0); //��ѯ�ȴ�TF0��λ
      P2_0 =!P2_0;       //��ʱʱ�䵽P1.0����
      TF0 = 0;           //�����TF0
	}
}
