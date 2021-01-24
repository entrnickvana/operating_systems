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
      curr_pair = curr_pair->next;


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
  ll_size++;
  return pr;  
}

void to_front(struct pair* pr)
{
  struct pair* tmp;
  if(pr->prev == NULL) // head
  {
    //do nothing
  }
  else if(pr->prev != NULL && pr->next != NULL) // mid body
  {
    tmp = pr;
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
  
  int ii;
  for(ii = 0; ii < 16; ii++)
  {
    if(curr_pair->next != NULL)
    {
      printf("INDEx:\t%d  KEY:\t\t%s", ii, curr_pair->key);
      printf("\t\tVALUE:\t\t%s", curr_pair->key);
      curr_pair = curr_pair->next;
    }else
    {
      printf("INDEx:\t%d  KEY:\t\tNULL", ii);
      printf("\t\tVALUE:\t\tNULL");
    }
    printf("\n");
  }
  

}


