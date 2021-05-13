#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>
typedef int DataType;
typedef struct node
{
	DataType data;//数据
	int bf;//节点平衡因子
	struct node *lchild, *rchild;//左孩子，右孩子
}BstNode;
int get_height(BstNode* T);//树高
BstNode* Update_Rotation(BstNode* T);//更新树高并旋转失衡节点
BstNode* right_Rotation(BstNode* T);//右旋
BstNode* left_Rotation(BstNode* T);//左旋

void insertNode(BstNode* T, BstNode* s)//插入节点
{
	//T - 根节点 s - 插入节点
	BstNode *q = NULL;//前驱
	BstNode *p = NULL;//当前
	p = T;
	while (p){
		q = p;
		if (p->data == s->data)
			return;
		if (s->data > p->data)
			p = p->rchild;
		else
			p = p->lchild;
	}
	if (s->data < q->data)
		q->lchild = s;
	else
		q->rchild = s;
}
BstNode* creatBst()//创建AVL
{
	BstNode* root = NULL;//根节点
	BstNode* s = NULL;//插入节点
	DataType data = 0;
	scanf("%d", &data);
	while (data != -1){
		s = (BstNode*)malloc(sizeof(BstNode));
		s->lchild = NULL;
		s->rchild = NULL;
		s->data = data;
		if (root != NULL){
			insertNode(root, s);
		}
		else{
			root = s;
		}
		root = Update_Rotation(root);//更新平衡因子，失衡就调整返回新根节点
		scanf("%d", &data);
	}
	return root;
}
void InOrder(BstNode* T)//中序遍历
{
	if (T){
		InOrder(T->lchild);
		printf("%d ", T->data);
		InOrder(T->rchild);
	}
}
int get_height(BstNode* T)//树高
{
	if (!T)
		return 0;
	int left_height = get_height(T->lchild);//左树高
	int right_heiight = get_height(T->rchild);//右树高

	return left_height > right_heiight ? left_height + 1 : right_heiight + 1;
}
BstNode* right_Rotation(BstNode* T)//右旋
{
	BstNode* left_child = T->lchild;
	T->lchild = left_child->rchild;
	left_child->rchild = T;
	T = left_child;
	return T;
}
BstNode* left_Rotation(BstNode* T)//左旋
{
	BstNode* right_child = T->rchild;
	T->rchild = right_child->lchild;
	right_child->lchild = T;
	T = right_child;
	return T;
}
BstNode* left_right_Rotation(BstNode* T)//左旋失衡因子左子树，右旋失衡因子
{
	T->lchild = left_Rotation(T->lchild);
	T = right_Rotation(T);
	return T;
}
BstNode* right_left_Rotation(BstNode* T)//右旋失衡因子右子树，左旋失衡因子
{
	T->rchild = right_Rotation(T->rchild);
	T = left_Rotation(T);
	return T;
}
BstNode* Update_Rotation(BstNode* T)//更新树高并旋转失衡节点
{
	if (T){
		T->lchild = Update_Rotation(T->lchild);
		T->rchild = Update_Rotation(T->rchild);
		T->bf = get_height(T->lchild) - get_height(T->rchild);//更新树高
		if (T->bf<-1 || T->bf>1){//失衡调整
			if (T->bf > 1){
				if (T->lchild->bf > 0)//LL型 - 右旋
					T = right_Rotation(T);
				else//LR型 - 先左旋在右旋
					T = left_right_Rotation(T);
			}
			if (T->bf < -1){
				if (T->rchild->bf < 0)//RR型 - 左旋
					T = left_Rotation(T);
				else//RL型 - 先右旋在左旋
					T = right_left_Rotation(T);
			}
		}
	}	
	return T;
}
void test()
{
	BstNode* root = creatBst();
	InOrder(root);
}
int main()
{
	test();

	return 0;
}