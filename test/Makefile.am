FINALTARGET = ikev2_test

AM_CPPFLAGS = -DPACKAGE_LOCALE_DIR=\""$(localedir)"\"
AM_CPPFLAGS += -DPACKAGE_SRC_DIR=\""$(srcdir)"\"
AM_CPPFLAGS += -DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"
AM_CPPFLAGS += -Wall -Werror

bin_PROGRAMS = $(FINALTARGET)

## Put all your source files here
ikev2_test_SOURCES = ikev2_test.cc

# Clean files generated by gcov
clean-local: clean-local-check

.PHONY: clean-local-check

clean-local-check: ; rm -rf ikev2_test
