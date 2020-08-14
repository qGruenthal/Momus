#include "commandline_interface.h"
#include "core.h"

void
simple_output_of_test (SCM test)
{
  struct Test t = test_from_scm (test);

  printf ("%s %s for %d\n"
          , t.passed ? "Passed" : "Failed"
          , t.name
          , t.passed ? t.value : 0
          );
}

void
display_test ()
{
  printf ("Display Test\n");
}

void
scm_init_commandline_interface ()
{
  scm_c_define_gsubr ("display-test", 0, 0, 0, display_test);
  scm_c_define_gsubr ("simple-output-of-test", 1, 0, 0, simple_output_of_test);

  scm_c_eval_string("(add-hook! critique display-test)");
}
