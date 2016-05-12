#include <stdio.h>

#include "str.hxx"

int main(void)
{
   /* リソース確保＆初期化（中身を空文字列にする） */
   string s1, s2;

   /* "123"を設定 */
   s1.set("123");
   printf("%s\n", s1.value());  /* "123abc" */
   /* "456"を追加（"123abc"） */
   s1.add("abc");
   /* 2文字目から4文字取り出した新しい文字列を作成する（"23ab"） */
   s2 = s1.extract(1, 4);

   /* printfで出力できる文字列を返す */
   printf("%s\n", s1.value());  /* "123abc" */
   printf("%s\n", s2.value());  /* "23ab" */

   /* 文字列の長さを返す */
   printf("%d\n", s1.length()); /* 6 */
   printf("%d\n", s2.length()); /* 4 */

   return 0;
}
