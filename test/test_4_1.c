#define _CRT_SECURE_NO_WARNINGS 1

//#define MAXSIXE 1024
//typedef int DataType;
//typedef struct SeQueue
//{
//	DataType data[MAXSIXE];//��Ա�ռ�
//	int rear, front;       //��β��ͷָ��
//}SeQueue;
//void enSeQueue(SeQueue* sq)//���
//{
//	if ((sq->rear + 1) % MAXSIXE == sq->front)
//	{
//		printf("����\n");
//		return;
//	}
//	sq->rear = (sq->rear + 1) % MAXSIXE;
//	scanf("%d", &sq->data[sq->rear]);
//
//}
//void deSeQueue(SeQueue* sq)//����
//{
//	while (sq->rear != sq->front)
//	{
//		sq->front = (sq->front + 1) % MAXSIXE;
//		printf("%d ", sq->data[sq->front]);
//	}
//	if (sq->rear == sq->front)
//	{
//		printf("����Ϊ��\n");
//	}
//}
//void test0(SeQueue* sq)
//{
//	enSeQueue(sq);//���
//	enSeQueue(sq);//���
//	enSeQueue(sq);//���
//	enSeQueue(sq);//���
//
//}
//int main()
//{
//	SeQueue* sq = (SeQueue*)malloc(sizeof(SeQueue));
//	sq->rear = sq->front = MAXSIXE - 1;
//
//	test0(sq);//���
//	deSeQueue(sq);//����
//
//	return 0;
//}

//typedef int DataType;
//typedef struct Node
//{
//	DataType data;
//	struct Node* next;
//}LQNode;
//LQNode* enLQueue(LQNode* r)
//{
//	LQNode* p = (LQNode*)malloc(sizeof(LQNode));
//	scanf("%d", &p->data);
//	p->next = r->next;
//	r->next = p;
//	r = p;
//
//	return r;
//}
//LQNode* deLQueue(LQNode* r)//����
//{
//	if (r->next == r)
//	{
//		printf("�ӿ�\n");
//		return r;
//	}
//	LQNode* p = r->next->next;
//	printf("%d ", p->data);
//		if (p != r)
//		{
//			r->next->next = p->next;
//			free(p);
//			p = r->next->next;
//		}
//		else
//		{
//			r = r->next;
//			r->next = r;
//		}
//	if (r->next == r)
//	{
//		printf("���п�\n");
//		return r;
//	}
//	return r;
//}
//LQNode* test0(LQNode* r)
//{
//	r = enLQueue(r);//���
//	r = enLQueue(r);//���
//	r = enLQueue(r);//���
//	r = enLQueue(r);//���
//	return r;
//}
//void test1(LQNode* r)
//{
//	r = deLQueue(r);//����
//	r = deLQueue(r);//����
//	r = deLQueue(r);//����
//	r = deLQueue(r);//����
//
//}
//int main()
//{
//	LQNode* r = (LQNode*)malloc(sizeof(LQNode));
//	r->next = r;
//
//	r = test0(r);//���
//	test1(r);
//	//deLQueue(r);//����
//
//	return 0;
//}

