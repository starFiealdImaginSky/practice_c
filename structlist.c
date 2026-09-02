#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 構造体Employeeを定義 */
struct Employee
{
    char *name;
    int age;
    char dept[4];
};

/* プロトタイプ宣言 */
void print_Emp(struct Employee *emp);

int main(void)
{
    char *new_name; /* new_name自体にはアドレスが格納。*new_nameによりそのアドレスを辿って中身を見る。 */
    int new_age;
    char new_dept[4] = "ES";
    new_name = "山田太郎";
    new_age = 30;

    struct Employee emp1 = {"山田花子", 23, "ES"};

    struct Employee emp2;
    emp2.name = new_name;
    emp2.age = new_age;
    strcpy(emp2.dept, new_dept); /* char[4]型のemp2のメンバdeptにnew_deptを格納する方法。中身を知らないので、アドレスを使ってるかとかは良くわからん。 */
    print_Emp(&emp1); /* &を使うことで引数にはアドレスが入れられる。 */

    /*struct Employee *emp3;
    emp3->age = 32;
    emp3->name = "哲郎";
    strcpy(emp3->dept, "ES");
    print_Emp(emp3);
    ↑これはsegmentation fault。Employee構造体を置くメモリが確保できていない。状態で、emp3というEmployeeを指すポインタだけが定義され、emp3が指している場所のageに32を書き込んでと言っているから。emp3が有効な場所を指していないからこのエラーを発する。
    */
}

/* 構造体empのメンバを出力する関数。empそのものにはアドレスが格納されており、*empとすることで、そのアドレスに居る構造体を指し示せる。 */
void print_Emp(struct Employee *emp) /* 仮引数を*empとした場合、これは変数宣言のchar *nameと同じような振る舞いをすると考えればよい。 */
{
    printf("名前：%s, 年齢：%d, 部署：%s\n", emp->name, emp->age, emp->dept);
    /* 1.構造体ポインタを使っているから、->を使って、メンバを表示。 */
}