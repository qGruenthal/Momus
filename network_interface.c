#include "network_interface.h"

void
submit_test (SCM url)
{
  CURL* curl;
  CURLcode  result;

  FILE* submission;
  struct stat submission_metadata;

  submission = fopen ("/proc/version", "rb");
  if (!submission)
    return ;

  if (fstat (fileno (submission), &submission_metadata) != 0)
    return ;

  curl = curl_easy_init ();

  if (curl)
    {
      curl_easy_setopt (curl, CURLOPT_URL, scm_to_locale_string (url)); // "file:///tmp/submission_test");
      //curl_easy_setopt (curl, CURLOPT_UPLOAD, 1L);
      //curl_easy_setopt (curl, CURLOPT_READDATA, submission);
      //curl_easy_setopt (curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t) submission_metadata.st_size);

      result = curl_easy_perform (curl);
      if (result == CURLE_OK)
        printf ("Uploaded\n");
      else
        printf ("Failed to upload\n");

      curl_easy_cleanup (curl);
    }

  fclose (submission);
}

void
scm_init_network_interface ()
{
  //curl_global_init (CURL_GLOBAL_ALL);

  scm_c_define_gsubr ("submit-test", 1, 0, 0, submit_test);

  atexit (curl_global_cleanup);
}
