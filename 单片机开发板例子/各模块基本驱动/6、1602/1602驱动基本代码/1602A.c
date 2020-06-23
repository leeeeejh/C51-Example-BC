#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit rs=P3^5;
sbit lcden=P3^4;
sbit lcdrw=P3^7;

sbit dula=P2^6;
sbit wela=P2^7;
uchar table1[]="TX-51STAR MCU";
uchar table2[]="WWW.TXMCU.COM";
void delay(uint x)
{
	uint a,b;
	for(a=x;a>0;a--)
		for(b=10;b>0;b--); 
}

void write_com(uchar com)	 //Щ���RS=0
{
	lcdrw=0;
	P0=com;
	rs=0;
	lcden=0;
	delay(10);
	lcden=1;
	delay(10);
	lcden=0;
	
}

void write_data(uchar dat)	   //д���ݣ�RS=1
{
        lcdrw=0;
	P0=dat;
	rs=1;
	lcden=0;
	delay(10);
	lcden=1;
	delay(10);
	lcden=0;
	
}

void init()
{
	dula=0;
	wela=0;
	write_com(0x38);   //��ʾģʽ���ã�16��2��ʾ��5��7����8λ���ݽӿ�
	delay(20);
	write_com(0x0f);   //��ʾģʽ����
	delay(20);
	write_com(0x06);   //��ʾģʽ���ã�������ƣ��ַ�����
	delay(20);
	write_com(0x01);   //����Ļָ�����ǰ����ʾ�������
	delay(20);	
}
void main()
{
	uchar a;
	init();			  //1602��ʼ��
	write_com(0x80);  //������Ҫ��ʾ�ַ���λ��Ϊ��һ�е�һ��
	a=0;
	while(table1[a]!='\0')	//ֻҪû��д��������־���ͼ���д
		{					//����д�ַ��ĵ�һ�ַ�������whileѭ����
		write_data(table1[a]);
		a++;
		}
	write_com(0x80+0x40);  //���õڶ������ַ���ʾ��λ�ã�Ϊ�ڶ��У���һ��
	a=0;
	for(a=0;a<13;a++)	   //�ܹ�Ҫ��ʾ13���ַ�����ѭ��ʮ���Ρ�
	{					   //����д�ַ��ĵڶ��ַ�������forѭ��
	write_data(table2[a]);
	delay(10);		
	}
	while(1);
}