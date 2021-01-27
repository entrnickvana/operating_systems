

#include "assignment1.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
  cache_set("A", "Alligator");
  print_cache();
  printf("cache_get A = %s\n",cache_get("A"));
  cache_del("A");
  print_cache();
  return 0;
}
