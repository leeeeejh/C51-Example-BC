//ʵ��2 ��������ʶ��
#include <REG51.H>	

void main() {
   char key = 0;
   while(1){
   		key = P0 & 0x0f;       	//��ȡ����״̬
		if (key != 0x0f) P2 = key;	//��ʾ��led
	}
}


   
  