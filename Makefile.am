bin_PROGRAMS = momus
momus_SOURCES = momus.c core.c core.h
momus_CFLAGS = $(GUILE_CFLAGS) $(CURL_CFLAGS)
momus_LDFLAGS = $(GUILE_LIBS) $(CURL_LIBS)

lib_LTLIBRARIES = libcommandline_interface.la
libcommandline_interface_la_SOURCES = commandline_interface.c commandline_interface.h core.c core.h
libcommandline_interface_la_CFLAGS = $(GUILE_CFLAGS)
libcommandline_interface_la_LDFLAGS = $(GUILE_LIBS)
