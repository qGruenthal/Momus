#include "commandline_interface.h"

void
simple_output_of_test (SCM test)
{
  SCM name = scm_list_ref (test, scm_from_int8 (0));
  SCM passed = scm_list_ref (test, scm_from_int8 (1));
  SCM value = scm_list_ref (test, scm_from_int8 (2));

  int p = scm_to_bool (SCM_CDR (passed));
  printf ("%s %s for %d\n"
          , p ? "Passed" : "Failed"
          , scm_to_locale_string (SCM_CDR (name))
          , p ? scm_to_int (SCM_CDR (value)) : 0
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
