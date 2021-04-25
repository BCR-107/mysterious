#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

//计算器
typedef struct
{
	double data[MAX];
	int top1;
}Stack1;//数字栈
typedef struct
{
	char data[MAX];
	int top2;
}Stack2;//字符栈
void Push1(Stack1* s1,const double d)//入栈数字
{
	s1->top1++;
	s1->data[s1->top1] = d;
}
void Push2(Stack2* s2,const char c)//入栈字符
{
	s2->top2++;
	s2->data[s2->top2] = c;
}
int Islarger(const char p)//比较操作符优先级
{
	if (p == '*' || p == '/')
		return 2;
	else if (p == '+' || p == '-')
		return 1;
	else
		return 3;
}
double Pow(double X, double Y)//求平方 - (还可优化) - pow
{
	if (Y == 0){
		return 1.0;
	}
	if (Y < 0){
		return 1.0 / Pow(X, -Y);
	}
	return X * Pow(X, Y - 1);
}
double Atof(char * Str)//把数字字符转成浮点型数字 - atof
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
void Calculation(double *tmp1, const double tmp2, const char C)//计算数值
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
	s1->top1 = -1;//数字
	Stack2*s2 = (Stack2*)malloc(sizeof(Stack2));
	s2->top2 = -1;//字符

	char arr0[MAX] = { 0 };
	char*p = arr0;
	gets(arr0);
	while (*p != '\0'){
		char* q = p;
		if (*p >= '0' && *p <= '9'){
			//是数字，取出完整数值并压栈
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
			//栈空或者为'('压栈
			Push2(s2, *p);
			p++;
		}
		else if (*p == ')'){
			//出栈到最近的'('
			while (s2->data[s2->top2] != '(' && s1->top1 >= 0) {
				//未到'('，且数字栈有2个及以上操作数，出栈两个操作数与一个操作符，并把计算结果压栈
				Calculation(&s1->data[s1->top1 - 1], s1->data[s1->top1], s2->data[s2->top2]);
				s1->top1--, s2->top2--;
			}
			p++;
			s2->top2--;//出栈'('
		}
		else if ((Islarger(*p) > Islarger(s2->data[s2->top2]) || s2->data[s2->top2] == '(') ){
			//当前符号优先级大于栈顶，或栈顶为'('，压栈
			Push2(s2, *p);
			p++;
		}
		else if ((Islarger(*p) <= Islarger(s2->data[s2->top2])) ){
			//当前符号优先级小于等于栈顶
			while ((Islarger(*p) <= Islarger(s2->data[s2->top2])) && s2->top2 != -1 && s2->data[s2->top2] != '('){
				//出栈两个操作数与一个操作符，并把计算结果压栈
				Calculation(&s1->data[s1->top1 - 1], s1->data[s1->top1], s2->data[s2->top2]);
				s1->top1--, s2->top2--;
			}
			//压栈当前操作符
			Push2(s2, *p);
			p++;
		}
	}
	while (s2->top2 != -1){
		//字符栈未空计算剩余表达式
		Calculation(&s1->data[s1->top1 - 1], s1->data[s1->top1], s2->data[s2->top2]);
		s1->top1--, s2->top2--;
	}
	printf("%lf\n", s1->data[s1->top1]);
}
int main()
{
	Calculator();//计算器

	return 0;
}
