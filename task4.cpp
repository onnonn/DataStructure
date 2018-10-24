#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void print(int a[8], int num){
    printf("第%d种:\n", num);
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(j == a[i]){
                printf("Q ");//用Q代表皇后的位置
            } else {
                printf("* ");//用*代表棋盘空位置
            }
        }
        printf("\n");
    }
    printf("---------------\n");
}


int solveQueen(int a[8], int cur, int& num){
    if(cur == 8){
        num++;
        print(a, num); //打印出棋盘
        return 0;
    }
    for(int i = 0; i < 8; i++){
        a[cur] = i;
        int flag = 1;
        for(int j = 0; j < cur; j++){
            if(a[cur] == a[j] || (abs(a[cur] - a[j]) == cur - j)){//皇后不能相互吃到的条件。由于下标不同，行数肯定不同，只需要确定列和斜向是否满足条件。
                flag = 0;
                break;
            }
        }
        if(flag){
            solveQueen(a, cur+1, num);//递归调用，放下一行的棋子
        }
    }
    return 0;
}


int main()
{
    int a[8] = {0}; //用数组表示各皇后的坐标，其中下标表示行，值表示列。即a[x]=y 表示(y,x)是皇后的坐标(左上为原点）
    int num = 0;//用于累计多少种解法
    solveQueen(a, 0, num);
    return 0;
}

//ubuntu下gcc跑比window的codeblock快好多哦233