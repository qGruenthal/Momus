#include <libguile.h>
#include <unistd.h>
#include <stdio.h>

#include "core.h"

void* load_config (void* data);

int
main (int argc, char* argv[])
{
  if (access ("./config.scm", F_OK) != -1)
    scm_with_guile (&load_config, NULL);
  else
    printf ("No project exists in this directory\n");

  return 0;
}

void*
load_config (void* data)
{
  scm_init_core ();
  scm_c_primitive_load ("./config.scm");

  return NULL;
}
