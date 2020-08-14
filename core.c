#include "core.h"

struct Test
test_from_scm (SCM test)
{
  SCM name = scm_list_ref (test, scm_from_int8 (0));
  SCM passed = scm_list_ref (test, scm_from_int8 (1));
  SCM value = scm_list_ref (test, scm_from_int8 (2));

  struct Test t;

  t.name = scm_to_locale_string (SCM_CDR (name));
  t.passed = scm_to_bool (SCM_CDR (passed));
  t.value = scm_to_int (SCM_CDR (value));

  return t;
}

void
scm_init_module_core (void* data)
{
  SCM critique = scm_make_hook (scm_from_int (0));
  scm_c_define ("critique", critique);

  scm_c_export ("critique",
                NULL);
}

void
scm_init_core ()
{
  scm_c_define_module ("momus c-core",
                       (void (*) (void*)) scm_init_module_core,
                       NULL);
}
