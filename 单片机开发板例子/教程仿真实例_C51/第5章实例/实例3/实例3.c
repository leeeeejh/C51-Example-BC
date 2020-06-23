#include "reg51.h"
char led[]={0xfe,0xfd,0xfb,0xf7};//LED��������
bit dir=0,run=0;     			//ȫ�ֱ���
void delay(unsigned int time);	 
key() interrupt 0{				//�����жϺ���
	switch (P0 & 0x0f){			//�޸ı�־λ״̬
		case 0x0e:run=1;break;
		case 0x0d:run=0,dir=0;break;
		case 0x0b:dir=1;break;
		case 0x07:dir=0;break;
}} 
void main(){ 
	char i;
	IT0=1;EX0=1;EA=1;//���ش�����INT0�������ж�����
	while(1){ 
		if (run) 			  
			if(dir)			  //��run=dir=1,���϶�������
				for(i=0;i<=3;i++){
					P2=led[i];
					delay(200);
				}
		    else			  //��run=1��dir=0,���¶�������
				for(i=3;i>=0;i--){
					P2=led[i];
					delay(200);
				}
	    else P2=0xff;            //��run=0,��ȫ��
}}
void delay(unsigned int time){ 
	unsigned int j = 0;
	for(;time>0;time--)
		for(j=0;j<125;j++);
}