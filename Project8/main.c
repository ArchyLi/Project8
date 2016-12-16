#include "contact3.h"
//使用说明函数
void usage()
{
	printf("使用说明: 请输入正确的数字[0-7]!\n");
}



static void myDelete(contact_p c)
{
	char name[32];
	printf("请输入你要删除的名字: ");
	scanf("%s", name);
	delContact(c, name);
}

void Test()
{
	contact_p myContact = NULL;
	initContact(&myContact);
	volatile int done = 0;
	int s = -1;
	while (!done) {
		s = -1;
		print_menu();
		printf("请输入<0~7>: ");
		scanf("%d", &s);
		switch (s) 
		{
		case 0:
			printf("bye~\n");
			done = 1;
			break;
		case 1:
			myAdd(myContact);
			break;
		case 2:
			myDelete(myContact);
			break;
		case 3:
			//Modify();
			break;
		case 4:
			//mySearch();
			break;
		case 5:
			showContact(myContact);
			break;
		case 6:
			clearContact(myContact);
			break;
		case 7:
			//mySort();
			break;
		default:
			usage();
			break;
		}
	}
	destroyContact(myContact);
}
int main()
{
	Test();
	system("pause");
	return 0;
}
