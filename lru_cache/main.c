

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

  cache_set("B", "Bat");
  print_cache();
  cache_set("C", "Cat");
  print_cache();
  cache_set("D", "Dog");
  print_cache();
  cache_del("C");
  print_cache();
  cache_set("E", "Eagle");
  print_cache();
  cache_set("E", "Emu");
  print_cache();
  cache_set("F", "Fly");
  print_cache();
  cache_set("G", "Goose");
  print_cache();
  cache_set("H", "Hippo");
  print_cache();
  cache_set("I", "Iguana");
  print_cache();
  cache_set("J", "Jackal");
  print_cache();
  cache_set("K", "Kangaroo");
  print_cache();
  cache_set("L", "Lemur");
  print_cache();
  cache_set("M", "Mongoose");
  print_cache();
  cache_set("N", "Newt");
  print_cache();
  cache_set("O", "Osprey");
  print_cache();
  cache_set("P", "Panda");
  print_cache();
  cache_set("Q", "Quail");
  print_cache();
  cache_set("R", "Raptor");
  print_cache();
  cache_set("S", "Swan");
  print_cache();
  cache_set("T", "Tarantula");
  print_cache();
  cache_set("U", "Urchin");
  print_cache();
  cache_set("V", "Venasuar");
  print_cache();



  return 0;
}
