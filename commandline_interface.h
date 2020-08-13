#include <libguile.h>
#include <stdio.h>

#ifndef COMMANDLINE_INTERFACE_H
#define COMMANDLINE_INTERFACE_H

void simple_output_of_test (SCM test);

void scm_init_commandline_interface ();

#endif
