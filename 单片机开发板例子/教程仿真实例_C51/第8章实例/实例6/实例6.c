#include<absacc.h>
#define DAC0832 XBYTE[0xfeff]	   		//����DAC0832�ķ��ʵ�ַ
unsigned char num;
void main() {
  while (1) {
    for (num = 0 ; num < 255 ; num++) 	//�����β���
	  DAC0832=num;
   	for (num = 255 ; num > 0 ; num--) 	//�½��β���
	DAC0832=num;
										//DAC0832ת�����
  }
}		  

