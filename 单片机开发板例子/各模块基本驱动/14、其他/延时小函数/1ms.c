/**************************************************************************
�����ܣ�  �ó���ֻ������11.0592MHz�ľ���
			����һЩ���õ�С��ʱ��
			���õ��������ʱ�ķ�����ռ��CPU��Դ��
*******************************************************************************/

#include <reg51.h>

void delay100ms(void)   //��ʱ100ms  ��� -0.000000000023us
{
    unsigned char a,b;
    for(b=221;b>0;b--)
        for(a=207;a>0;a--);
}

void delay10ms(void)   //��ʱ10ms�� ��� -0.000000000002us
{
    unsigned char a,b;
    for(b=249;b>0;b--)
        for(a=17;a>0;a--);
}

void delay1ms(void)   //��ʱ1ms����� -0.651041666667us
{
    unsigned char a,b;
    for(b=102;b>0;b--)
        for(a=3;a>0;a--);
}

void delay100us(void)   //��ʱ100΢�룬��� -0.173611111111us
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=43;a>0;a--);
}

void delay10us(void)   //��ʱ10΢�� ��� -0.234375us
{
    unsigned char a;
    for(a=3;a>0;a--);
}

void main()
{
	char m;
	for(m=0;m<4;m++)	 //��������ʱ4*10ms=40ms��
	{
		delay10ms();
	}
}