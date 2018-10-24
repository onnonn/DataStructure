#include <iostream>
#include <stdio.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node* next;
} Node, *ListNode;

ListNode initCircle(int len){
    ListNode circle = (ListNode)malloc(sizeof(Node));
    ListNode tail = NULL, new_node = NULL;
    circle->data = 1;
    circle->next = circle;
    tail = circle; // tail指向链表的最后一个元素
    int i;
    for(i = 2; i <= len; i++){
        new_node = (ListNode)malloc(sizeof(Node));
        new_node->data = i;
        new_node->next = circle; //创建新结点并且指针域指向头结点
        tail->next = new_node;  //原本的结尾节点指针域指向新结点
        tail = new_node;  //tail指向新的最后一个元素
    }
    return circle;
}

Node* findNode(Node* Start, int index){
    Node *p = Start;
    for(int i = 1; i < index; i++){
        if(p->next){
            p = p->next;
        }else{
            return NULL;
        }
    }
    return p;
}

void deleteNode(Node* p1, Node* p2){
    p1->next = p2->next;
    p2 = NULL;
}

void sovleJosephus(Node* start, int d){
    Node* p = start;
    if(p->next == start){//只剩一个了直接输出返回
        printf("%d ", p->data);
        return;
    }
    Node* p1 = findNode(p, d-1); //找要删除结点的前一个结点，方面后面删除
    p = p1->next;
    printf("%d ", p->data);//打印这个数
    deleteNode(p1, p);//删除这个节点
    sovleJosephus(p1->next, d);//递归调用，从下一个人开始继续报数
}


void josephus(int population, int start, int distance) {
    ListNode Circle = initCircle(population); //创建一个长度为总人数的循环链表
    Node* pNode = findNode(Circle, start); //找到开始结点
    if(pNode){
        sovleJosephus(pNode, distance);
    }else{
        printf("error");//开始的结点大于总人数，报错
    }
}

int main()
{
    int p, s, d;
    printf("input population:");        scanf("%d", &p);
    printf("input start number:");      scanf("%d", &s);
    printf("input distance:");          scanf("%d", &d);
    josephus(p, s, d);

    return 0;
}

//用循环链表写的……好像有点长 但是感觉对链表的理解加深了！ 下次用数组试试看？