TESTS = xml_output
check_PROGRAMS = $(TESTS)
EXTRA_DIST = CSpec-Run.xsl
CLEANFILES = results.xml
xml_output_CPPFLAGS = -I$(top_srcdir)/inc
xml_output_SOURCES = fabs_desc.c main.c
xml_output_LDADD = $(top_builddir)/src/libcspec.la
