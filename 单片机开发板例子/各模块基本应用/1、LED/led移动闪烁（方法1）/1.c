/********************************************************************
				
�����ܣ�	ʹ��λLED��λ�ƶ�������ѭ����
			���ַ�����򵥡�

**********************************************************************/
#include <reg51.h>
#include <intrins.h>  //���ͷ�ļ�����������ĺ��ģ�������������λ��������
					  //�������е�_crol_(P1,y)

sbit led=P1^0;

void delay(unsigned int i)
{
	unsigned int j;
	unsigned char k;
	for(j=i;j>0;j--)		//Լ300ms
		for(k=144;k>0;k--);	 //(132,11.0592MHz).(144,12MHz)Լ0.3ms
}

void main()
{	P1=0xfe;
	delay(1000);
	while(1)
	{
		unsigned char m;
		P1=0xfe;
		delay(1000);
		for(m=7;m>0;m--)
		{
			P1=_crol_(P1,1);   //P1������һλ��
			delay(1000);
		}
	}
}