#include<reg52.h> 	
unsigned char code table[]="MicroController";  //Ҫ��ʾ������
unsigned char code table1[]="Proteus /Keil C";
sbit RS=P2^0; 				//�Ĵ���ѡ������
sbit RW=P2^1; 				//��д����
sbit EN=P2^2;  				//Ƭѡ����
void delay(unsigned int x){ //��ʱ
	unsigned int i;
	for(i=x;i>0;i--);
}
void write_com(unsigned char com){ 	//дָ���  
	P0 = com;	   			//�ͳ�ָ��
	RS=0;RW=0;EN=1;			//дָ��ʱ��
	delay(200);
	EN=0; 
}
void write_dat(unsigned char dat){ 	//д���ݺ���
	P0 = dat;				//�ͳ�����
	RS=1;RW=0;EN=1;		 	//д����ʱ��
	delay(200);
	EN=0;
}
void init(){   				//��ʼ��
	write_com(0x01); 		//����
	write_com(0x38); 		//����16*2��ʾ��5*7����
	write_com(0x0f); 		//����ʾ����ʾ�������˸
	write_com(0x06); 		//��ַ��1��д������ʱ�������1λ
}
void main(){
	unsigned char i;   
	init();
	write_com(0x80); 		//���Ϊ��һ�е�һ���ַ�
	for(i=0;i<15;i++){    	//��ʾ��һ���ַ�
		write_dat(table[i]);
		delay(3000);    	//��������ٶ�
	}
	write_com(0xC0);  		//���Ϊ�ڶ��е�һ���ַ�
	for(i=0;i<15;i++){	  	//��ʾ�ڶ����ַ�
		write_dat(table1[i]);
		delay(3000);
	}
	write_com(0x02);  		//��긴λ
	while(1);
}