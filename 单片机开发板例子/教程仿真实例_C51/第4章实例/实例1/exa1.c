#include <reg51.h>		//ͷ�ļ�
sbit p1_0=P1^0;			//�������p1_0
main()					//������
{	void delay(int x);	//��������
	int time=1000;		//��ʱ����
	while(1) 			//����ѭ��
	{	p1_0=!p1_0;		//p1_0����ȡ��
		delay(time);	//������ʱ����
	}
}
void delay(int x)		//��ʱ��������
{	int i;				//�������i
	for(i=1;i<=x;x++);	//��ѭ��
}