#include <reg51.h>
#include <absacc.h>        
#define	AD_IN7	XBYTE[0xfeff]	//IN7ͨ����ַ
sbit ad_busy=P3^3;              //�����ⵥԪ����

void main(void){
     while(1){
       	AD_IN7 = 0;  			//����A/D�ź�                
		while(ad_busy==1); 		//�ȴ�A/Dת������
		P1 = AD_IN7;			//ת��������ʾ
	}
}
