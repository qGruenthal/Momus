#include "network_interface.h"

SCM
submit_test ()
{
  CURL* curl;
  CURLcode result;

  FILE* submission;
  struct stat submission_metadata;

  submission = fopen ("/proc/version", "rb");
  if (!submission)
    return SCM_EOL;

  if (fstat (fileno (submission), &submission_metadata) != 0)
    return SCM_EOL;

  curl = curl_easy_init ();
  if (curl)
    {
      curl_easy_setopt (curl, CURLOPT_URL, "file:///tmp/submission_test");
      curl_easy_setopt (curl, CURLOPT_UPLOAD, 1L);
      curl_easy_setopt (curl, CURLOPT_READDATA, submission);
      curl_easy_setopt (curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t) submission_metadata.st_size);

      result = curl_easy_perform (curl);
      if (result == CURLE_OK)
        printf ("Uploaded\n");
      else
        printf ("Failed to upload\n");

      curl_easy_cleanup (curl);
    }

  fclose (submission);

  return SCM_EOL;
}

void
scm_init_network_interface ()
{
  scm_c_define_gsubr ("submit-test", 0, 0, 0, submit_test);
}
