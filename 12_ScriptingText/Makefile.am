SUBDIRS = src tests

@DX_RULES@

gitclean: maintainer-clean
	git clean -fd

gcov:	check
	$(MAKE) -C src gcov

all-local:	doxygen-doc
