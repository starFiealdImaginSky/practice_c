#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *name;             /* nameが良くわからないアドレスを指し示している */
    name = "山田太郎";      /* nameが"山田太郎"を格納しているアドレスの先頭を指し示している。 */
    char name2[5] = "john"; /* name2[0]がjを、[1]がoを……と保持している。 */

    printf("hello world\n");
    printf("%s\n", name);     /* 文字列はポインタを指定してあげると上手く動く */
    printf("%s\n", name2);    /* name2自体は配列だが、敷野中で登場するときには先頭要素へのポインタに変換される */
    printf("%c\n", name[0]);  /* 出力が文字化け→山が8bit=1Byteに格納できていないから */
    printf("%c\n", name2[3]); /* 半角なら1Byteに格納可能。*/
}