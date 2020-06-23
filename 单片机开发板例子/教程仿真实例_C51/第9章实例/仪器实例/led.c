#include <reg51.h>
char code map1[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//'0'~'9'
char code map2[] = {0x00, 0x76, 0x38};//' ', 'H', 'L'

char _convert(char c) {
	if (c == ' ') 
		return map2[0];
	else if (c == 'H')
		return map2[1];
	else if (c == 'L') 
		return map2[2];
	else if (c >= '0' && c <= '9')
	    return map1[c - '0'];
	return 0;
}

void _delay() {
 	int i = 0, j = 0;
	for (i = 0 ; i < 10 ; i++) {
		for (j = 0 ; j < 10 ;j++) {
		}
	}
}

void print(char name, unsigned int value) {	 //��̬��ʾ���� 
	char buf[4]={"   "};
	char i,pos=0xf7;	
	 
	for (i = 3 ; i > 0 ; i--) {
		buf[i] = '0' + value % 10;	 //����ֵ�ֽ�滺����
		value /= 10;				
		if (value == 0) {
		 	break;
		}
	}
	buf[0] = name;					//���������뻺����
   	for (i = 0 ;i < 4 ;i++) {
    	P2 = P2 | 0x0f;	        	//�ض�ȫ�������
		P2 = P2 & pos;				//ѭ��ѡͨ�����
		P0 = _convert(buf[3-i]);	//�����ʾ��
 		pos = (pos >> 1)|0x80;    	//���µ�ͨλ��
		delay(); 
	} 
}
