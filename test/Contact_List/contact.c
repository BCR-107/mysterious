#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


void LoadContact(Contact *head)//�����ļ��е����ݵ�����
{
	
	FILE* pfRead = fopen("contact.dat", "rb");//���ļ�
	if (pfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	//��ȡ�ļ��ŵ�ͨѶ¼��
	Contact * cur= (Contact *)malloc(sizeof(Contact));//����һ���ռ䱣���ļ��е�����
	cur ->next = NULL;
	while ((fread((void *)&cur ->data, sizeof(PeoInfo), 1, pfRead))>0)
	{
		cur ->next = head ->next;
		head ->next = cur;
		cur = (Contact *)malloc(sizeof(Contact));//����ռ�Ϊ�´ζ�ȡ׼��
	}
	free(cur);//�ͷŶ�����Ŀռ�

	fclose(pfRead);
	pfRead = NULL;

}
void AddContact(Contact *head)//��������
{
	Contact *rear = head;
	while (rear->next != NULL)//Ѱ���ϴ�����ĩβ
	{
		rear = rear ->next;
	}
	Contact *newnode = (Contact *)malloc(sizeof(Contact));
	newnode->next = NULL;
	printf("����������:>");
	scanf("%s", newnode ->data.name);
	printf("����������:>");
	scanf("%d", &(newnode ->data.age));
	printf("�������Ա�:>");
	scanf("%s", newnode ->data.sex);
	printf("������绰:>");
	scanf("%s", newnode ->data.tele);
	printf("�������ַ:>");
	scanf("%s", newnode ->data.addr);

	rear ->next = newnode;
	printf("���ӳɹ�\n");

}
void ShowContact(Contact *head)//չʾ��������
{	
	Contact *p = head ->next;
	if (p == NULL)
	{
		printf("��������ϵ��\n");
		return;
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
void DelContact(struct Contact* head)//ɾ������
{
	char name[MAX_NAME];	
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	Contact* p1 = head;
	Contact* p2 = head->next;
	while (p2 != NULL)
	{		
		if (0 == strcmp(p2->data.name, name))
		{
			p1->next = p2->next;
			free(p2);
			printf("ɾ���ɹ�\n");
			return;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	printf("������Ҫɾ������\n");

}
void SearchContact(const Contact* head)//����
{
	char name[MAX_NAME];
	printf("����������˵�����:>");
	scanf("%s", name);
	Contact* p = head->next;
	while (p != NULL)
	{
		if (0 == strcmp(p ->data.name, name))
		{
			printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("�����˲�����\n");

}
void ModifyContact(Contact* head)//�޸�����
{
	char name[MAX_NAME];
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	Contact* p = head->next;
	while (p != NULL)
	{
		if (0 == strcmp(p->data.name, name))
		{
			printf("����������:>");
			scanf("%s", p ->data.name);
			printf("����������:>");
			scanf("%d", &(p ->data.age));
			printf("�������Ա�:>");
			scanf("%s", p ->data.sex);
			printf("������绰:>");
			scanf("%s", p ->data.tele);
			printf("�������ַ:>");
			scanf("%s", p ->data.addr);

			printf("�޸����\n");
			return;
		}
		p = p->next;
	}
	printf("Ҫ�޸ĵ��˲�����\n");

}
//void DestroyContact(Contact* head)//����
//{
//	Contact* p = head->next;;
//	while (head->next != NULL)
//	{
//		head->next = p->next;
//		free(p);
//	}
//}
void SaveContact(Contact* head)//����
{
	Contact* p = head->next;
	FILE* pfWrite = fopen("contact.dat", "wb");//���ļ�
	if (pfWrite == NULL)
	{
		printf("SaveContact::%s", strerror(errno));
		return;
	}
	//дͨѶ¼�е����ݵ��ļ���
	while (p != NULL)
	{
		fwrite((void *)&p ->data, sizeof(PeoInfo), 1, pfWrite);
		p = p ->next;
	}
	printf("����ɹ�\n");
	
	fclose(pfWrite);
	pfWrite = NULL;
}