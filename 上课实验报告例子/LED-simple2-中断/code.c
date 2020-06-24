/*
encoding:utf-8
name:led-simple2
function:
1.�ϵ縴λ��ȫ��LED������
2.������S2������󣬰�D1-D7��˳�����δ��ϵ��µ���LED��
3.������S3������󣬰�D7-D1��˳�����δ��µ��ϵ���LED��
4.������S4�������ȫ����Ϩ���ٴε�����S4�������ȫ���Ƶ�����
author : https://www.mrskye.cn
*/
#include<reg51.h>
#include<intrins.h>

sbit LE=P2^5;
unsigned char n;    //ȫ��ѭ������
unsigned char flag = 0; //������־λ

void delay(unsigned int i)  //�ӳٺ���
{
    unsigned int j;
    unsigned char k;
    for(j=i;j>0;j--)
    {
        for(k=125;k>0;k--);
    }
}

void service_int0(void) interrupt 0
{
    flag = 1;
}

void main()
{
    //�жϷ����ʼ��
    IE = 0x81;   //�����жϷ���
    TCON = 0x1; //�����жϴ�����ʽ
    P1=0xff;   //��λ�ر�ȫ��LED
    while(1)
    {
        if(flag)
        {
            switch (P2&0xf)
            {
                case 0xe:  //S2
                {
                    P1=0xfe;    //D0
                    delay(2500);    //D0��ʱ��
                    for(n=0;n<7;n++)    //ѭ��8-1��
                    {
                        P1=_crol_(P1,1);//ѭ������
                        delay(2500);
                    }                    
                    P1=0xff;   //��λ�ر�ȫ��LED
                    break;
                }
                case 0xd:  //S3
                {
                    P1=0x7f;    //D7
                    delay(2500);    //D7��ʱ��
                    for(n=0;n<7;n++)    //ѭ��8-1��
                    {
                        P1=_cror_(P1,1);//ѭ������
                        delay(2500);
                    }
                    P1=0xff;   //��λ�ر�ȫ��LED
                    break;
                }
                case 0xb:  //S4
                {
                    P1=~P1; //ȡ��
                    break;
                }
                /*
                case 0x7:  //S5
                {
                    while(P2&0xf==0x7f); //�жϰ���״̬
                    for(P1=0x0;;P1--)
                    {
                        if(P2==0x7f)break;  //�ٴΰ����˳������
                        delay(1000);
                    }
                    break;
                }
                */
                default: break;
            }
            flag = 0;
        }        
    }
}