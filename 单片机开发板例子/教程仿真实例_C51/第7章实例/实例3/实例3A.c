/*���ͳ���*/
#include<reg51.h>
#define uchar unsigned char
char code map[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//'0'~'9'

void delay(unsigned int time){ 
	unsigned int j = 0;
	for(;time>0;time--)
		for(j=0;j<125;j++);
}

void main(void){
   	uchar counter=0;	 	//���������
   	PCON = 0x80;			//�����ʼӱ�
   	SCON = 0x90;			//��ʽ2,SM2=TI=RI=0,�������
   	while(1){   				
		ACC = counter;		//��ȡ��ż��־λֵ
		TB8 = P;			//��װ��ż��־
       	SBUF = counter;		//��������
       	while(TI==0);		//�ȴ��������
       	TI = 0;				//��TI��־λ
       	while(RI==0);		//�ȴ��һ��ش�
       	RI = 0;
		if(RB8 ==0){		//�ж�RB8=0��
			P2 = map[counter];	//��Ϊ0������ʾ�ѷ���ֵ
			if(++counter>9) counter=0;//ˢ�·�������
			delay(500);		//�����������
		}
	}
}



