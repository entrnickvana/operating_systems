/**
 * Write your solutions here and turn in just this file.
 * Please keep in mind that your solution must compile and work with the basic
 * tester and tests. Feel free to extend them, but we will have our
 * own edits to them and your assignment1.c needs to work correctly with the
 * original tests/tester.
 */
#define _POSIX_C_SOURCE 200809L // for strdup; it won't be part of C until 2023.
#include <string.h>
#include <stdlib.h>

#include "assignment1.h"

char* cache_get(const char* key) {
    return NULL;
}

void cache_set(const char* key, const char* value) {
}

bool cache_del(const char* key) {
    return false;
}

void cache_clear(void) {
}