#include<reg51.h>
void delay() {	                        //��ʱ
    unsigned int i;
    for (i=0; i<20000; i++) {}
}

void main() { 
    unsigned char index, LED;            //����LEDָ�����ʾ��ģ
    SCON = 0;           	             //���ô���ģ�鹤���ڷ�ʽ0
    while (1) {      
	   LED=0x7f;
	   for (index=0; index < 8; index++) {
	        SBUF = LED;                  //����L0�Ƶ���
	        do {} while(!TI);            //ͨ��TI��ѯ�б������Ƿ��������
            LED = ((LED>>1)|0x80);       //����1λ��ĩλ��1
			TI=0;
			delay();  
 	   }
    }
}
