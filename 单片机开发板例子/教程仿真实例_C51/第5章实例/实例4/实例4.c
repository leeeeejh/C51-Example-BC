#include "reg51.h"
char led_mod[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,	  //led��ģ
				  0x7f,0x6f}; //��ʾ��ģ	  
sbit D1=P3^0;
void delay(unsigned int time){//��ʱ
	unsigned char j=255;	   
	for(;time>0;time--)
		for(;j>0;j--);
} 
key0() interrupt 0 {	      //K0�жϺ���
	unsigned char i;
	D1=!IE0;					  //IE0״̬��� 
	for(i=0;i<=9;i++){    	  //�ַ�0-9ѭ��1Ȧ
		P2=led_mod[i];
		delay(35000);	
	}P2=0x40; 				  //��������-�� 
}  

key1() interrupt 2 {          //K1�жϺ���
	unsigned char i;
	for(i=0;i<=9;i++){    	  //�ַ�0-9ѭ��1Ȧ
		D1=!IE0;				  //IE0״̬���
		P1=led_mod[i];
		delay(35000);	
	}P1=0x40; 				  //��������-�� 
}

void main(){
	unsigned char i;
	TCON = 0x05;			  //���崥����ʽ
 	PX0=0;PX1=1;			  //INT1����
	D1=1;P1=P2=0x40;		  //�����ֵ
	IE=0x85;				  //���ж�
	while(1){
	    for(i=0;i<=9;i++){    //�ַ�0-9����ѭ��
		   P0=led_mod[i];
		   delay(35000);	
		}
	     
	}
}