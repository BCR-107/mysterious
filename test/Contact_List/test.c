#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
#define _CRT_SECURE_NO_WARNINGS 1

void menu()//�˵�
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
	//������ͷ
	Contact *head = (Contact*)malloc(sizeof(Contact));
	head -> next = NULL;
	//�����������ļ��е���Ϣ���ص�������
	LoadContact(head);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
			case ADD://������ϵ��
				AddContact(head);
				break;
			case DEL://ɾ����ϵ��
				DelContact(head);
				break;
			case SEARCH://������ϵ��
				SearchContact(head);
				break;
			case MODIFY://�޸���ϵ��
				ModifyContact(head);
				break;
			case SHOW://չʾ������ϵ��
				ShowContact(head);
				break;
			case SORT:
				break;
			case EXIT://�˳�������	
				SaveContact(head);
				//�ͷŶ�̬���ٵ��ڴ�
				//DestroyContact(head);
				break;
			case SAVE://��������
				SaveContact(head);
				break;
			default:
				printf("ѡ�����\n");
				break;
		}
	} while (input);
	return 0;
}