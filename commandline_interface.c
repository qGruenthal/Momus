#include "commandline_interface.h"

void
display_test ()
{
  printf ("Display Test\n");
}

void
scm_init_commandline_interface ()
{
  scm_c_define_gsubr ("display-test", 0, 0, 0, display_test);
}
