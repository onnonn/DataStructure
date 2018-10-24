#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 100

typedef int ElemType;

typedef struct {
    ElemType *elems;
    int len;
    int size;
} ArrayList;

void init(ArrayList& list){
    list.elems = (ElemType *) malloc(sizeof(ElemType) * INIT_SIZE);
    list.len = 0;
    list.size = INIT_SIZE;
}

void add(ArrayList& list, ElemType e){
    list.elems[list.len] = e;
    list.len++;
    //printf("%d ", list.elems[list.len-1]);
}

void input(ArrayList& list){
    int tmp;
    while(scanf("%d", &tmp)){
        add(list, tmp);
        if(getchar() == '\n'){//
            break;
        }
    }
}
void print(ArrayList& list) {
    for (int i = 0; i < list.len; i++) {
        printf("%d ", list.elems[i]);
    }
    printf("\n");
}

int main()
{
    ArrayList l1,l2,l3;
    init(l1);
    init(l2);
    init(l3);
    printf("input list1:");     input(l1);
    printf("input list2:");     input(l2);
    int i = 0, j = 0;
    while(1){
        if(l1.elems[i] < l2.elems[j]){
            add(l3,l1.elems[i]);
            i++;
        }
        else{
            add(l3,l2.elems[j]);
            j++;
        }
        if(i >= l1.len || j >= l2.len){
            break;
        }
    }
    if(i == l1.len){
        for(; j < l2.len; j++){
            add(l3,l2.elems[j]);
        }
    } else {
        for(; i < l1.len; i++){
            add(l3,l1.elems[i]);
        }
    }
    print(l3);

    return 0;
}