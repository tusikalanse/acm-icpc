#include <string.h>
#include <stdio.h>

char s[100];

int main() {
  scanf("%s", s);
  int l = strlen(s);
  for(int i = l - 1; ~i; --i)
    putchar(s[i]);
  putchar('\n');
  return 0;
}