#include <reg51.h>
unsigned char xdata *PORT; //����˿�ָ�����
void main(){
    unsigned char tmp;
	*PORT=0xff;				//�������ú���
    while(1){
		tmp = *PORT; 		//��74244�˿ڶ�ȡ����
		if(tmp!=0xff)*PORT=tmp;//���м���������ֵ��74273
    }                       
}
