#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct tree
{
    char d;
    struct tree *left,*right;
};
struct tree* stack[50];
int top=-1;
void push(struct tree* root)
{
    top++;
    stack[top]=root;
}

struct tree* pop()
{
    return stack[top--];
}

void operand(char c)
{
    struct tree *root;
    root=(struct tree*)malloc(sizeof(struct tree));
    root->d=c;
    root->left=root->right=NULL;
    push(root);
}
void operator(char c)
{
    struct tree *root;
    root=(struct tree*)malloc(sizeof(struct tree));
    root->d=c;
    root->right=pop();
    root->left=pop();
    push(root);    
}

void inorder(struct tree *root)
{
    if(root==NULL)
        return;
    else
    {
        if(root!=NULL)
        {
            inorder(root->left);
        }
        printf("%c",root->d);
        inorder(root->right);
    }
}
int main()
{
    int i=0;
    char postfix[20];
    printf("Enter postfix expression:");
    scanf(" %s",postfix);
    while(postfix[i]!='\0')
    {
        if(isalnum(postfix[i]))
        {
            operand(postfix[i]);
        }
        else
        {
            operator(postfix[i]);
        }
        i++;
    }
    inorder(stack[top]);
}
