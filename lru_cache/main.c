

#include "assignment1.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    
  printf("Hello World!!!\n");

  cache_set("tesla1", "my");
  cache_set("tesla2", "name");
  cache_set("tesla3", "is");
  cache_set("tesla4", "Jonas");
  print_cache();  

  //  cache_set("1", "my");
  //  cache_set("2", "name");
  //  cache_set("3", "is"); 
  //  cache_set("4", "Jonas");
  //  cache_get("dummy");
  //
  //
  //  cache_set("A", "my");
  //  cache_set("B", "heart");
  //  cache_set("C", "is"); 
  //  cache_set("D", "beating");
  //  cache_set("E", "like");
  //  cache_set("F", "a");
  //  cache_set("G", "hammer");
  //  cache_get("dummy");  
  //
  //  cache_clear();
  //
  //  cache_set("A1", "Bro");
  //  cache_set("A2", "Brah");
  //  cache_set("A3", "Broseph");
  //  cache_get("dummy");


  return 0;
}
