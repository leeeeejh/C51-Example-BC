		  #include<reg51.h>

unsigned char xdata CONW _at_ 0x7fff;	//������
unsigned char xdata PORTA _at_ 0x7cff;	//A�ڶ���
unsigned char xdata PORTB _at_ 0x7dff;	//B�ڶ���

void main( ){
	CONW=0x82;						//�����ּĴ�����ֵ
	while(1){
		PORTA=PORTB;				//��B�ڶ���ֵ����A��д����
	}
}