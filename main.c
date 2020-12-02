#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree{
    char data;
    struct Tree* lchild,* rchild;
}tree;

typedef struct Node {
    tree *data;//数据域
    struct Node *next;//指针域
}LinkStack;


void InitStack(LinkStack **S)
{
    (*S) = (LinkStack *)malloc(sizeof(LinkStack));
    (*S)->next = NULL;
}

/*入栈*/
void Push(LinkStack **S, tree **x)
{
    LinkStack *p;
    p = (LinkStack *)malloc(sizeof(LinkStack));
    p->data = *x;//存入要入栈的信息
    p->next = (*S)->next;
    (*S)->next = p;

}

/*出栈*/
int Pop(LinkStack **S,tree **c)
{
    LinkStack *p=(*S)->next;
    if ((*S)->next == NULL)
    {
        exit(0);
    }
    else
    {
        *c = p->data;//返回栈顶的值
        (*S)->next = p->next;//栈顶位置变化
        free(p);//释放栈顶空间
    }
}

int CreateTree(tree **T) {
    char ch;
    printf("please input");
    scanf("%c",&ch);
    getchar();
    printf("%c\n",ch);
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (tree *)malloc(sizeof(tree));
        if (T == NULL)
        {
            printf("failed\n");
            return 0;
        }
        else
        {
            (*T)->data = ch;
            CreateTree(&((*T)->lchild));
            CreateTree(&((*T)->rchild));
        }
    }
}

void PreOrderTree(tree *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        printf("%c ",T->data);
        PreOrderTree(T->lchild);
        PreOrderTree(T->rchild);
    }
}

void MiddleOrderTree(tree *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        PreOrderTree(T->lchild);
        printf("%c ",T->data);
        PreOrderTree(T->rchild);
    }
}

void LastOrderTree(tree *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        PreOrderTree(T->lchild);
        PreOrderTree(T->rchild);
        printf("%c ",T->data);
    }
}

void PreShowTree(tree *T) {
    LinkStack *s;
    InitStack(&s);
    while(s||T) {
        if(T)
        {
            printf("%c ",T->data);//（访问）打印结点
            Push(&s,&T);
            T=T->lchild;
        }
        if(T == NULL){
            Pop(&s,&T);//结点弹出堆栈
            T=T->rchild;//转向右子树
        }
    }
}

int main () {
    tree *T;
    CreateTree(&T);
    PreShowTree(T);
}