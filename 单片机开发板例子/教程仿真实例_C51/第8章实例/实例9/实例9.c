 #include <reg51.h>
char bit_tab[]={0x20,0x10,0x08,0x04,0x02,0x01};	//��ʾλ����
char disp_tab[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};//������

void delay(unsigned int time){	
	char j;
	for(;time>0;time--)	
		for(j=225;j>0;j--);
}	 

void main()	{  
	unsigned int count;						//����T0����ֵ
	unsigned char led_point; 				//���������ָ��
	TMOD = 0x0D;							//����ΪT0������ʽ1
	TR0 = 1;								//����T0
	while(1){
		count = TH0 * 256 + TL0;			//��ȡT0����ֵ
		for(led_point = 0;led_point < 6; led_point++){ 
		   	P1 = bit_tab[5-led_point];		//������ʾλ
			P2 = disp_tab[count%10];		//��ʾ����ֵ
			count /= 10;					//��������ֵĩλ
			delay (500);
		}
	}
}