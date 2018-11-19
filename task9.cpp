#include <iostream>
#include <windows.h>
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

//void quickSort(int a[], int left, int right){
//    if(left > right){
//        return;
//    } else {
//        int i = left, j = right, tmp = a[left];
//        while(i != j){
//            for(; i < j && a[j] >= tmp; j--);
//            for(; i < j && a[i] <= tmp; i++);
//            if(i < j){
//                swap(&a[i], &a[j]);
//            }
//        }
//        a[left] = a[i];
//        a[i] = tmp;
//        quickSort(a, left, i-1);
//        quickSort(a, i+1, right);
//    }
//}

int partition(int a[], int left, int right){
    int i = left;
    for(int j = i+1; j <= right; j++){
        if(a[left] > a[j]){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[left], &a[i]);
    return i;
}

void quickSort(int a[], int left, int right) {
    if(left < right){
        int pivet = partition(a, left, right);
        quickSort(a, left, pivet-1);
        quickSort(a, pivet+1, right);
    }
}

int main(){
    srand((unsigned)time(NULL));
    DWORD start, finish;
    double duration;
    int n = random(10, 50000);//产生一个10～50000间的数
    int *a = (int *)malloc(sizeof(int) * n);
    randomNumber(a, n);//随机生成数组中的元素
    int b[n], c[n];
    for(int i = 0; i < n; i++){
        b[i] = a[i];
        c[i] = a[i];
    }

    //冒泡排序：
    start = GetTickCount();
    bubbleSort(a, n);
    finish = GetTickCount();
    duration = (finish - start) / 1000.0;
    printf("bubbleSort running time: %lf s\n", duration);
    //插入排序：
    start = GetTickCount();
    insertSort(b, n);
    finish = GetTickCount();
    duration = (finish - start) / 1000.0;
    printf("insertSort running time: %lf s\n", duration);
    //快速排序：
    start = GetTickCount();
    quickSort(c, 0, n-1);
    finish = GetTickCount();
    duration = (finish - start) / 1000.0;
    printf("quickSort running time: %lf s\n", duration);
/*
     for(int i = 0; i < n; i++){
         printf("%d ", a[i]);
     }
     printf("\n");
     for(int i = 0; i < n; i++){
         printf("%d ", b[i]);
     }

     printf("\n");
         for(int i = 0; i < n; i++){
         printf("%d ", c[i]);
     }
*/
    return 0;
}
