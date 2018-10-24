
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 21
#define M 1000

typedef struct Dictionary{
    char word[N];
    int count;
}Dict;

void str_tolower(char *str){//把字符串全部转换成小写
    while(*str){
        *str = tolower(*str);
        str++;
    }
}

int main()
{
    FILE *f = fopen("D:\\abc.txt", "r");//我统计的是这个地方的文本中的单词
    Dict dict[M] = {{0}};//初始化结构体数组
    char w[N] = {0};
    int wcount = 0;
    while(fscanf(f, "%s", w) != EOF){ //使用fscanf来读取字符串
        str_tolower(w);//都转换成小写字母，避免因为首字母大写而算成两个单词
        if(!(w[strlen(w)-1] >= 'a' && w[strlen(w)-1] <= 'z')){//如果最后一个字符不是英文，那么就是标点符号，需要去除
            w[strlen(w)-1] = '\0';
        }
        int flag = 1;
        for(int i = 0; i < wcount; i++){
            if(strcmp(w, dict[i].word) == 0){ //字典里已存在
                dict[i].count++;
                flag = 0;
            }
        }
        if(flag){//字典里不存在
            strcpy(dict[wcount].word, w);
            dict[wcount].count++;
            wcount++;
        }

    }
    for(int i = 0; i < wcount; i++){
        printf("%15s%5d\n", dict[i].word, dict[i].count);
    }
    fclose(f);

    return 0;
}