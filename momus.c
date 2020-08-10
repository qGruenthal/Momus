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

  scm_c_eval_string("(load-extension \".\/libcommandline_interface\" \"scm_init_commandline_interface\")");
  scm_c_eval_string("(display-test)\n(newline)");

  return NULL;
}
