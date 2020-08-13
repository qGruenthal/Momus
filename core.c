#include "core.h"

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
