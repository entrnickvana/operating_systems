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

/* //TODO
* 1)  cache_del implementation 
* 2)  pop oldest pair
* 3)
* 4)
* 5)
* 6)
* 7)
*/

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

char* cache_get(const char* key) 
{
  
  struct pair* curr_pair;
  char* val;
  curr_pair = head;
  while(curr_pair != NULL)
  {
    if(strcmp(key, curr_pair->key) == 0)
    {
      int len_val;
      len_val = get_str_len(curr_pair->val);
      val = malloc(len_val*sizeof(char) + 1);
      strncpy(val, curr_pair->val, len_val + 1);
      to_front(curr_pair);
      return val;
    }
    curr_pair = curr_pair->next;
  }
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
  for(ii = 0; ii < 16 && curr_pair != NULL; ii++)
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
      struct pair* new_pr;
      new_pr = new_pair(key, value);
      to_front(new_pr);
      return;
    }

    curr_pair = curr_pair->next;
  } 
    
  //Delete oldest pair
  free(curr_pair->key);  
  free(curr_pair->val);  
  curr_pair->prev->next = NULL;
  free(curr_pair);
  
  //Add newest to front
  pair* new_pr;
  new_pr = new_pair(key, value);
  to_front(new_pr);
  ll_size++;
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
  if(pr->next == NULL && pr->prev == NULL)
  {
    head->prev = pr;
    pr->next = head;
    pr->prev = NULL;
    head = pr;
    return;
  }
  
  //Mid body pair
  if(pr->next != NULL && pr->prev != NULL)
  {
    pr->prev->next = pr->next;
    pr->next->prev = pr->prev;
    
    head->prev = pr;
    pr->next = head;
    head = pr;
    return;
  }
}

bool cache_del(const char* key) {

  struct pair* curr_pair;
  char* val;
  curr_pair = head;
  while(curr_pair != NULL)
  {
    if(strcmp(key, curr_pair->key) == 0)
    {
      free(curr_pair->key);
      free(curr_pair->val);
      
      if(curr_pair == head)
      {
        free(head);
        head = NULL;
        ll_size--;
        return true;
      }

      // Mid body
      if(curr_pair->prev != NULL && curr_pair->next != NULL)
      {
        curr_pair->prev->next = curr_pair->next;
        curr_pair->next->prev = curr_pair->prev;
        free(curr_pair);
        ll_size--;
        return true;
      }
      // Tail
      if(curr_pair->prev != NULL && curr_pair->next == NULL)
      {
        curr_pair->prev->next = NULL;
        free(curr_pair);
        ll_size--;
        return true;
      }
    }
    curr_pair = curr_pair->next;
  }
  return false;
}

void cache_clear(void) {
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
  if(head == NULL) {printf("Empty Cache\n"); return;}
  struct pair* curr_pair;
  curr_pair = head;


  int idx;
  idx = 0;
  while(curr_pair->next != NULL && idx < 16)
  {
    printf("IDX:  %d  KEY:  %s   VAL:   %s\n", idx, curr_pair->key, curr_pair->val);
    idx++;
    curr_pair = curr_pair->next;
  }  
   printf("IDX:  %d  KEY:  %s   VAL:   %s\n", idx, curr_pair->key, curr_pair->val);
}


