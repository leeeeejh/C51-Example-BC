/*********************************************************************

�����ܣ�	����ѧϰ���ϵ�S2����ʱ��һֱ���ţ����ᷢ��Ƶ��Ϊ1000HZ��2000HZ����
			���źţ�ͨ�����������������ھȻ��������ı�������

**********************************************************************/
#include <reg51.h>
#include <intrins.h>

#define uchar unsigned char 
#define uint unsigned int

sbit beep=P2^3;
sbit kaiguan=P3^4;

void delay()		   //���0.5ms���ҵ���ʱ
{
	uint a;
	for(a=55;a>0;a--)
	{
		_nop_();
	}
}
void main()
{	delay();
  	while(1)
	{
		if(!kaiguan)
		{
			uint m;
			for(m=800;m>0;m--)	  //����ʱ��0.5ms*800=0.4s
			{
				beep=~beep;		
				delay();		 //1000HZ���źš�
			}
			for(m=500;m>0;m--)	 //����ʱ��0.5ms*2*500 =0.5s
			{
				beep=~beep;
				delay();
				delay();		//500HZ���źš�
			}
		}
	}
}