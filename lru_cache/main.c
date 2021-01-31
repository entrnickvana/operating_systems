
#include "assignment1.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
  
  //cache_set("A", "Alligator");
  //cache_set("AA", "Arab");
  //cache_set("B", "Black");
  //cache_set("BB", "Blow Job");
  //cache_del("AA");
  //printf("cache_get A = %s\n",cache_get("A"));
  //printf("cache_get BB = %s\n",cache_get("BB"));
  //print_cache();
  //
  //cache_clear();
  //print_cache();
  //printf("cache_get A = %s\n",cache_get("A"));
  //print_cache();

  
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
  printf("Cache_get = %s\n", cache_get("K"));
  print_cache();
  printf("Cache_get = %s\n", cache_get("J"));
  print_cache();
  cache_del("V");
  print_cache();
  cache_set("V", "Veep");
  print_cache();
  cache_set("W", "Wildebeast");
  print_cache();
  cache_clear();
  print_cache();

  cache_set("HHH", "Hippo1");
  print_cache();
  cache_set("III", "Iguana1");
  print_cache();
  cache_set("JJJ", "Jackal1");
  print_cache();
  cache_set("KKK", "Kangaroo1");
  print_cache();
  cache_set("LLL", "Lemur1");
  print_cache();
  cache_set("MMM", "Mongoose1");
  print_cache();
  cache_set("NNN", "Newt1");
  print_cache();
  cache_set("OOO", "Osprey1");
  print_cache();
  cache_set("PPP", "Panda1");
  print_cache();
  cache_set("QQQ", "Quail1");
  print_cache();
  cache_set("RRR", "Raptor1");
  print_cache();
  cache_set("SSS", "Swan1");
  print_cache();
  cache_set("TTT", "Tarantula1");
  print_cache();
  cache_set("UUU", "Urchin1");
  print_cache();
  cache_set("VVV", "Venasuar1");

  cache_set("E", "Eagle");
  print_cache();
  cache_set("E", "Emu");
  print_cache();
  cache_set("FFFF", "Fly");
  print_cache();
  cache_clear();
  printf("\nAAAA\n");
  print_cache();
  printf("\nBBB\n");
  cache_set("FFFaB", "Flyer");
  //printf("cache_get E = %s\n",cache_get("E"));
  printf("cache_get FFFaB = %s\n",cache_get("FFFaB"));
  print_cache();

  return 0;
}
