CFLAGS = -Wall

if DEBUG
CFLAGS += -g
else
CFLAGS += -DNDEBUG -O2
endif

if PROFILE
CFLAGS += -pg
endif

if COVERAGE
CFLAGS += -fprofile-arcs -ftest-coverage
endif

INCLUDES	=	-I$(top_srcdir)/inc

lib_LIBRARIES	=	libcspec.a
libcspec_a_SOURCES	=	\
	cspec_output_header.c \
	cspec_output_verbose.c \
	cspec_output_xml.c \
	cspec_runner.c \
	cspec_config.c \
	cspec_output_unit.c \
	cspec_private.c \
	cspec_output.c \
	array.c \
	cspec_output_junit_xml.c
