#include <reg51.H> 				//51ͷ�ļ�
sbit P3_7=P3^7;
unsigned char code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char count;
void delay(unsigned int time) 	//��ʱ
{	unsigned int j = 0;
	for(;time>0;time--)
		for(j=0;j<125;j++);
}
void main()	
{ count=0;                      //����������ֵ
  P0=table[count/10];           //P0����ʾ��ֵ
  P2=table[count%10];           //P2����ʾ��ֵ
  while(1)                     	//��������ѭ��
  {	 if(P3_7==0)              	//�������,��ⰴ���Ƿ�ѹ��           
  	 {	delay(10);      
		if(P3_7==0)          	//������ѹ��
		{	count++;          	//��������1
          	if(count==100)   	//�ж�ѭ���Ƿ���
    			count=0; 
			P0=table[count/10];	//P0�������ʾ
			P2=table[count%10];	//P2�������ʾ
			while(P3_7==0);    	//�ȴ������ɿ�����ֹ��������
   		}
	  }
   }
}






