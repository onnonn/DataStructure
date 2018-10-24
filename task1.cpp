#include <stdio.h>
#include <stdlib.h>
struct Student{
    char id[16];
    char name[16];
    float grades[3];
    float ave;
};


int main()
{
    struct Student ss[5];
    int i, max = 0;
    for(i = 0; i < 5; i++){
        scanf("%s %s", ss[i].id, ss[i].name);
        int j;
        float sum = 0;
        for(j = 0; j < 3; j++){
            scanf("%f", &ss[i].grades[j]);
            sum += ss[i].grades[j];
        }
        ss[i].ave = sum / 3;
        if(ss[i].ave > ss[max].ave){
            max = i;
        }
    }
    for(i = 0; i < 5; i++){
        printf("%s %s %f\n", ss[i].id, ss[i].name, ss[i].ave);
    }
    printf("最高分学生：\n%s %s ", ss[max].id, ss[max].name);
    for(i = 0; i < 3; i++){
        printf("%f ", ss[max].grades[i]);
    }
    printf("%f", ss[max].ave);


    return 0;
}