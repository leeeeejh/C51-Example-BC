#include <reg51.h>
char led_mod[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,	  //led��ģ
				  0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71};	  
char key_buf[] = {0xee, 0xde, 0xbe, 0x7e,0xed, 0xdd, 0xbd, 0x7d,//��ֵ
				  0xeb, 0xdb, 0xbb, 0x7b,0xe7, 0xd7, 0xb7, 0x77};

void getKey () interrupt 0{						   //�жϺ���
	char key_scan[] = {0xef, 0xdf, 0xbf, 0x7f};	   //��ɨ����
	char i = 0, j = 0;
	for (i = 0; i < 4 ; i++) {
		P2= key_scan[i];  			//���ɨ���� 
		for (j = 0 ; j < 16 ;j++) {
			if (key_buf[j]== P2){ //����ֵ,���жϼ���
			   P0= led_mod[j];		//��ʾ�պϼ�����
			   break;
}}}
	P2=0x0f;			 //Ϊ�´��ж���׼��
}
 
void main(void) {
   P0 = 0x00; 			 //��������
   IT0=1;				 //���崥��
   EX0=1;				 //INT0����
   EA=1;				 //���ж�����
   P2 = 0x0f;			 //Ϊ�״��ж���׼��,����ȫΪ0,����ȫΪ1
   while(1);			 //ģ������������
}





