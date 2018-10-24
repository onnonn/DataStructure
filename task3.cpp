#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node* next;
} Node;

void insertAfter(Node* p1, Node *p2) {
    p2->next = p1->next;
    p1->next = p2;
}
void input(Node* List){
    ElemType tmp;
    Node* p1 = List;
    while(scanf("%d", &tmp)){
        Node* p2 = (Node* )malloc(sizeof(Node));
        p2->data = tmp;
        p2->next = NULL;
        insertAfter(p1, p2);
        p1 = p1->next;
        if(getchar() == '\n'){
            break;
        }
    }
}

void print(Node* head) {
    for (Node* p = head->next; p != NULL; p = p->next) { //从head后开始打印
        printf("%d ", p->data);
    }
    printf("\n");
}
void mergelist(Node* l1, Node* l2){
    Node* i = l1;
    Node* j = l2->next;
    Node* k;
    while(i->next != NULL && j != NULL){
        if(i->next->data > j->data){
            k = j->next;
            insertAfter(i, j);
            j = k;
        } else {
            i = i->next;
        }
    }
    if(j){
        i->next = j;
    }
}
int main()
{
    Node* l1 = (Node *)malloc(sizeof(Node));
    Node* l2 = (Node *)malloc(sizeof(Node));
    l1->next = NULL;
    l2->next = NULL;
    printf("input list1: ");    input(l1);
    printf("input list2: ");    input(l2);

    mergelist(l1,l2);
    print(l1);

    return 0;
}