#include <reg51.H>
#define E2PROM_ADDR 0x12			//����EPROM��ַ
sbit P3_7=P3^7;						//����������˿�
unsigned char count =0;				//���������
unsigned char code table[]=	{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
//����e2prom�Ķ�д����
void read_e2prom(unsigned char rom_addr, unsigned char ram_addr, unsigned char size);
void write_e2prom(unsigned char rom_addr, unsigned char ram_addr, unsigned char size);

void main(void)	{
	//��EPROM�ж�ȡ��������ֵ
	read_e2prom(E2PROM_ADDR, (unsigned char)&count, 1); 
	P0=table[count/10];				//��ʾcount��ʮλ
	P2=table[count%10];				//��ʾcount�ĸ�λ
  	while(1) {             		 
      	if(P3_7==0){      			//��ⰴ���Ƿ�ѹ��   
			count++;          		//��������1
			if(count==100) count=0; //�ж�ѭ���Ƿ���
			P0=table[count/10];		//ʮλ�����ʾ
			P2=table[count%10];		//��λ�����ʾ
			//����ǰ����ֵ����EPROM
			write_e2prom(E2PROM_ADDR,(unsigned char)&count,1); 
			while(P3_7==0);    		//�ȴ�����̧�𣬷�ֹ��������
	   }
    }
}

