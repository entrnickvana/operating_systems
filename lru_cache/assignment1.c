/**
 * Write your solutions here and turn in just this file.
 * Please keep in mind that your solution must compile and work with the basic
 * tester and tests. Feel free to extend them, but we will have our
 * own edits to them and your assignment1.c needs to work correctly with the
 * original tests/tester.
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "assignment1.h"

typedef struct pair{
  char* key;
  char* val;
  struct pair* next;
  struct pair* prev;
  
} pair;

static struct pair* head = NULL;
static int ll_size = 0;
pair* new_pair(char* key, const char* value);
void to_front(struct pair* pr);
int free_pair(pair* pr);
void print_cache();

char* cache_get(const char* key) {
  return NULL;
}

void cache_set(const char* key, const char* value) {
  
  pair* curr_pair;
  size_t len_key;
  size_t len_val;

  if(head == NULL)
  {
    printf("Creating Cache\n");
    head = new_pair(key, value);
    printf("HEAD KEY: %s  VAl:  %s\n", head->key, head->val);
    ll_size = 1;
    return;
  }

  int ii;
  curr_pair = head;
  for(ii = 0; ii < 16; ii++)
  {

    //Key Match
    if(strcmp(key,  curr_pair->key) == 0)
    { 
      printf("MATCH!\n");
      free(curr_pair->val);
      len_val = get_str_len(value);
      curr_pair->val = malloc(len_val*sizeof(char) + 1);
      strncpy(curr_pair->val, value, len_val);
      to_front(curr_pair);
      return;
    }

    //End of key-value pairs
    if(curr_pair->next == NULL && ll_size < 16)
    {
      printf("REACHED END OF PAIRS, INDEX: %d\n", ii);
      struct pair* new_pr;
      new_pr = new_pair(key, value);
      to_front(new_pr);
      return;
    }

    if(curr_pair->next != NULL)
    {
      printf("Incrementing pair\nCURR: %s | %s\n", curr_pair->key, curr_pair->val);
      printf("NEXT: %s | %s\n", curr_pair->next->key, curr_pair->next->val);      
      curr_pair = curr_pair->next;
    }

  } 
  return;
}

pair* new_pair(char* key, const char* value)
{
  size_t len_key;
  size_t len_val;
  len_key = get_str_len(key);
  len_val = get_str_len(value);
  struct pair* pr;
  pr = (struct pair*)malloc(sizeof(pair));
  pr->key = (char*)malloc(len_key*sizeof(char) + 1);
  pr->val = (char*)malloc(len_val*sizeof(char) + 1);
  strncpy(pr->key, key, len_key + 1);
  strncpy(pr->val, value, len_val + 1);
  pr->next = NULL;
  pr->prev = NULL;
  printf("NEW PAIR KEY | VAL:  %s | %s\n", pr->key, pr->val);
  ll_size++;
  return pr;  
}

void to_front(struct pair* pr)
{

  printf("to_front\n");
  //Adding new pair
  if(pr->next == NULL && pr->prev == NULL)
  {
    printf("adding to front\n");
    head->prev = pr;
    pr->next = head;
    pr->prev = NULL;
    head = pr;
    ll_size++;
    printf("HEAD: key|val: %s | %s\n", head->key, head->val);
    printf("NEXT: key|val: %s | %s\n", head->next->key, head->next->val);

  }
}

bool cache_del(const char* key) {
  printf("CACHE_DEL\n");
  return false;
}

void cache_clear(void) {
  printf("CACHE_CLEAR\n");
  return;
}

int free_pair(pair* pr)
{
  if(pr != NULL)
  { 
    if(pr->key != NULL) { free(pr->key);}
    if(pr->val != NULL) { free(pr->val);}
    free(pr);
  }
  else { printf("pr is NULL");}
  return 1;

}

int get_str_len(char* str)
{
  int ii;
  for(ii = 0; str[ii] != '\0'; ii++) {}
  return ii;
}

void print_cache()
{
  printf("Current Size: %d\n", ll_size);
  struct pair* curr_pair;
  curr_pair = head;

  int idx;
  idx = 0;
  while(curr_pair->next != NULL)
  {
    printf("IDX:  %d  KEY:  %s   VAL:   %s\n", idx, curr_pair->key, curr_pair->val);
    idx++;
    curr_pair = curr_pair->next;
  }  
   printf("IDX:  %d  KEY:  %s   VAL:   %s\n", idx, curr_pair->key, curr_pair->val);
}


