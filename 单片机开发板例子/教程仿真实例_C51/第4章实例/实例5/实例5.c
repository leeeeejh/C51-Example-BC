//ʵ��5 LED�������ʾ
#include <reg51.h> 					// 51ͷ�ļ�
char led_mod[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; //LED��ʾ��ģ
void delay(unsigned int time){ 
	unsigned int j = 0;
	for(;time>0;time--)				//���ô����ʵ��ֵ��Ϊtime��ֵ
		for(j=0;j<125;j++);
}
void main() 
{	char i = 0;
	while(1)		  	
	{	for(i=0;i<=9;i++) 
		{	P0=led_mod[i];			//��ȡ��ģ�����P0��
			delay(500); 
		}
	} 
}

