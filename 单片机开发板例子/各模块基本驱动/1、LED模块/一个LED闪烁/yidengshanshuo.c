/********************************************************************
			
�����ܣ�	��һLED��˸ʮ�κ�ֹͣ��

**********************************************************************/
#include <reg51.h>

sbit led=P2^3;

void delay(unsigned int i)
{
	unsigned int j;
	unsigned char k;
	for(j=i;j>0;j--)
		for(k=125;k>0;k--) ;
}

void main()
{
	unsigned char m;
	for(m=20;m>0;m--)
	{
		led=~led;	//��ÿ��һ��ʱ�伴�����ȡ����AA	55
		delay(3000); //��˸�����
	}
	while(1); //��˸ʮ�κ󣬵��˲�����˸��
}