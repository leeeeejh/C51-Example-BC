 //š����λ������������ܵ�ǰ��λ��ʾ0-255֮�����ֵ������ǰ�ģ���ѹת���������źš�
//��Щš����λ��������������ܲ��ᶯ̬�仯�����û�����ʵ����ϵ�S22��λ�����ɸ�������
//�������������ԭ���Ǻ�ADоƬ�����һЩ�����йء�
#include<reg51.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit adrd=P3^7;                          //IO�ڶ���
sbit adwr=P3^6;
sbit diola=P2^5;
sbit dula=P2^6;
sbit wela=P2^7;
unsigned char j,k,adval;

void delay(unsigned char i)		//��ʱ����
{
  for(j=i;j>0;j--)
    for(k=125;k>0;k--);
}


void main()		//	������
{

    while(1)
  {
    wela=1;
    P0=0;                       //ѡͨADCS
    adwr=0;						//ADд��
    _nop_();
    adwr=1;
    P0=0xff;                    //�ر�ADCS
    delay(10);
    wela=0;                     //�ر���ADƬѡ�ź���������������Է�ֹ�ڲ��������ʱʹAD��Ƭѡ�����仯
    delay(1);				  //500
	        				//��Ҫע�����ADC0804��д�Ͷ�֮���ʱ����Ҫ�㹻�������޷���������
     wela=1;                   //���´���ADƬѡ�ź��������������
     P0=0;                       //ѡͨADCS
     P1=0xff;                    //��ȡP1��֮ǰ�ȸ���дȫ1
     adrd=0;                     //AD��ʹ��
     adval=P1;			//AD���ݶ�ȡ����P1��
     adrd=1;
     P0=0xff;
	                      
     adwr=0;			   //�ر�ADCS
     diola=1;			   //��LED
	 P1=adval;             //ͬʱ��AD��ֵ�Ͱ˸����������ʾ
   }
}
