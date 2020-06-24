#include<reg52.h>

sbit DULA = P3^0;
sbit WELA = P3^1;
sbit flag = P1^0;

unsigned char flag_int0 = 0;
unsigned char flag_time0 = 0;

//7led��ʾ������
unsigned char wordlist[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
//led��λ
unsigned char ledlist[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
//����ʽ���̼�ֵ
unsigned char key_buf[] = {0xee, 0xde, 0xbe, 0x7e,0xed, 0xdd, 0xbd, 0x7d,0xeb, 0xdb, 0xbb, 0x7b,0xe7, 0xd7, 0xb7, 0x77};
//ʱ����
unsigned char time_index[] = {0,0};
unsigned char time_list[] = {0x00,0x00};


void delay(unsigned int i)  //�ӳٺ���
{
    unsigned int j;
    unsigned char k;
    for(j=i;j>0;j--)
    {
        for(k=125;k>0;k--);
    }
}

void display(unsigned char display_list[],unsigned int time)
{
    unsigned char i;
    //for(i=0;*(display_list+i);i++)
    for(i=0;i<2;i++)//2��Ӧled��ʾλ��
    {
        //ѡ����ʾλ
        P0=*(ledlist+i);
        WELA=1;
        WELA=0;
        //����ַ���
        P0=*(display_list+i);
        DULA=1;
        DULA=0;
        delay(time);
    }
}

void service_int0(void) interrupt 0//�ⲿ�ж�0�жϷ�����
{
    flag_int0 = 1;
}

void service_time0(void) interrupt 1//��ʱ���ж�0�жϷ�����
{
    flag_time0++;
}

void main()
{
    /*�жϷ����ʼ��*/
    IE = 0x83;   //10000011|�жϷ���
    TCON = 0x11; //00010001|�жϴ�����ʽ
    TMOD = 0X1; //00000001|��ʱ��������ʽ
    TH0=0Xb0;//��ʱ��װ�س�ֵ
    TH1=0x3c;//50ms��ʱ��
    P1=0xff;   //��λ�ر�ȫ��LED
    P2=0x0f;    //���̴�����״̬
    while (1)
    {
        if(flag_int0)//��������ж�
        {
            unsigned char i = 0;
            for(i=0;i<5;i++)
            {
                unsigned char j;
                for (j = 0; j < 90; j++)
                {
                    unsigned char display_list[] = {0x79,0x3f};
                    display(display_list,10);
                }
                for (j = 0; j < 90; j++)
                {
                    unsigned char display_list[] = {0x00,0x00};
                    display(display_list,10);
                }
            }
            flag_int0 = 0;
        }
        if(flag_time0>=13)//��ʱ���жϷ���
        {
            while(!flag);
            time_index[1] = time_index[1]+1;
            if(!(time_index[1]%10))
            {
                time_index[1] = time_index[1]%10;
                time_index[0] = (time_index[0]+1)%10;
            }
            flag_time0=0;
            time_list[0] = wordlist[time_index[0]];
            time_list[1] = wordlist[time_index[1]];
        }
        display(time_list,20);
    }
    
}