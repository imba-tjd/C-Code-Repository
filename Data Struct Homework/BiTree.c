// 用链式存储构建一个二叉树，使用非递归中序遍历的方法输出这个树
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree CreateBiTree(char *const string);
BiTNode *CreateBitNode(char **ch);

BiTree CreateBiTree(char *const string)
{
    char *chs = string;
    return CreateBitNode(&chs);
}

BiTNode *CreateBitNode(char **ch)
{
    BiTNode *bn = (BiTNode *)malloc(sizeof(BiTNode));
    bn->data = **ch;
    bn->lchild = bn->rchild = NULL;

    if (*((*ch)++) == '#')
        return bn;

    bn->lchild = CreateBitNode(ch);
    bn->rchild = CreateBitNode(ch);
    return bn;
}

void ShowBiTree(BiTree bt)
{
    BiTNode *stack[20];
    int top = -1;
    BiTNode *p = bt;

    do
    {
        while (p->data != '#')
        {
            stack[++top] = p;
            p = p->lchild;
        }

        p = stack[top--];
        printf("%c", p->data);
        p = p->rchild;
    } while (top > -1);

    /*
    do
    {
        if (p->lchild->data != '#')
        {
            stack[++top] = p;
            p = p->lchild;
            continue;
        }

        printf("%c", p->data);

        if (p->rchild->data != '#')
        {
            stack[++top] = p;
            p = p->rchild;
            continue;
        }

        p = stack[top--];
    } while (top > -1);
    */
}

int main(void)
{
    BiTree bt = CreateBiTree("ABC##DE#G##F###");
    ShowBiTree(bt);
    return 0;
}