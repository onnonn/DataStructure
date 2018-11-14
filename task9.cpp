#include <iostream>
#include <stdio.h>
#include <time.h>
#define random(x,y) (x + rand()% (y-x))

void* randomNumber(int* a, int n){
    for(int i = 0; i < n; i++){
        a[i] = random(0, 50);
    }
}

void swap(int *x,int *y){
    int tmp;
    tmp=*x;
    *x=*y;
    *y=tmp;
}

void bubbleSort(int a[], int n){ // 冒泡排序
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

void insertSort(int a[], int n){
    for(int i = 1; i < n; i++){
        int tmp = a[i], j;
        for(j = i-1; j >= 0 && tmp < a[j]; j--){
            a[j+1] = a[j];
        }
        a[j+1] = tmp;
    }
}

void quickSort(int a[], int left, int right){
    if(left > right){
        return;
    } else {
        int i = left, j = right, tmp = a[left];
        while(i != j){
            for(; i < j && a[j] >= tmp; j--);
            for(; i < j && a[i] <= tmp; i++);
            if(i < j){
                swap(&a[i], &a[j]);
            }
        }
        a[left] = a[i];
        a[i] = tmp;
        quickSort(a, left, i-1);
        quickSort(a, i+1, right);
    }
}


int main(){
    srand((unsigned)time(NULL));
    double start, finish, duration;
    int n = random(10, 50);//产生一个10～50间的数
    int *a = (int *)malloc(sizeof(int) * n);
    randomNumber(a, n);//随机生成数组中的元素
    int b[n], c[n];
    for(int i = 0; i < n; i++){
        b[i] = a[i];
        c[i] = a[i];
    }

    //冒泡排序：
    start = clock();  
    bubbleSort(a, n);
    finish = clock();
    duration = (finish - start) / CLOCKS_PER_SEC; 
    printf("bubbleSort running time: %lf s\n", duration);
    //插入排序：
    start = clock();  
    insertSort(b, n);
    finish = clock();
    duration = (finish - start) / CLOCKS_PER_SEC; 
    printf("insertSort running time: %lf s\n", duration);
    //快速排序：
    start = clock();  
    quickSort(c, 0, n-1);
    finish = clock();
    duration = (finish - start) / CLOCKS_PER_SEC; 
    printf("quickSort running time: %lf s\n", duration);

    // for(int i = 0; i < n; i++){
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    // for(int i = 0; i < n; i++){
    //     printf("%d ", b[i]);
    // }

    // printf("\n");
    //     for(int i = 0; i < n; i++){
    //     printf("%d ", c[i]);
    // }
    return 0;
}