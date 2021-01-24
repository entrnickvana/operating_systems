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

typedef struct {
  char* key;
  char* val;
  struct pair* next;
  struct pair* prev;
  
} pair;

static pair* head = NULL;
static int ll_size = 0;

char* cache_get(const char* key) {
  return NULL;
}

void cache_set(const char* key, const char* value) {
  
  pair* curr_pair;
  size_t len_key;
  size_t len_val;

  if(head == NULL)
  {
    head = new_pair(key, value);
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
      pair* new_pr;
      new_pr = new_pair(key, value);
      to_front(new_pr);
      return;
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
  pair* pr;
  pr = malloc(sizeof(pair));
  pr->key = malloc(len_key*sizeof(char) + 1);
  pr->val = malloc(len_val*sizeof(char) + 1);
  strncpy(pr->key, key, len_key + 1);
  strncpy(pr->val, value, len_val + 1);
  pr->next = NULL;
  pr->prev = NULL;
  ll_size++;
  return pr;  
}

void to_front(pair* pr)
{
  pair* tmp;
  if(pr->prev == NULL) // head
  {
    //do nothing
  }
  else if(pr->prev != NULL && pr->next != NULL) // mid body
  {
    tmp->next = pr->next;
    tmp->prev = pr->prev;
    
    pr->next = head;
    pr->prev = NULL;
    head->prev = pr;
    head = pr;

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
  }
  else // tail
  {
    pr->prev->next = NULL;
    head->prev = pr;
    pr->prev = NULL;
    head = pr;
  }
}

bool cache_del(const char* key) {
  printf("CACHE_DEL\n");
  return false;
}

void cache_clear(void) {
  printf("CACHE_CLEAR\n");
  if(lru_cache != NULL)
    free_heap(lru_cache);
  else { printf("[free]: lru_cache is NULL\n"); }
  return;
}

int free_heap(heap_array* hp)
{

  if(hp == NULL){ printf("hp is NULL\n"); return 1; }

  int ii;
  for(ii = 0; ii < 16; ii++)
  { 
    if(hp->pairs[ii] != NULL)
      if(!free_pair(hp->pairs[ii]))
        return 0;
  }
  free(hp);
  return 1;
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

void print_heap(void)
{

}


