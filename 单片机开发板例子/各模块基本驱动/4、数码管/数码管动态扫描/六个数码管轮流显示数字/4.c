/********************************************************************
			

�����ܣ�	��ѧϰ�����λ�����������ʾ����0��5��

**********************************************************************/
#include <reg51.h>

sbit dula=P2^6;		//��ѡ�źŵ�����������
sbit wela=P2^7;		//λѡ�źŵ�����������

unsigned char code wei[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf};
						//����ܸ�λ�����
unsigned char code duan[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d};
						//0-5�����
void delay(unsigned int i)
{
	unsigned int m,n;
	for(m=i;m>0;m--)
		for(n=112;n>0;n--);
}

void main()
{
	unsigned char num;
//	delay(1);
	while(1)
	{
		for(num=0;num<6;num++)
		{
			P0=0x00;	  
			dula=1;
			dula=0;
			P0=wei[num];	   
			wela=1;
			wela=0;

			P0=duan[num];	  
			dula=1;
			dula=0;

		//	delay(50);
		 }
	}
}

