/*���ճ���*/
#include<reg51.h>
#define uchar unsigned char
char code map[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//'0'~'9'
void main(void){
   uchar receive;		    	//���������
   PCON = 0x80;					//�����ʼӱ�
   SCON = 0x90;					//���ڷ�ʽ2,TI��RI����,�������
   while(1){  
		while(RI==1){			//�ȴ��������
			RI = 0;				//��RI��־λ
			receive = SBUF;		//ȡ�ý���ֵ
			ACC = receive;		//��ȡ��ż��־λ
			if (P == RB8) TB8=0;//����־λֵװ���9λ
			  else TB8 = 1;
			SBUF = receive;		//���յĽ����������
			while(TI == 0);		//�ȴ����ͽ���
			TI = 0;		   		//��TI��־λ
			P2 = map[receive];  //��ʾ����ֵ
		}
    }
}
