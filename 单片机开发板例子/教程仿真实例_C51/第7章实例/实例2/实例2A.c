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
   	uchar counter=0;		//���������
   	TMOD=0x20;				//T1��ʱ��ʽ2
   	TH1 = TL1 = 0xf4;		//2400b/s
   	PCON=0;					//�����ʲ��ӱ�
   	SCON = 0x50;			//���ڷ�ʽ1,TI��RI����,�������;
	TR1=1;					//����T1   
	while(1){   	
       SBUF = counter;		//���������ź�
       while(TI==0);		//�ȴ��������
       TI = 0;				//��TI��־λ
       while(RI==0);		//�ȴ��һ��ش�
       RI = 0;
	   if(SBUF ==counter){  //������ֵ�뷢��ֵ��ͬ,��֯������
	      P2 = map[counter];	    //��ʾ�ѷ���ֵ
	      if(++counter>9) counter=0;//����������ֵ
	      delay(500);
		}
	}
}



