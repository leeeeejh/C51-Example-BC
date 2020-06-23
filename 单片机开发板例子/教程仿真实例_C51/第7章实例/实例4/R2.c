//���ͨ�ţ�2#�ӻ���

#include <reg51.h>
#define NODE2_ADDR 2
#define uchar unsigned char

uchar i,j;
sbit P3_7=P3^7;
uchar code table[16]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
					  0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};

void display(uchar ch){
	if((ch>=48)&&(ch<=57)) P2=table[ch-48];
	else if((ch>=65)&&(ch<=70)) P2=table[ch-55];
}					  

main(){
	SCON=0xf0;		//���ڷ�ʽ3�����ͨ�š�������ա��жϱ�־����
	TMOD=0x20;		//T1��ʱ��ʽ2
	TH1=TL1=0xfd;	//9600bps
	TR1=1;			//����T1
	ES=1;EA=1;		//���ж�
	while(1);
}

void receive(void) interrupt 4 {
	RI=0;
	if(RB8==1){
		if(SBUF==NODE2_ADDR){
			SM2=0;
			P3_7=!P3_7;
		}
		return;
	}
	display(SBUF);
	SM2=1;
}

