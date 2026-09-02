#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp; /* fpはアドレス */
    char buf[100];
    char *file_name;
    file_name = "sample.txt";

    fp = fopen(file_name, "r");
    /* fopen_s(&fp,file_name,"r"); */ /* 第1引数：ファイルアタのポインタ変数のアドレスを指定する(開いているファイルへのポインタを受け取るファイルポインタ　へのポインタ)。これにより、第２引数で指定下ファイルを、第3引数で選んだモード（r:読み込み専用）で開き、その開いたファイルのアドレスを、第1引数で指定したポインタ変数fpにわたす。 */
    if (fp == NULL)                   /* fpがポインタを受け取れない場合、fpにはNULLが入る。 */
    {
        printf("ファイルを開けません\n");
        return 1;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL) /* fgets_s(buf,sizeof(buf),fp) */
    /* char *fgets(char* buf,int n, FILE *fp)に対して、
    buf:読み込んだ文字列を格納する文字配列へのポインタ。
    n:読み込む最大文字数
    stream:読み込む元のファイルポインタである。
    これは、
    1.改行文字\nを読み込む(\nを配列に格納),
    2.n-1文字に達した場合、
    3.EOFに達した場合に終了する。
    戻り値は成功時には　引数bufと同じポインタを返す。終了条件に達したとき、その次には\0が添加される。失敗時・EOF達成時にはNULLを返す。

    */
    {
        for (int i = 0; buf[i] != '\0'; i++) /* 1行分のデータを見る。終端文字を見たら終わる。 */
        {
            if (buf[i] != ',' && buf[i] != '\n' && buf[i] != '\r') /* コンマ・改行・復帰を除いて取得、入力。 */
            {
                printf("%c", buf[i]); /* 文字分割が出来る関数がありそう。strtok関数なるものがあるが、結構複雑そうなので要調査 */
            }
        }
    }
    printf("\n");
    fclose(fp);
    return 0;
    /* まだ、malloc,realloc,freeについて調べられていないので、それは要注意 */
}