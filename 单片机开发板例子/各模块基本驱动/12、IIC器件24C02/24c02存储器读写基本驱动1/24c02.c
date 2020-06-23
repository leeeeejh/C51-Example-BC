/*****************************************************************
�����ܣ�  ��IIC��������24c02EEPROM�е�ַΪ0�Ĵ洢��Ԫ��д������0xaa
			���������������P1�ڣ��ɹ۲쵽P1��������LED���汻������
			��ҪΪ����ϰIIC���ߵ����������Լ�24C02�Ĳ���������
***************************************************************/
//����AT24C02EEPROMоƬ����
#include<reg51.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit sda=P2^0;                          //IO�ڶ���
sbit scl=P2^1;

void nop()
{
	_nop_();
	_nop_();
}
/////////24C02��д��������////////////////////
void delay1(unsigned int m)
{	unsigned int n;
  	for(n=0;n<m;n++);
}

void init()  //24c02��ʼ���ӳ���
{
	scl=1;
	nop();
	sda=1;
	nop();
}

void start()        //����I2C����
{
	sda=1;
	nop();
	scl=1;
	nop();
	sda=0;
	nop();
	scl=0;
	nop();
}

void stop()         //ֹͣI2C����
{
	sda=0;
	nop();
	scl=1;
	nop();
	sda=1;
	nop();
}

void writebyte(unsigned char j)  //дһ���ֽ�
{
	unsigned char i,temp;
   	temp=j;
   	for (i=0;i<8;i++)
   {
	   temp=temp<<1;
	   scl=0;
	   nop();
	   sda=CY;		//temp����ʱ���Ƴ���ֵ������CY��
	   nop();
	   scl=1;		//��sda���ϵ������ȶ��󣬽�scl����
	   nop();
   }
   scl=0;
   nop();
   sda=1;
   nop();
}

unsigned char readbyte()   //��һ���ֽ�
{
   unsigned char i,j,k=0;
   scl=0; nop(); sda=1;
   for (i=0;i<8;i++)
   {  
		nop(); scl=1; nop();
      	if(sda==1) 
		j=1;
      	else
		j=0;
      	k=(k<<1)|j;
	  	scl=0;
	}
   	nop();
	return(k);
}

void clock()         //I2C����ʱ��
{
   unsigned char i=0;
   scl=1;
   nop();
   while((sda==1)&&(i<255))
   	  i++;
   scl=0;
   nop();
}

////////��24c02�ĵ�ַaddress�ж�ȡһ���ֽ�����/////
unsigned char read24c02(unsigned char address)
{
   unsigned char i;
   start();
	   writebyte(0xa0);	//������10100000��д
	   clock();
	   writebyte(address);// ��Ƭ�ڿ�ʼ��ַ
	   clock();
	   start();
	   writebyte(0xa1);	  //������10100001����
	   clock();
	   i=readbyte();	  //��һ�ֽ�
   stop();
   delay1(100);
   return(i);
}

//////��24c02��address��ַ��д��һ�ֽ�����info/////
void write24c02(unsigned char address,unsigned char info) //adderss=0��info=0xaa
{
   start();
   writebyte(0xa0);		//�����֣�д
   clock();
   writebyte(address); 	//д���ַ0
   clock();
   writebyte(info);		//д����1010_1010
   clock();
   stop();
   delay1(5000); //�����ʱһ��Ҫ�㹻��������������Ϊ24c02�ڴ�sda��ȡ�����ݺ󣬻���Ҫһ��ʱ�����¼���̡�
}

void main()
{
	init();        //��ʼ��24C02
	write24c02(0,0xaa);//��24c02�еĵ�ַΪ0�Ĵ洢��Ԫд��16��	P1=read24c02(0);//Ȼ���ٽ����ݶ�������P1�ڣ�ͨ��led���������ʾ��
	while(1);
}

