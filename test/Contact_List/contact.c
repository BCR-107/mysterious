#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


void LoadContact(Contact *head)//加载文件中的数据到链表
{
	
	FILE* pfRead = fopen("contact.dat", "rb");//打开文件
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	//读取文件放到通讯录中
	Contact * cur= (Contact *)malloc(sizeof(Contact));//申请一个空间保存文件中的数据
	cur ->next = NULL;
	while ((fread((void *)&cur ->data, sizeof(PeoInfo), 1, pfRead))>0)
	{
		cur ->next = head ->next;
		head ->next = cur;
		cur = (Contact *)malloc(sizeof(Contact));//申请空间为下次读取准备
	}
	free(cur);//释放多申请的空间

	fclose(pfRead);
	pfRead = NULL;

}
void AddContact(Contact *head)//增加数据
{
	Contact *rear = head;
	while (rear->next != NULL)//寻找上次数据末尾
	{
		rear = rear ->next;
	}
	Contact *newnode = (Contact *)malloc(sizeof(Contact));
	newnode->next = NULL;
	printf("请输入名字:>");
	scanf("%s", newnode ->data.name);
	printf("请输入年龄:>");
	scanf("%d", &(newnode ->data.age));
	printf("请输入性别:>");
	scanf("%s", newnode ->data.sex);
	printf("请输入电话:>");
	scanf("%s", newnode ->data.tele);
	printf("请输入地址:>");
	scanf("%s", newnode ->data.addr);

	rear ->next = newnode;
	printf("增加成功\n");

}
void ShowContact(Contact *head)//展示现有数据
{	
	Contact *p = head ->next;
	if (p == NULL)
	{
		printf("不存在联系人\n");
		return;
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		while (p != NULL)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				p ->data.name,
				p ->data.age,
				p ->data.sex,
				p ->data.tele,
				p ->data.addr);
			p = p ->next;
		}
	}
	
}
void DelContact(struct Contact* head)//删除数据
{
	char name[MAX_NAME];	
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	Contact* p1 = head;
	Contact* p2 = head->next;
	while (p2 != NULL)
	{		
		if (0 == strcmp(p2->data.name, name))
		{
			p1->next = p2->next;
			free(p2);
			printf("删除成功\n");
			return;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	printf("不存在要删除的人\n");

}
void SearchContact(const Contact* head)//查找
{
	char name[MAX_NAME];
	printf("请输入查找人的名字:>");
	scanf("%s", name);
	Contact* p = head->next;
	while (p != NULL)
	{
		if (0 == strcmp(p ->data.name, name))
		{
			printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				p->data.name,
				p->data.age,
				p->data.sex,
				p->data.tele,
				p->data.addr);
			return;
		}
		p = p->next;
	}
	printf("查找人不存在\n");

}
void ModifyContact(Contact* head)//修改数据
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	Contact* p = head->next;
	while (p != NULL)
	{
		if (0 == strcmp(p->data.name, name))
		{
			printf("请输入名字:>");
			scanf("%s", p ->data.name);
			printf("请输入年龄:>");
			scanf("%d", &(p ->data.age));
			printf("请输入性别:>");
			scanf("%s", p ->data.sex);
			printf("请输入电话:>");
			scanf("%s", p ->data.tele);
			printf("请输入地址:>");
			scanf("%s", p ->data.addr);

			printf("修改完成\n");
			return;
		}
		p = p->next;
	}
	printf("要修改的人不存在\n");

}
//void DestroyContact(Contact* head)//销毁
//{
//	Contact* p = head->next;;
//	while (head->next != NULL)
//	{
//		head->next = p->next;
//		free(p);
//	}
//}
void SaveContact(Contact* head)//保存
{
	Contact* p = head->next;
	FILE* pfWrite = fopen("contact.dat", "wb");//打开文件
	if (pfWrite == NULL)
	{
		printf("SaveContact::%s", strerror(errno));
		return;
	}
	//写通讯录中的数据到文件中
	while (p != NULL)
	{
		fwrite((void *)&p ->data, sizeof(PeoInfo), 1, pfWrite);
		p = p ->next;
	}
	printf("保存成功\n");
	
	fclose(pfWrite);
	pfWrite = NULL;
}