//ʵ��4 ��ˮ��
#include <reg51.h>	
#include <intrins.h> //������ѭ����λ�⺯����ͷ�ļ�

void delay(void)	 //������ʱ����
{	unsigned char i,j;
	for(i=1;i<=100;i++)
		for(j=1;j<=200;j++);
}

void main()
{	P2=0x7f;		//P2��ֵ����01111111B����Ӧ��D8��������
	delay();		//��ʱ
	while(1){ 		//����ѭ��
		P2 =_cror_(P2,1); //������ѭ����λ�⺯����P2��ѭ��1λ
		delay();	//��ʱ
	}
}

   
  