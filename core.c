#include "core.h"

void handle_critique ()
{
  printf ("hello: %s\n", "ant");
}

void
scm_init_module_core (void* data)
{
  SCM proc = scm_c_define_gsubr ("handle-critique", 0, 0, 0, handle_critique);

  SCM critique = scm_make_hook (scm_from_int (0));
  scm_c_define ("critique", critique);

  scm_add_hook_x (critique, proc, scm_from_bool (1));

  scm_c_run_hook (critique, SCM_EOL);

  scm_c_export ("handle-critique",
                "critique",
                NULL);
}

void
scm_init_core ()
{
  scm_c_define_module ("momus c-core",
                       (void (*) (void*)) scm_init_module_core,
                       NULL);
}
