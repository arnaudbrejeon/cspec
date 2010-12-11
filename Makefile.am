SUBDIRS	=	src spec

if COVERAGE
gcov:	FORCE
	cd src; gcov -b -f *.gcda
	cd spec; gcov -b -f *.gcda
	lcov -c -d . -o lcov.info
	genhtml -o gcov lcov.info
	gcovr.py -b -x > coverage.xml
endif

splint: FORCE
	splint -nullret -nullstate -usereleased -compdef -branchstate -mayaliasunique -compmempass -dependenttrans -compdestroy -statictrans -boolops -nullassign -globstate -immediatetrans -paramuse -mustfreefresh -unrecog -mustfreeonly -I$(top_srcdir)/inc $(top_srcdir)/src/*.c > $(top_srcdir)/splint.log || exit 0

cccc:	FORCE
	mkdir -p $(top_srcdir)/.cccc
	cccc --outdir=$(top_srcdir)/.cccc --lang=c $(top_srcdir)/src/*.c $(top_srcdir)/spec/*.c

cpd:	FORCE
	java net.sourceforge.pmd.cpd.CPD --minimum-tokens 100 --files $(top_srcdir) --language c  --format xml > $(top_srcdir)/cpd.xml

FORCE:
