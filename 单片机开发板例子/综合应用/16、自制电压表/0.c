/****************************************************************************

*****************************************************************************
�����ܣ�	����һ����Ϊ5V�ĵ�ѹ������ʾ��������ϡ�
			����ѹ���������λ��ADC��DACоƬ֮��Ļ���������֮��ĵ�ѹ��š��
			���������������Է����������ʾ�ĵ�ѹֵ�仯��
****************************************************************************/
#include<reg51.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit adrd=P3^7;                          //IO�ڶ���
sbit adwr=P3^6;
sbit diola=P2^5;
sbit dula=P2^6;
sbit wela=P2^7;
unsigned char j,k,adval,zheng,xiao1,xiao2,xiao3;
unsigned int value0;
float value;
void delay(unsigned char i)		//��ʱ����
{
  for(j=i;j>0;j--)
    for(k=125;k>0;k--);
}

uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,				//����ܱ���
                        0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void display(uchar bai_c,uchar sh_c,uchar g_c)			//��ʾ����
{  
   P0=table[bai_c]|0x80;		//��ʾ��λ
   dula=1;
   dula=0;

   P0=0xfe;
   wela=1;
   wela=0;
   delay(5);

   dula=0;
   P0=table[sh_c];		//��ʾʮλ
   dula=1;
   dula=0;

   wela=0;
   P0=0xfd;
   wela=1;
   wela=0;
   delay(5);

   P0=table[g_c];		//��ʾ��λ
   dula=1;
   dula=0;

   P0=0xfb;
   wela=1;
   wela=0;
   delay(5);
}

void main()		//	������
{
	uchar a;
    while(1)
  {
    wela=1;
    P0=0;                       //ѡͨADCS
    adwr=0;			//ADд�루���д��ʲô���У���Ҫ��Ϊ������ADת����
    _nop_();
    adwr=1;
    P0=0xff;                    //�ر�ADCS
    delay(10);
    wela=0;                     //�ر���ADƬѡ�ź���������������Է�ֹ�ڲ��������ʱʹAD��Ƭѡ�����仯

     wela=1;                   //���´���ADƬѡ�ź��������������
     P1=0xff;                    //��ȡP1��֮ǰ�ȸ���дȫ1
     P0=0;                       //ѡͨADCS
     adrd=0;                     //AD��ʹ��
     adval=P1;			//AD���ݶ�ȡ����P1��
     adrd=1;
    P0=0xff;                     //�ر�ADCS
     adwr=0;
     P1=adval;                    //ͬʱ��AD��ֵ�Ͱ˸����������ʾ
	value=adval*5.0/255.0;		  //ת����

	value0=(unsigned int)(value*1000);//ǿ������ת��������ȡ����λ��ֵ��
	zheng=value0/1000;
	xiao1=value0/100%10;
	xiao2=value0/10%10;
	xiao3=value0%10;   //��������Ĵ���
	if(xiao3>=5)
		xiao2++;
	
	 for(a=20;a>0;a--)        //��Ҫע�����ADC0804��д�Ͷ�֮���ʱ����Ҫ�㹻�������޷���������
    {                           //�������ʾ���ַ������ԭ��Ҳ��Ϊ������д��֮���ʱ����                                                                                                                                                                                                                           
    	display(zheng,xiao1,xiao2);
     }	//��ȥ��ʾ��λ��
   }
}
