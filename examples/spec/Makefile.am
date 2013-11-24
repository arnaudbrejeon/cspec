TESTS = spec
check_PROGRAMS = $(TESTS)
CLEANFILES = output_cspec_output_junit_xml_case1.xml \
			 output_cspec_output_junit_xml_case2.xml \
			 result.xml
spec_CPPFLAGS = -I$(top_srcdir)/inc
spec_SOURCES = spec_runner.c cspec_output_junit_xml_spec.c array_spec.c
spec_LDADD = $(top_builddir)/src/libcspec.la
