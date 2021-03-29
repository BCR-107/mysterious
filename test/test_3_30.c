#define _CRT_SECURE_NO_WARNINGS 1

//Ë³ÐòÕ»
//#define MAXSIZE 1024
//typedef int DataType;
//typedef struct SeqStack
//{
//	DataType data[MAXSIZE];
//	int top;
//}SeqStack;
//SeqStack* initSeqStack()
//{
//	SeqStack* s=(SeqStack*)malloc(sizeof(SeqStack));
//	s->top = -1;
//	return s;
//}
//void push(SeqStack* s)
//{
//	if (s->top == MAXSIZE - 1)
//	{
//		printf("overflow");
//		return;
//	}
//	int n = 0;
//	scanf("%d", &n);
//	while (n > 0)
//	{
//		s->top++;
//		scanf("%d", &s->data[s->top]);
//		n--;
//	}
//}
//void pop(SeqStack* s)
//{
//	if (s->top == -1)
//	{
//		printf("empty stack");
//		return;
//	}
//	while (s->top != -1)
//	{
//		printf("%d ", s->data[s->top]);
//		s->top--;
//	}
//}
//int main()
//{
//	SeqStack*s = initSeqStack();
//	push(s);
//	pop(s);
//	return 0;
//}

//Á´Õ»(Ðè¸Ä½ø)
//typedef int DataType;
//typedef struct Node
//{
//	DataType data;
//	struct Node* next;
//}LinkStack;
//LinkStack* PushLinkStack(LinkStack* top)
//{
//	int n = 0; 
//	scanf("%d", &n);
//	while (n > 0)
//	{
//		LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
//		scanf("%d", &s->data);
//		s->next = top;
//		top = s;
//		n--;
//	}
//	return top;
//}
//void popLinkStack(LinkStack* top)
//{
//	if (top == NULL)
//	{
//		printf("empty LinkStack");
//		return;
//	}
//	LinkStack* p = top;
//	while (top != NULL)
//	{
//		printf("%d ", top->data);
//		top = top->next;
//		free(p);
//		p = top;
//	}
//	if (top == NULL)
//	{
//		printf("success free");
//		return;
//	}
//}
//int main()
//{
//	LinkStack* top = NULL;
//
//  top = PushLinkStack(top);
//	popLinkStack(top);
//
//	return 0;
//}