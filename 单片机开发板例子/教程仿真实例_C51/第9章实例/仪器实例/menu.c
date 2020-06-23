#define MENU_ON		0
#define MENU_OFF	1
#define MENU_NUM	2
#define MENU_MAX	240
#define MENU_MIN	10

unsigned char param_value[] = {100, 150};
unsigned char menu_status = MENU_OFF;
char _menu_name[] = {'L','H'};	 		 //�������ķ���
unsigned char _menu_value[] = {0,0};			 	 //����ʾ�õĲ�������
unsigned char _menu_idx = 0;			 //�������

char get_key();
void print(char name, unsigned int value);

void menu_thread(void) {
	char i = 0;
	char key = get_key();		         
	if (menu_status == MENU_OFF) {		 
		//��ǰ�˵�Ϊ�ر�״̬ʱ
		if (key == 0) {					 //������0�ѱ�����
			menu_status = MENU_ON;		 //�õ�ǰ�˵�Ϊ��״̬
			_menu_idx = 0;				 //���ò������0
			//�����в�����ǰֵȡ�������빩��ʾ�Ĳ���������
			for (i = 0 ; i < MENU_NUM ; i++) {	  
				_menu_value[i] = param_value[i];	
			}
		}
	} else {							 
		//�����ǰ�˵�Ϊ��״̬����������²�����
		if (key == 0) { 
			//������0���£��򲻱����ֵ�����л�����һ������
			if (++_menu_idx == MENU_NUM) {	  //�ж��Ƿ����в�����ѭ������
				menu_status = MENU_OFF;	  //����ѭ����ɣ����ò˵��ر�״̬
			}
		} else if (key == 1) { 
			//������1���£��򱣴��ֵ�����л�����һ������
			param_value[_menu_idx] = _menu_value[_menu_idx];
			if (++_menu_idx == MENU_NUM) {
				menu_status = MENU_OFF;
			}
		} else if (key == 2) { 
			//������2���£������ֵ��10
			_menu_value[_menu_idx] += 10;
			if (_menu_value[_menu_idx] >= MENU_MAX) {
				_menu_value[_menu_idx] = MENU_MAX;
			}
			
		} else if (key == 3) { 
			//������3���£������ֵ��10
			_menu_value[_menu_idx] -= 10;
			if (_menu_value[_menu_idx] <= MENU_MIN) {
				_menu_value[_menu_idx] = MENU_MIN;
			}
		}
	}

	if (menu_status == MENU_ON) {
		//�˵�״̬Ϊ��ʱ,��ʾ����ֵ
		print(_menu_name[_menu_idx], _menu_value[_menu_idx]); 
	}
}