/*********************************************************/
/*                    ʵ��4                             */
/*********************************************************/
int value,key=1;//����value��key
main(void)			//������
{
next:switch(key) 
	{	case 1:value=11;break;
		case 2:value=35;break;
		case 3:value=72;break;
		default:goto end;
	} 
	key++;
	goto next; 
end:key=0;		//��������
}