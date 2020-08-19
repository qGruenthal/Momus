#include <libguile.h>
#include <stdio.h>
#include <sys/stat.h>
#include <curl/curl.h>

#ifndef NETWORK_INTERFACE_H
#define NETWORK_INTERFACE_H

void submit_test ();

void scm_init_network_interface ();

#endif
