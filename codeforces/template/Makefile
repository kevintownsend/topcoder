CXX = g++
CXXFLAGS = -std=c++20 -O2 -Wall -Wextra
DBGFLAGS = -std=c++20 -g -O1 -Wall -Wextra -fsanitize=address,undefined -D_GLIBCXX_DEBUG

TARGETS := $(patsubst %.cc,%,$(wildcard *.cc))

.PHONY: $(TARGETS) $(addprefix d,$(TARGETS)) vim clean

$(TARGETS): %: %.cc
	$(CXX) $(CXXFLAGS) $< -o $@.out
	@if [ -f $@.in ]; then ./$@.out < $@.in; \
	elif [ -f $(firstword $(subst _, ,$@)).in ]; then ./$@.out < $(firstword $(subst _, ,$@)).in; \
	else ./$@.out; fi

$(addprefix d,$(TARGETS)): d%: %.cc
	$(CXX) $(DBGFLAGS) $< -o $*.out
	@if [ -f $*.in ]; then ./$*.out < $*.in; \
	elif [ -f $(firstword $(subst _, ,$*)).in ]; then ./$*.out < $(firstword $(subst _, ,$*)).in; \
	else ./$*.out; fi

vim:
	vim -p a.cc a.in b.cc b.in c.cc c.in d.cc d.in e.cc e.in f.cc f.in

clean:
	rm -f *.out
