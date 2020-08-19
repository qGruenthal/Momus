#include <libguile.h>
#include <unistd.h>
#include <stdio.h>
#include <curl/curl.h>

#ifndef CORE_H
#define CORE_H

struct Test {
  char* name;
  int passed;
  int value;
};

struct Test test_from_scm (SCM test);

void scm_init_module_core ();
void scm_init_core ();

#endif
