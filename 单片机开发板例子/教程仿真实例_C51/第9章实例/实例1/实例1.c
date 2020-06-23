#include <REG51.H>
char map[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
sbit lcs = P1^2;	   			//1241���Ŷ���
sbit sclk = P1^1;
sbit dout = P1^0;
void print(unsigned int value);	//��ʾ����
void delay();					//��ʱ����
unsigned int ad();				//ADת������
void main() {
   unsigned int value = 0;
   while (1) {
      value  = ad();			//�õ�ADת�����
	  print(value);				//��ʾת�����
}}
unsigned int ad() {				//ADת������
	unsigned int result = 0;
	unsigned char i = 0;
	lcs = 0;			   		//����ת��ʱ��ʼADת��
	while(dout == 0);			//�ȴ�ת������
	for ( ; i < 12 ; i++) {		//��ȡת�����
		sclk = 1;
		delay();
		sclk = 0;
		result <<= 1; 		
		result |= dout;
	}
	sclk = 1;					//������13������
	delay();
	sclk = 0;
	lcs = 1;					//����ADת��
	return result;				//����ת�����
}
void print(unsigned int value) {
	char p_buf[4] = "    ";
    char i,pos=0xf7;
	for (i=0; i < 4 ; i++) {   //���ת������
		p_buf[i] = value % 10; //������ʾ����
		value /= 10;
		if (value == 0) break;
	}
	for (i = 0 ;i < 4 ;i++) {   
	   P2 = P2 | 0x0f;		   //�γɶ���
	   P2 = P2 & pos;
	   P0 = map[p_buf[i]];	   //��ʾ��������
	   pos = (pos >> 1)| 0x80; //ˢ�¶���
	   delay();
}}
void delay() {
    char i ;
	for (i = 0 ; i < 100 ; i++);
}