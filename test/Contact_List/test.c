#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
#define _CRT_SECURE_NO_WARNINGS 1

void menu()//菜单
{
	printf("***************************************\n");
	printf("******  1. add        2. del     ******\n");
	printf("******  3. search     4. modify  ******\n");
	printf("******  5. show       6. sort    ******\n");
	printf("******  7. save       0. exit    ******\n");
	printf("***************************************\n");
}
int main()
{
	int input = 0;
	//创建表头
	Contact *head = (Contact*)malloc(sizeof(Contact));
	head -> next = NULL;
	//加载链表，把文件中的信息加载到链表中
	LoadContact(head);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
			case ADD://增加联系人
				AddContact(head);
				break;
			case DEL://删除联系人
				DelContact(head);
				break;
			case SEARCH://查找联系人
				SearchContact(head);
				break;
			case MODIFY://修改联系人
				ModifyContact(head);
				break;
			case SHOW://展示现有联系人
				ShowContact(head);
				break;
			case SORT:
				break;
			case EXIT://退出并保存	
				SaveContact(head);
				//释放动态开辟的内存
				//DestroyContact(head);
				break;
			case SAVE://保存数据
				SaveContact(head);
				break;
			default:
				printf("选择错误\n");
				break;
		}
	} while (input);
	return 0;
}