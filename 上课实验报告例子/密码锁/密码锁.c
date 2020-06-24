/*
proj:��λ���޸�����������
author:mrskye
website:https://www.mrskye.cn/
encoding:gbk
*/
#include<reg52.h>

sbit DULA = P3^0;
sbit WELA = P3^1;

//7led��ʾ������
unsigned char wordlist[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
//led��λ
unsigned char ledlist[] = {0xfe,0xfd};
//����ʽ���̼�ֵ
unsigned char key_buf[] = {0xee, 0xde, 0xbe, 0x7e,0xed, 0xdd, 0xbd, 0x7d,0xeb, 0xdb, 0xbb, 0x7b,0xe7, 0xd7, 0xb7, 0x77};
//��ʾ�ַ��б�
unsigned char display_list[] = {0x00,0x00};
//��״̬(Ĭ����)
unsigned char lock = 1;
//����(��ʼ����08)
unsigned char c[] = {0x3f,0x7f};
//��ʼ��key
unsigned char key = 0;
//��ʼ��led��ʾλ
unsigned char led_set = 0;

void delay(unsigned int i)
{
    unsigned int m,n;
    for(m=i;m>0;m--)
		for(n=90;n>0;n--);
}

unsigned char getKey() 
{	unsigned char key_scan[] = {0xef, 0xdf, 0xbf, 0x7f};	   //��ɨ����
	unsigned char i = 0, j = 0;
	for (i = 0; i < 4 ; i++) 
	{	P2 = key_scan[i];  						   //P2�ͳ���ɨ����
		if ((P2 & 0x0f) != 0x0f) 				   //�ж����޼��պ�
		{	
            delay(100);//����
            if ((P2 & 0x0f) != 0x0f)
            {
                for (j = 0 ; j < 16 ;j++) //��Ч������ر������ұպϼ�����
			    {	
                    if (key_buf[j]==P2)
                    {
                        while ((P2 & 0x0f) != 0x0f);//�ɿ�����
                        return j;
                    } 
			    }	
            }
		}
	}
    return -1;//�޼��պ�								   
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

void fini(unsigned char word)
{
    unsigned char i;
    for(i=0;i<2;i++)//2��Ӧled��ʾλ��
    {
        *(display_list+i)=word;
    }
}

void setDisplayList(unsigned char key)
{
    if(key!=-1)
    {
        *(display_list+led_set)=wordlist[key];
        ++led_set;
    }
}

void main(void) {
    fini(0x40);//��ʼ��led
    while (1)
    {  
        key = getKey();//��ȡ��ֵ
        setDisplayList(key);//�趨��ʾ�б�
        display(display_list,10);//����led��ʾ
        if (led_set==2)//������λ����
        {
            if(lock)
            //��������
            {
                if(display_list[0]==c[0] && display_list[1]==c[1])
                {
                    lock=0;
                    fini(0x73);
                    display(display_list,10);//����led��ʾ
                }
            }
            led_set=0;//��λ��ʼ��
        }
        //�޸����벿��
        if(!lock)
        {
            do
            {
                display(display_list,10);//����led��ʾ
            }while(getKey()!=15);
            fini(0x40);//��ʼ��led
            while(led_set<2)
            {
                if((key = getKey())!=-1)//��ȡ��ֵ
                {
                    setDisplayList(key);//�趨��ʾ�б�
                }
                display(display_list,10);//����led��ʾ
            }
            do
            {
                display(display_list,10);//����led��ʾ
            }while (getKey()!=14);//�ȴ�����ȷ��
            c[0]=display_list[0];//�޸�����
            c[1]=display_list[1];
            lock=1;//����
            fini(0x40);//��ʼ��led
        }
    }
}