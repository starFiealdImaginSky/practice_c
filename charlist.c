#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *name;
    name = "山田太郎";
    char *name2;
    name2 = "john";

    printf("hello world\n");
    printf("%s\n", name);     /* 文字列はポインタを指定してあげると上手く動く */
    printf("%c\n", name[0]);  /* 出力が文字化け→山が8bit=1Byteに格納できていないから */
    printf("%c\n", name2[0]); /* 半角なら1Byteに格納可能。*/
}