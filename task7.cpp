#include <iostream>
#include <stdio.h>

typedef char ElemType; //字符类型

typedef struct Node {
    ElemType data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createTree(){
    Node *root;
    char c;
    scanf("%c", &c);
    if(c == '#'){//用#表示空结点
        root = NULL;
    } else {
        root = (Node *)malloc(sizeof(Node));
        root->data = c;
        root->left = createTree();
        root->right = createTree();
    }
    return root;
}

void inorder(Node *root){
    if(root != NULL){
        inorder(root->left); //遍历左子树
        printf("%c", root->data); // 输出根节点
        inorder(root->right); //遍历右子树
    } else {
        printf("#");
    }
}

int main(){
    inorder(createTree());
    return 0;
}

/* eg: 
    input: ab#c##de###  output:#b#c#a#e#d#
    input: abc##de#g##f###  output:#c#b#e#g#d#f#a#
*/