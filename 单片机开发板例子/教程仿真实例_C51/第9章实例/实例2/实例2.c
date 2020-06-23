#include <REG51.H>
#include <math.h>
sbit din = P3^0;   				//����оƬ���ű���
sbit clk = P3^1;
sbit cs = P3^2;
#define  PI 3.1415

void da(unsigned int value);	

void main() {
	unsigned int num,value;
	while (1) {
		for (num = 180 ; num < 360 ; num++){	  //���������Ҳ���
			value = 2047 + 2047 * sin((float)num / 180 * PI);
			da(value); 
  		}
	}
}

void da(unsigned int v){		 //DAת��
	char i = 11;
	cs = 1;
	cs = 0;						//CS�����øߵ�ƽ
	for ( ; i >= 0 ; i--) {
	 	din = (v >> i) & 0x01;	//�ֽⲢ�����ݣ���������DIN����
		clk = 1;				//����ʱ������
		clk = 0;
	}
	cs = 1;	   					//������13������
	cs = 0;						//CS�����õ͵�ƽ
}


