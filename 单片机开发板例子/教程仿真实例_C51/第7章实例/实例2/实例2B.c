/*���ճ���*/
#include<reg51.h>
#define uchar unsigned char
char code map[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//'0'~'9'

void main(void){
   	uchar receiv;		    //������ջ���
   	TMOD=0x20;				//T1��ʱ��ʽ2
   	TH1=TL1=0xf4;			//2400b/s
   	PCON=0;					//�����ʲ��ӱ�
   	SCON=0x50;				//���ڷ�ʽ1,TI��RI����,�������;
	TR1=1;					//����T1
   	while(1){  
		while(RI==1){		//�ȴ��������
   		   RI = 0;			//��RI��־λ
   		   receiv = SBUF;	//ȡ�ý���ֵ
		   SBUF = receiv;	//�����������
		   while(TI==0);	//�ȴ����ͽ���
		   TI = 0;		   	//��TI��־λ
		   P2 = map[receiv];//��ʾ����ֵ
   	   }
    }
}



