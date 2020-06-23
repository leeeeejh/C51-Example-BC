#include <reg51.h>

#define CHECK_KEY_DOWN 	0	   //���ڼ�ⰴ��ѹ�½׶α�־
#define CHECK_KEY_UP   	1	   //���ڼ�ⰴ��̧��׶α�־
#define KEY_UP			0	   //����̧���־
#define KEY_DOWN		1	   //����ѹ�±�־

sbit _p32 = P3^2;


char _key_status = CHECK_KEY_DOWN; //�������״̬����ֵΪ���ѹ�½׶Σ�
char _key_idx = 0;				   //�������

void serial(char byte);

char _check_key(unsigned char _key_idx) { //��鰴��״̬
	serial(~(0x01<<_key_idx));	  //�����鰴������ת����ɨ��������
	if (_p32 == 0) {					  //����P32״̬��������ֵ
		return KEY_DOWN;
	} else {
		return KEY_UP;
	}
}

char get_key(void) {							
	char result = -1;							//�޼�����ʱ��ֵΪ-1
	if (_key_status == CHECK_KEY_DOWN) {		//�����ǰ���ڼ��ѹ�½׶Σ��������²���
		if (_check_key(_key_idx) == KEY_DOWN) {	//�жϵ�ǰɨ�����״̬����Ϊѹ�±�־��
			_key_status = CHECK_KEY_UP;			//�����׶α�־����Ϊ̧��
		} else {								//���򣬽����׶α�־����Ϊѹ��
			if (++_key_idx == 4) {				//�ж��Ƿ�4�������Ѿ�����ɨ��һ��
				_key_idx = 0;					//�ǣ��򽫴�ɨ�谴������Ϊ0
			}
		}
	} else if (_key_status == CHECK_KEY_UP) {	//�����ǰ���ڼ��̧��׶Σ��������²���
		if (_check_key(_key_idx) == KEY_UP) {	//�жϵ�ǰɨ�����״̬����Ϊ̧���־��
			result = _key_idx;					//��ֵ���
			_key_status = CHECK_KEY_DOWN;		//�������׶α�־��Ϊѹ��
			if (++_key_idx == 4) {				//�ж��Ƿ�4�������Ѿ�����ɨ��һ��
				_key_idx = 0;					//�ǣ��򽫴�ɨ�谴������Ϊ0
			}
		}
	}
	return result;
}