#include <reg51.h>		//51ͷ�ļ�
sbit lock=P3^0;	   		//����˿ڱ���
char key_buf[] = {0xee, 0xde, 0xbe, 0x7e,0xed, 0xdd, 0xbd, 0x7d,//�����ֵ
				  0xeb, 0xdb, 0xbb, 0x7b,0xe7, 0xd7, 0xb7, 0x77};
unsigned char init=0x7f,on=0x73,off=0x79,lock_on=0,lock_off=1; //�����������
char getKey(void) 		//�������ֵ����
{	char key_scan[] = {0xef, 0xdf, 0xbf, 0x7f};	//��ɨ����
	char i = 0, j = 0;
	for (i = 0; i < 4 ; i++) 
	{	P2 = key_scan[i];  						//P2�ͳ���ɨ����
		if ((P2 & 0x0f) != 0x0f)				//�ж����޼��պ�
			for(j=0;j<16;j++) if(key_buf[j]==P2) return j; //���ұպϼ�����
	}
	return -1;				//�޼��պϷ���-1
}
void delay(void)	 		//������ʱ����
{	unsigned int i,j;
	for(i=1;i<=400;i++)
		for(j=1;j<=200;j++);
}

void action(char stat,char num)	//����ٿغ���
{	unsigned char i;
	lock=num; 		//���忪��״̬����
	for(i=1;i<=2;i++) //��ʾ�ַ���˸����
	{	P0=stat;	
		delay();
		P0=0x0;
		delay(); 
	}
	P0=0x40; 		//��ʾ�����ַ���-��
	lock=1;			//����
}
void main(void)					//������ 
{	char key = 0;				//��ֵ��ʼֵ
	action(init,lock_off);		//��ʼ��
	while(1){					//����ѭ��
		key = getKey();			//��ñպϼ���
		if (key != -1){
		  	if (key != 7) action(off,lock_off); //���벻��������
			else action(on,lock_on);	//������ϣ��ȿ���������
		}
	}
}

