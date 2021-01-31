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
static int dbg = 1;
pair* new_pair(const char* key, const char* value);
void to_front(struct pair* pr);
void print_cache();
int get_str_len(const char* str);

char* cache_get(const char* key) 
{
  if(head == NULL) return NULL;
  
  struct pair* curr;
  curr = head;
  
  while(curr != NULL)
  {
    if(strcmp(key, curr->key) == 0)
    {
      int val_len = strlen(curr->val);
      char* val_cpy;
      val_cpy = malloc(val_len*sizeof(char) + 1);
      strncpy(val_cpy, curr->val, val_len + 1);
      to_front(curr);
      return val_cpy;
    }
    curr = curr->next;
  }
  return NULL;
}

//char* cache_get(const char* key) 
//{
//
//  struct pair* curr_pair;
//  char* val;
//  curr_pair = head;
//  while(curr_pair != NULL)
//  {
//    if(strcmp(key, curr_pair->key) == 0)
//    {
//      int len_val;
//      len_val = get_str_len(curr_pair->val);
//      val = malloc(len_val*sizeof(char) + 1);
//      strncpy(val, curr_pair->val, len_val + 1);
//      to_front(curr_pair);
//      return val;
//    }
//    curr_pair = curr_pair->next;
//  }
//  return NULL;
//}

void cache_set(const char* key, const char* value) {
  pair* curr_pair;
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
      free((char*)curr_pair->val);
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
      ll_size++;
      return;
    }
    
    //Add newest, Remove oldest value
    if(curr_pair->next == NULL && ll_size == 16 && ii == 15)
    {
      //Delete oldest pair
      free((char*)curr_pair->key);  
      free((char*)curr_pair->val);  
      curr_pair->prev->next = NULL;
      free((char*)curr_pair);
      
      //Add newest to front
      pair* new_pr;
      new_pr = new_pair(key, value);
      to_front(new_pr);
      return;
    }
    curr_pair = curr_pair->next;
  } 

  if(dbg) printf("Error on cache_set!\n");    
  return;
}

pair* new_pair(const char* key, const char* value)
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
  return pr;  
}

//void to_front(struct pair* pr)
//{
//  //if head
//  if(pr->prev == NULL)
//  {
//    return;
//  }
//
//  //if tail
//  if(pr->next == NULL)
//  {
//    pr->prev->next = NULL;
//    head->prev = pr;
//    pr->next = head;
//    pr->prev = NULL;
//    head = pr;   
//    return;
//  }
//
//  //if body
//  if(pr->next != NULL && pr->prev != NULL)
//  {
//    pr->prev->next = pr->next;
//    pr->next->prev = pr->prev;
//    head->prev = pr;
//    pr->next = head;
//    pr->prev = NULL;
//    head = pr;
//    return;
//  }
//
//  printf("to_front error\n");
//}

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
  
  if(pr->next == NULL && pr->prev != NULL)
  {
    pr->prev->next = NULL;
    head->prev = pr;
    pr->next = head;
    head = pr;
    return;
  }
}

bool cache_del(const char* key) {

  struct pair* curr_pair;
  curr_pair = head;
  while(curr_pair != NULL)
  {
    if(strcmp(key, curr_pair->key) == 0)
    {
      free((char*)curr_pair->key);
      free((char*)curr_pair->val);
      
      //Head
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
  if(head == NULL) return;
 
  struct pair* curr;
  struct pair* nxt;
  
  curr = head;
  while(curr->next != NULL)
  {
    nxt = curr->next;
    free((char*)curr->key);
    free((char*)curr->val);
    curr->key = NULL;
    curr->val = NULL;
    free((pair*)curr);
    curr = nxt;
    ll_size--;
  }

  free((char*)curr->key);
  free((char*)curr->val);
  curr->key = NULL;
  curr->val = NULL;
  free((pair*)curr);
  ll_size--;
  head = NULL;
}

//void cache_clear(void) {
//
//  struct pair* curr_pair;
//  curr_pair = head;
//   
//  while(curr_pair->next != NULL))
//  {
//    curr_pair = curr_pair->next;
//    free((char*)curr_pair->prev->key);
//    free((char*)curr_pair->prev->val);
//    curr_pair->prev->prev = NULL;
//    curr_pair->prev->next = NULL;
//    free(curr_pair->prev);
//    curr_pair->prev = NULL;
//    ll_size--;
//  }
//  
//  free((char*)curr_pair->key);
//  free((char*)curr_pair->val);
//  curr_pair->prev = NULL;
//  curr_pair->next = NULL;
//  free(curr_pair);
//  ll_size--;
//  head = NULL;
//
//}


int get_str_len(const char* str)
{
  int ii;
  for(ii = 0; str[ii] != '\0'; ii++) {}
  return ii;
}

void print_cache()
{
  if(head == NULL)
  {
    printf("Cache is empty, SIZE = %d\n", ll_size);
    return;
  }
  
  struct pair* curr;
  curr = head;
  printf("SIZE = %d\n", ll_size);
  printf("HEAD: Key = %s, Val = %s\n", head->key, head->val);

  int idx;
  idx = 0;
  while(curr != NULL)
  {
    printf("IDX: %d\t\t CURR: Key = %s, Val = %s\n", idx, curr->key, curr->val);    
    idx++;
    curr = curr->next;
  }
  printf("\n\n\n");
  return;
}




