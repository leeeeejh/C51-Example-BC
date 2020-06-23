#include "reg51.h"
unsigned char led[]={0xfe,0xfd,0xfb,0xf7};//LED�ƵĻ�������
void delay(unsigned char time){ 	     //��ʱ����
	unsigned int j=15000;
	for(;time>0;time--)
		for(;j>0;j--);
} 
void main(){ 
	bit dir=0,run=0;				    //��־λ���弰��ʼ��
	char i;
	while(1){ 
		switch (P0 & 0x0f){			 	//��ȡ��ֵ
			case 0x0e:run=1;break;		//K1��������run=1
			case 0x0d:run=0,dir=0;break;//K2��������run=dir=0
			case 0x0b:dir=1;break;		//K3��������dir=1
			case 0x07:dir=0;break;	    //K4��������dir=0
		}
		if (run) 						//��run=dir=1, ���϶�������
			if(dir)
				for(i=0;i<=3;i++){
					P2=led[i];
					delay(200);
				}
		    else						//��run=1,dir=0, ���¶�������
				for(i=3;i>=0;i--){
					P2=led[i]; 
					delay(200);
				}
	    else P2=0xff; 					//��run=0����ȫ��
	}
}