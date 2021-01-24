/**
 * @author Ryan Stutsman <stutsman@cs.utah.edu>
 * @brief Unit tests for CS5460 Assignment 1.
 * 
 * @copyright Copyright 2021 University of Utah. All rights reserved.
 * 
 * Add tests by copying a test_ function below and adding it to the tests
 * array at the bottom of the file. The macro injects the name of the function
 * and a pointer to it into the tests array. tester.c uses the tests array
 * and runs through each of them in turn.
 * 
 * Any test function that returns is considered to have succeeded. To cause
 * a test function to fail you can call the FAIL macro or just exit(-1).
 * 
 * CHECK_PAIR(K, V) performs cache_get(K) and then asserts that the returned
 * value matches (via strcmp) V. It frees the returned string, if any. You
 * can pass NULL for V, which then asserts that NULL is returned from cache_get.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "assignment1.h"
#include "tester.h"

/** Check to make sure the key "test" doesn't have a value stored in the cache
 * after cache_clear is called (tester.c clears the cache before each call).
 */
static void test_initially_empty() {
    CHECK_PAIR("test", NULL);
}

static void test_set_get_works() {
    cache_set("test", "aaa");
    CHECK_PAIR("test", "aaa");
}

static void test_empty_after_clear() {
    cache_set("test", "aaa");
    cache_clear();
    CHECK_PAIR("test", NULL);
}

static void test_several_sets() {
    char key[16];
    char value[16];

    for (int i = 0; i < 17; i++) {
        snprintf(key, sizeof(key), "key-%d", i);
        snprintf(value, sizeof(value), "value-%d", i);
        cache_set(key, value);
    }
    CHECK_PAIR("key-0", NULL);
    CHECK_PAIR("key-1", "value-1");
    CHECK_PAIR("key-15", "value-15");
    CHECK_PAIR("key-16", "value-16");
    CHECK_PAIR("key-17", NULL);
}

#define MKTEST(name) {name, #name}
// List of tests to be executed by the tester. After you define a new
// test above, you must add a line to this array to include your new
// test if you wish to have the tester run it for you.
struct test tests[] = {
    MKTEST(test_initially_empty),
    MKTEST(test_set_get_works),
    MKTEST(test_empty_after_clear),
    MKTEST(test_several_sets),
    MKTEST(NULL),
};
