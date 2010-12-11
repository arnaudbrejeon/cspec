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

TESTS	=	spec
check_PROGRAMS	=	$(TESTS)
spec_SOURCES	=	spec_runner.c cspec_output_junit_xml_spec.c array_spec.c
spec_LDADD	=	../src/libcspec.a
