//�ɹ۲쵽���������������������״̬֮����˸��
//����ʾ�����۲�IOUT���ŵ�ƽ���ɿ����������Ρ�
#include <reg52.h>
sbit wela=P2^7;
sbit dula=P2^6;
sbit dawr=P3^6;
sbit csda=P3^2;
unsigned int j,k;
void delay(unsigned int i)
{
  for(j=i;j>0;j--)
    for(k=125;k>0;k--);
}

void main()
{
  wela=0;
  dula=0;

  csda=0;
  dawr=0;
  while(1)
  {
	  P0=0xff;
	  delay(500);
	  P0=0x00;
	  delay(500);
  }
}
