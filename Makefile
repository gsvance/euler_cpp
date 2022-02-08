# Top-level Makefile for euler_cpp



# List of all extant problem directories: "001/ 002/ ..."
DIRS = $(wildcard [0-9][0-9][0-9]/)

# Phony clean targets for each directory: "001/clean 002/clean ..."
CLEANS = $(patsubst %/,%/clean,$(DIRS))



# This makefile is just for running other makefiles, so everything is phony!
.PHONY: all clean cleanall $(DIRS) $(CLEANS)



# By default, make every directory
all: $(DIRS)

# Each directory depends only on its own Makefile
# The -C option for make means "cd here first, then run make"
$(DIRS): %/: %/Makefile
	make -C $@

# I couldn't decide, so both of these targets run clean in all directories
clean: $(CLEANS)
cleanall: $(CLEANS)

# Run clean inside each directory using its makefile
$(CLEANS): %/clean:
	make -C $*/ clean

