#include "include.h"

int main(int argc, char const *argv[]) {
  cout << "Hello World!\n";
  printf("Hello world 2!\n");
  char *pippo;
  pippo = (char *)"Hello";
  if (strcmp((const char *)pippo, "Hello") == 0)
    printf("ok\n");
  else
    printf("ko\n");
  return 0;
}
