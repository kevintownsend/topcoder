PROBLEMS = a b c d e

r%:
	@mkdir -p $@
	@[ -f $@/Makefile ] || cp template/Makefile $@/Makefile
	@for p in $(PROBLEMS); do \
		[ -f $@/$$p.cc ] || cp template/template.cc $@/$$p.cc; \
		touch $@/$$p.in; \
	done
	@echo "Initialized codeforces/$@/"
