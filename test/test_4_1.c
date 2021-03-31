#define _CRT_SECURE_NO_WARNINGS 1

//#define MAXSIXE 1024
//typedef int DataType;
//typedef struct SeQueue
//{
//	DataType data[MAXSIXE];//成员空间
//	int rear, front;       //队尾队头指针
//}SeQueue;
//void enSeQueue(SeQueue* sq)//入队
//{
//	if ((sq->rear + 1) % MAXSIXE == sq->front)
//	{
//		printf("队满\n");
//		return;
//	}
//	sq->rear = (sq->rear + 1) % MAXSIXE;
//	scanf("%d", &sq->data[sq->rear]);
//
//}
//void deSeQueue(SeQueue* sq)//出队
//{
//	while (sq->rear != sq->front)
//	{
//		sq->front = (sq->front + 1) % MAXSIXE;
//		printf("%d ", sq->data[sq->front]);
//	}
//	if (sq->rear == sq->front)
//	{
//		printf("队列为空\n");
//	}
//}
//void test0(SeQueue* sq)
//{
//	enSeQueue(sq);//入队
//	enSeQueue(sq);//入队
//	enSeQueue(sq);//入队
//	enSeQueue(sq);//入队
//
//}
//int main()
//{
//	SeQueue* sq = (SeQueue*)malloc(sizeof(SeQueue));
//	sq->rear = sq->front = MAXSIXE - 1;
//
//	test0(sq);//入队
//	deSeQueue(sq);//出队
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
//LQNode* deLQueue(LQNode* r)//出队
//{
//	if (r->next == r)
//	{
//		printf("队空\n");
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
//		printf("队列空\n");
//		return r;
//	}
//	return r;
//}
//LQNode* test0(LQNode* r)
//{
//	r = enLQueue(r);//入队
//	r = enLQueue(r);//入队
//	r = enLQueue(r);//入队
//	r = enLQueue(r);//入队
//	return r;
//}
//void test1(LQNode* r)
//{
//	r = deLQueue(r);//出队
//	r = deLQueue(r);//出队
//	r = deLQueue(r);//出队
//	r = deLQueue(r);//出队
//
//}
//int main()
//{
//	LQNode* r = (LQNode*)malloc(sizeof(LQNode));
//	r->next = r;
//
//	r = test0(r);//入队
//	test1(r);
//	//deLQueue(r);//出队
//
//	return 0;
//}

