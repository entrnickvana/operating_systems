
#include "assignment1.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{

  cache_clear();
  printf("Clear 1 passed\n");
  cache_clear();
  printf("Clear 2 passed\n");

  return 1;
  cache_set("A", "Alligator");
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

  //Now full, try to break with get
  printf("cache_get:\t\tQ\t\t%s\n", cache_get("Q"));
  print_cache();
  printf("cache_get:\t\tH\t\t%s\n", cache_get("H"));
  print_cache();
  cache_clear();
  print_cache();

  cache_set("Q", "Quail");
  cache_set("R", "Raptor");
  cache_set("S", "Swan");
  cache_set("T", "Tarantula");
  cache_set("U", "Urchin");
  cache_set("V", "Venasuar");
  print_cache();
  cache_del("R");
  cache_del("S"); 
  print_cache();

  printf("cache_get:\t\tQ\t\t%s\n", cache_get("Q"));
  printf("cache_get:\t\tU\t\t%s\n", cache_get("U"));
  print_cache();

  cache_set("I", "Iguana");
  cache_set("J", "Jackal");
  cache_set("K", "Kangaroo");
  cache_set("L", "Lemur");
  cache_set("M", "Mongoose");
  cache_set("N", "Newt");
  cache_set("O", "Osprey");
  cache_set("P", "Panda");
  cache_set("Q", "Quail");
  cache_set("R", "Raptor");
  cache_set("S", "Swan");
  cache_set("T", "Tarantula");
  cache_set("U", "Urchin");
  cache_set("V", "Venasuar");
  print_cache();


  return 0;
}
