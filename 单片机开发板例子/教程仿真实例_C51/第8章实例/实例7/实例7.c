#include<absacc.h>
#include<reg51.h>
#define  DAC1  XBYTE[0xfeff]	//����1#DAC0832�����������ķ��ʵ�ַ
#define  DAC2  XBYTE[0xfdff]	//����2#DAC0832�����������ķ��ʵ�ַ
#define  DAOUT XBYTE[0xefff]	//����DAC0832��DAC�Ĵ������ʵ�ַ
void main (void){
     unsigned char num;			//��Ҫת��������
     while(1){
		for(num =0; num <=255; num++){
			DAC1 = num;	   		//�Ͼ������1#DAC
			DAC2 = 255-num;		//�¾������2#DAC
        	DAOUT = num;		//��·ͬʱ����D/Aת�����
		}
     }
}
