/********************************************************************
					
*************************************************************************
�������ܣ������ڷ���һ�ֽ����ݣ���ͨ�������ն˻��ߴ��ڵ���������ʾ������
		  �����ն˲�����ѡΪ9600����
		  �����ն����úú�ÿ����һ��S2�����ɿ�������ڳ����ն�
		  ����ʾһ����ĸ"abcdefg����"��
		  ��ڲ�����d: Ҫ���͵��ֽ����ݡ�
********************************************************************/


#include <reg52.h>
#define jingzhen     11059200UL			 /*ʹ��11.0592M����*/	 
#define botelv   9600UL	     /*�����ʶ���Ϊ9600	*/
unsigned char zifuchuan[]="abcdefg	����";			//����ʾ�ַ���1234567890abcdefg	����
volatile unsigned char sending;
sbit s2=P3^4;

//sbit  s3=P3^5;				 //����
//unsigned char 	rev;

void delay(unsigned char i)
{
	unsigned char j,k;
	for(j=i;j>0;j--)
		for(k=90;k>0;k--);
}
void init(void)				//���ڳ�ʼ��
{
 EA=0; //��ʱ�ر��ж�
 TMOD&=0x0F;  //��ʱ��1ģʽ�����ڸ�4λ
 TMOD|=0x20;    //��ʱ��1������ģʽ2���Զ���װģʽ
 SCON=0x50;     //���ڹ�����ģʽ1
 TH1=256-jingzhen/(botelv*12*16);  //���㶨ʱ����װֵ
 TL1=256-jingzhen/(botelv*12*16);
 PCON|=0x80;    //���ڲ����ʼӱ�
 ES=1;         //�����ж�����
 TR1=1;        //������ʱ��1
 REN=1;        //������� 
 EA=1;         //�����ж�
}

void send(unsigned char d)		  //����һ���ֽڵ����ݣ��β�d��Ϊ���������ݡ�
{
 
 SBUF=d; //������д�뵽���ڻ���
 sending=1;	 //���÷��ͱ�־
 while(sending); //�ȴ��������
}

void sendc(unsigned char * pd)
{
 while((*pd)!='\0') //�����ַ�����ֱ������0�Ž���
 {
  send(*pd); //����һ���ַ�
  pd++;  //�ƶ�����һ���ַ�
 }
}

/*resev(rev)
{
	P1=rev;
}*/
void main()
{
	init();
	while(1)
	{
		if(s2==0)
		{
			delay(20);
			if(!s2)
			{
				while(!s2);		   
				sendc(zifuchuan);
			}
		}
/*		if(s3==0)
		{
			delay(20);
			if(!s3)
			{
				while(!s3);		   
				resev(rev);
			}
		}
 */
	}
}

void uart(void) interrupt 4		 //���ڷ����ж�
{
 if(RI)    //�յ�����
 {
  RI=0;   //���ж�����
 // 	rev=SBUF;

 }
 else      //������һ�ֽ�����
 {
  TI=0;
  sending=0;  //�����ڷ��ͱ�־
 }
}