#include <reg51.h>		//头文件
sbit p1_0=P1^0;			//定义变量p1_0
main()					//主函数
{	void delay(int x);	//函数声明
	int time=1000;		//延时参数
	while(1) 			//无限循环
	{	p1_0=!p1_0;		//p1_0交替取反
		delay(time);	//调用延时函数
	}
}
void delay(int x)		//延时函数定义
{	int i;				//定义变量i
	for(i=1;i<=x;x++);	//空循环
}