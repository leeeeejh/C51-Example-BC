#include<reg51.h>
unsigned char delay_par=0x8;  				//���ƴ�����ֵ
unsigned char light_code=0xf7;				//����λ�ó�ֵ

void delay(void){	         				//�ɿع败��ά��ʱ��
  	unsigned char i=5; 
  	if(i>=0)  i--;		
}

void main(){
  	TCON=0x01;	           					//�ж�����Ϊ�½��ش���
  	EA=1;					   
  	EX0=1;				  					//���ж�
  	while(1);				  
}

void INT0_srv(void) interrupt 0 {
	P1=light_code;							//�����ɿع�(���ƿ�ʼ) 
	delay();								//��ʱ20us
	P1=0xff;								//�ضϴ���
	delay_par--;							//ͳ�����ƴ���
	if(delay_par==0){						//�л�����λ��
		switch(light_code){
			case 0xf7:	 light_code=0xfb;    break;
			case 0xfb:	 light_code=0xfd;	 break;
			case 0xfd:	 light_code=0xfe;	 break;
			case 0xfe:	 light_code=0xf7;	 break;
			default: 	 break;
		}
		delay_par=0x8;	 					//�������ƴ���
	}  
}