VERSIONS = v1 v1b v2 v3 v4 v5

.PHONY: all $(VERSIONS)

all: $(VERSIONS)
	@echo ' -- Done.'

$(VERSIONS):
	@printf 'Compile %3s ...\n' $@
	@gcc $@/main.c -o bin/license-$@
