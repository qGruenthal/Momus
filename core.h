#include <libguile.h>
#include <unistd.h>
#include <stdio.h>

#ifndef CORE_H
#define CORE_H

void handle_critique ();

void scm_init_module_core ();
void scm_init_core ();

#endif
