	#include <reg51.h> 	
	#define uchar unsigned char	
	bit ldelay=0; 			//����ʱ������
	uchar t=0; 				//��ʱ�������

    void main(void) {  	
		uchar code ledp[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f}; 
		uchar ledi; 		//ָʾ��ʾ˳��
		TMOD=0x01;			//����T0��ʱ��ʽ1
		TH0 =0x3c;TL0 =0xb0;//���20��=1�루12M����) 
		TR0=1; 			
		EA=ET0=1; 		
		while(1){		
	  		if(ldelay) {	//������ʱ�������ǣ����봦��
				ldelay=0; 	//������
				P2=ledp[ledi]; //����һ��ֵ�͵�P2��
				ledi++; 	//ָ����һ��
				if(ledi==8)ledi=0;//�������һ���ƾͻ�����һ��
	}}}

	timer0() interrupt 1 {	//T0�жϺ���
		if(++t==20){t=0; ldelay=1;}//ˢ�³���ʱ������
		TH0 =0x3c;TL0 =0xb0; //����T0��ֵ 
	} 	



