#include <reg51.h>
sbit P2_0=P2^0;

timer0 () interrupt 1 {   	//T0��ʱ�ж�
   P2_0 = !P2_0; 			//P1.0ȡ��
}

main(){
   TMOD = 0x02; 			//T0��ʱ��ʽ2
   TH0 = TL0 = 0x06;
   EA= ET0 = 1; 
   TR0=1; 		
   while(1);
}
