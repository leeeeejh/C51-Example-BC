//���ͨ�ţ�����������
#include <reg51.h>
#define uchar unsigned char
#define NODE1_ADDR 1  		//1#�ӻ���ַ
#define NODE2_ADDR 2		//2#�ӻ���ַ

uchar KeyValue=0;			//��ֵ
uchar code str[]="0123456789ABCDEF";  //�ַ���
uchar pointer_1=0,pointer_2=0;		//�ӻ���ǰ�����ַ�ָ��

void delay(uchar time){				//��ʱ
	uchar i,j;
	for(i=0;i<130;i++)
		for(j=0;j<time;j++);
} 

void proc_key(uchar node_number){	 //���ͳ���
	delay(200);
	SCON=0xc0;			//���ڷ�ʽ3�����ͨ�š�������ա��жϱ�־����
	TMOD=0x20;			//T1��ʱ��ʽ2
	TH1=TL1=0xfd;		//9600bps
	TR1=1;				//����T1		
	TB8=1;	   			//���͵�ַ֡
	SBUF=node_number;
	while(TI==0);		//�ȴ���ַ֡���ͽ���
	TI=0;				//��TI��־
	TB8=0;				//׼����������֡
	switch(node_number){//�л��ӻ�
		case 1: {
			SBUF=str[pointer_1++];	//1#�ӻ��ַ�֡
			if(pointer_1>=16) pointer_1=0;	 //�޸ķ���ָ��
			break;
		}
		case 2: {
			SBUF=str[pointer_2++];	//2#�ӻ��ַ�֡
			if(pointer_2>=16) pointer_2=0;	 //�޸ķ���ָ��
			break;
		}
		default: break;
	while(TI==0);		//�ȴ�����֡���ͽ���
	TI=0;
}}

main(){
	while(1){						
		P1=0xff;
		while(P1==0xff);	  //��ⰴ��
		switch(P1){			  //�л��ӻ�
			case 0xfe: proc_key(NODE1_ADDR);break;
			case 0xef: proc_key(NODE2_ADDR);break;
		}
	}
}  


