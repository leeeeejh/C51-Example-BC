#include <reg52.h>
typedef unsigned char uchar;
sbit en = P3 ^ 4;
sbit rs = P3 ^ 5;
uchar code table1[] =
{
    "SMC1602 0x01..."
};
uchar code table2[] =
{
    "      Hugh Dong."
};
void Delay(uchar m)
{
    uchar i, j;
    for (i = m; i > 0; --i)
        for (j = 110; j > 0; --j);
}
/* д���� */
void write_date(uchar date)
{
    //�ο�д����ʱ��ͼ
    rs = 1; //RS�ߵ�ƽ,д����
    P2 = date; //д������,��Ӧʱ��ͼt_SP2���ݽ���
    Delay(5);
    en = 1; //��ʹ��,��Eһ��������,��ʼд������
    Delay(5);
    en = 0; //�ر�ʹ��,д���������
}
/* дָ�� */
void write_com(uchar com)
{
    //����ԭ��ͬд����
    rs = 0; //RS�͵�ƽ,дָ��
    P2 = com;
    Delay(5);
    en = 1;
    Delay(5);
    en = 0;
}
/* ��ʼ��LCD */
void Init()
{
    en = 1;
    write_com(0x38); //00111000 ����16*2��ʾ,5*7����,8λ���ݽӿ�
    write_com(0x0E); //00001110 ����ʾ,��ʾ���,����˸
    write_com(0x06); //00000110 ��д�ַ����ַָ��+1,���+1,��Ļ���ƶ�
    write_com(0x01); //����
    write_com(0x80 + 0x01); //�������ݵ�ַָ��ӵ�һ����ʼ
}
int main()
{
    /* ��ʼ��LCD */
    Init();
    Delay(100);
    /* ��ʼ���ж� */
    EA = 1;
    EX0 = 1;
    EX1 = 1;
    /* ��ѭ�� */
    while(1);
}
void Display()interrupt 0 using 1
{
    uchar i;
    for (i = 0; i < 16; ++i) //�������д���һ������
    {
        write_date(table1[i]);
        Delay(20);
    }
    write_com(0x02); //����
    write_com(0x80 + 0x40); //���ݵ�ַָ��ָ��ڶ���
    for(i = 0; i < 16; ++i) //�������д��ڶ�������
    {
        write_date(table2[i]);
        Delay(20);
    }
}
void Clear() interrupt 1 using 1
{
    write_com(0x01);
}