CXX = g++
CXXFLAGS = -std=c++20 -O2 -Wall -Wextra
DBGFLAGS = -std=c++20 -g -O1 -Wall -Wextra -fsanitize=address,undefined -D_GLIBCXX_DEBUG

PROBLEMS = a b c d e f f_upsolve

.PHONY: $(PROBLEMS) $(addprefix d,$(PROBLEMS)) vim clean

$(PROBLEMS): %: %.cc
	$(CXX) $(CXXFLAGS) $< -o $@.out
	@if [ -f $@.in ]; then ./$@.out < $@.in; else ./$@.out; fi

$(addprefix d,$(PROBLEMS)): d%: %.cc
	$(CXX) $(DBGFLAGS) $< -o $*.out
	@if [ -f $*.in ]; then ./$*.out < $*.in; else ./$*.out; fi

vim:
	vim -p f_upsolve.cc f_upsolve.in
#	vim -p a.cc a.in b.cc b.in c.cc c.in d.cc d.in e.cc e.in

clean:
	rm -f *.out
