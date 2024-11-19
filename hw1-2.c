#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int a[1000], b[1000], c[1000];
   
int main() {
   int t1, t2, num = 0, cnt = 0;
   FILE* fp = fopen("in1.txt", "r");
   while (!feof(fp)) {
      fscanf_s(fp, "%d", &a[cnt]);
      cnt++;
   }
   

   FILE* fp2 = fopen("in2.txt", "r");
   cnt = 0;
   while (!feof(fp2)) {
      fscanf_s(fp2, "%d", &b[cnt]);
      cnt++;
   }

   for (int i = 0;i < 8;i++)
   {
      for (int j = 0;j < 10;j++)
      {
         if (a[i] == b[j]) {
            c[num] = a[i];
            num++;
            break;
         }
         if (a[i] < b[j]) {
            break;
         }
      }
   }
   for (int i = 0; i < num;i++) {
      printf("%d\n", c[i]);
   }
}