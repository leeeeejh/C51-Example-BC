#include<reg51.h>
void serial(char byte) 
{
	SCON = 0;			//���ڷ�ʽ0
	SBUF = byte; 	//����������뻺����
	while(TI!=1);	//�ȴ���λ����
	TI=0;	   			//�����־λ
}
