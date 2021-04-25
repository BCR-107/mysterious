#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

//������
typedef struct
{
	double data[MAX];
	int top1;
}Stack1;//����ջ
typedef struct
{
	char data[MAX];
	int top2;
}Stack2;//�ַ�ջ
void Push1(Stack1* s1,const double d)//��ջ����
{
	s1->top1++;
	s1->data[s1->top1] = d;
}
void Push2(Stack2* s2,const char c)//��ջ�ַ�
{
	s2->top2++;
	s2->data[s2->top2] = c;
}
int Islarger(const char p)//�Ƚϲ��������ȼ�
{
	if (p == '*' || p == '/')
		return 2;
	else if (p == '+' || p == '-')
		return 1;
	else
		return 3;
}
double Pow(double X, double Y)//��ƽ�� - (�����Ż�) - pow
{
	if (Y == 0){
		return 1.0;
	}
	if (Y < 0){
		return 1.0 / Pow(X, -Y);
	}
	return X * Pow(X, Y - 1);
}
double Atof(char * Str)//�������ַ�ת�ɸ��������� - atof
{
	char * p = Str;
	double Res = 0;
	int count = 0;
	while (*Str != '\0'){
		if (*Str == '.'){
			count = 1;
			p = Str;
			Str++;
			continue;
		}
		Res = Res * 10 + *Str - '0';
		Str++;
	}
	if (count){
		count = p - Str + 1;
	}
	return Res * Pow(10, count);
}
void Calculation(double *tmp1, const double tmp2, const char C)//������ֵ
{
	switch (C){
	case '+':
		*tmp1 = *tmp1 + tmp2;
		break;
	case '-':
		*tmp1 = *tmp1 - tmp2;
		break;
	case '*':
		*tmp1 = *tmp1 * tmp2;
		break;
	case '/':
		*tmp1 = *tmp1 / tmp2;
		break;
	}
}
void Calculator()
{
	Stack1*s1 = (Stack1*)malloc(sizeof(Stack1));
	s1->top1 = -1;//����
	Stack2*s2 = (Stack2*)malloc(sizeof(Stack2));
	s2->top2 = -1;//�ַ�

	char arr0[MAX] = { 0 };
	char*p = arr0;
	gets(arr0);
	while (*p != '\0'){
		char* q = p;
		if (*p >= '0' && *p <= '9'){
			//�����֣�ȡ��������ֵ��ѹջ
			while (*p >= '0' && *p <= '9' || *p == '.' && *p != '\0'){
				p++;
			}
			char tmpc = 0;
			tmpc = *p;
			*p = '\0';
			double m = Atof(q);
			Push1(s1, m);
			*p = tmpc;
		}
		else if (s2->top2 == -1 || *p == '('){
			//ջ�ջ���Ϊ'('ѹջ
			Push2(s2, *p);
			p++;
		}
		else if (*p == ')'){
			//��ջ�������'('
			while (s2->data[s2->top2] != '(' && s1->top1 >= 0) {
				//δ��'('��������ջ��2�������ϲ���������ջ������������һ�������������Ѽ�����ѹջ
				Calculation(&s1->data[s1->top1 - 1], s1->data[s1->top1], s2->data[s2->top2]);
				s1->top1--, s2->top2--;
			}
			p++;
			s2->top2--;//��ջ'('
		}
		else if ((Islarger(*p) > Islarger(s2->data[s2->top2]) || s2->data[s2->top2] == '(') ){
			//��ǰ�������ȼ�����ջ������ջ��Ϊ'('��ѹջ
			Push2(s2, *p);
			p++;
		}
		else if ((Islarger(*p) <= Islarger(s2->data[s2->top2])) ){
			//��ǰ�������ȼ�С�ڵ���ջ��
			while ((Islarger(*p) <= Islarger(s2->data[s2->top2])) && s2->top2 != -1 && s2->data[s2->top2] != '('){
				//��ջ������������һ�������������Ѽ�����ѹջ
				Calculation(&s1->data[s1->top1 - 1], s1->data[s1->top1], s2->data[s2->top2]);
				s1->top1--, s2->top2--;
			}
			//ѹջ��ǰ������
			Push2(s2, *p);
			p++;
		}
	}
	while (s2->top2 != -1){
		//�ַ�ջδ�ռ���ʣ����ʽ
		Calculation(&s1->data[s1->top1 - 1], s1->data[s1->top1], s2->data[s2->top2]);
		s1->top1--, s2->top2--;
	}
	printf("%lf\n", s1->data[s1->top1]);
}
int main()
{
	Calculator();//������

	return 0;
}
