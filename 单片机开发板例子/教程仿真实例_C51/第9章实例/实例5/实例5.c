#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit DS1302_SCLK = P3^6;					//1302����λ��������
sbit DS1302_IO = P3^7;
sbit DS1302_RST = P3^5;
sbit LM1602_EN = P2^2;				   		//1602����λ��������
sbit LM1602_RW = P2^1;
sbit LM1602_RS = P2^0;
sbit ACC_7 = ACC^7;						   	//ACCλ��������
sbit ACC_0 = ACC^0;
uchar second,minute,hour,week,day,month,year;
uchar table[]="0123456789";   				//����������ʾ�ַ�
uchar table1[]="Time:  ";
uchar table2[]="Date: ";
uchar t1302[]={0x14,0x7,0x17,0x04,0x21,0x30,0x00}; //1302��ֵ:��,��,��,����,ʱ,��,��

void delay(uint x){             			//��ʱ����
	uint i;
	for(i=x;i>0;i--);
}

uchar read_ds1302(uchar addr){		   		//DS1302�����ݺ���
   	uchar i;
   	DS1302_RST=0;
   	DS1302_RST=1;		  					//����1302ʹ��
	ACC = addr;								//ACC��װ�������ַ
	for(i=8;i>0;i--){	  					
		DS1302_IO = ACC_0;					//���λ�����ɶ˿����
		ACC >>= 1;							//��������1λ
		DS1302_SCLK = 0;					//ʱ��������
		DS1302_SCLK = 1;	 				//ʱ��������
	}
   	for (i=8; i>0; i-- ){
		ACC_7=DS1302_IO;					//λ�����������λ
		ACC >>= 1;							//��������1λ
		DS1302_SCLK = 1;					//ʱ��������
		DS1302_SCLK = 0;					//ʱ��������
	}
	DS1302_RST=0; 							//�ر�1302ʹ��	
	return(ACC);
}

void write_ds1302(uchar addr, uchar dat){ 	//DS1302д���ݺ���
	uchar i;
	DS1302_RST=0;
 	DS1302_RST=1;
	ACC = addr;								//ACC��װ�������ַ
	for(i=8;i>0;i--){	  			  		//���͵�ַ
		DS1302_IO = ACC_0;					//���λ�����ɶ˿����
		ACC >>= 1;							//��������1λ
		DS1302_SCLK = 0;					//ʱ��������
		DS1302_SCLK = 1;	 				//ʱ��������
	}
	ACC = dat;								//ACC��װ���������
	for(i=8;i>0;i--){	         	  		
		DS1302_IO = ACC_0;					//���λ�����ɶ˿����
		ACC >>= 1;							//��������1λ
		DS1302_SCLK = 0;					//ʱ��������
		DS1302_SCLK = 1;	 				//ʱ��������
	}
 	DS1302_RST=0;							//�ر�1302ʹ��
}

void read_1302time() {						//��ȡDS1302��Ϣ
	second = read_ds1302(0x81);	  			//����Ĵ���
	minute = read_ds1302(0x83);	  			//���ּĴ���
	hour = read_ds1302(0x85);	  			//��ʱ�Ĵ���
	//week = read_ds1302(0x8b);	  			//�����ڼĴ���
	month = read_ds1302(0x89);	  			//���¼Ĵ���
	day = read_ds1302(0x87);	  			//���ռĴ���
	year = read_ds1302(0x8d);	  			//����Ĵ���

}

void write_1602com(uchar com){ 	 	  		//LM1602дָ���
	P0 = com;	   							//�ͳ�ָ��
	LM1602_RS=0; LM1602_RW=0; LM1602_EN=1;	//дָ��ʱ��
	delay(100);
	LM1602_EN=0; 
}
 
void write_1602dat(uchar dat){ 				//LM1602�����ݺ���
	P0 = dat;								//�ͳ�����
	LM1602_RS=1; LM1602_RW=0; LM1602_EN=1;	//д����ʱ��
	delay(100);
	LM1602_EN=0;
}

void init_1302(){							//DS1302�ĳ�ʼ��
	write_ds1302(0x8e,0x00);				//��д�����Ĵ���
	write_ds1302(0x8c,t1302[0]);			//��
	write_ds1302(0x88,t1302[1]);			//��
	write_ds1302(0x86,t1302[2]);			//��
	write_ds1302(0x8a,t1302[3]);			//����
	write_ds1302(0x84,t1302[4]);			//ʱ
	write_ds1302(0x82,t1302[5]);			//��
	write_ds1302(0x80,t1302[6]);			//��
	write_ds1302(0x8e,0x80);				//��д�����Ĵ���
}

void init_1602(){   						//1602��ʼ��
	write_1602com(0x38); 					//����16*2��ʾ��5*7����
	write_1602com(0x0c); 					//����ʾ��������ʾ���
	write_1602com(0x06); 					//��ַ��1��д����ʱ�������1λ
}

void display1602(void){			  			//1602��ʾ����
    uchar i;
	write_1602com(0x80);					//��1����Ϣ
	for(i=0;i<6;i++) write_1602dat(table1[i]); 	//��ʾ�ַ���Time����
    write_1602dat(table[(hour/16)]);		//��ʾʱ���֡�����Ϣ
    write_1602dat(table[(hour%16)]);
    write_1602dat(':');
    write_1602dat(table[minute/16]);
    write_1602dat(table[minute%16]);
    write_1602dat(':');
    write_1602dat(table[second/16]);        
    write_1602dat(table[second%16]);

    write_1602com(0x80+0x40);				//��2����Ϣ
    for(i=0;i<6;i++) write_1602dat(table2[i]);	//��ʾ�ַ���Date����
    write_1602dat(table[day/16]);   		//��ʾ�ա��¡�����Ϣ
    write_1602dat(table[day%16]);
    write_1602dat('-');
    write_1602dat(table[month/16]);
    write_1602dat(table[month%16]);
    write_1602dat('-');
    write_1602dat(table[(year/16)]);
    write_1602dat(table[(year%16)]);
}

int main(void){
	init_1302();							//��ʼ��1302
	init_1602();				 			//��ʼ��1602
    while (1){
       read_1302time();			 			//��1302����ʱ����Ϣ
       display1602();				 		//��ʾ����ʱ����Ϣ
	}
}

