vim:
	vim -p makefile TODO \
		LostTreasureHunter.cpp \
		BUILD \
		random_walk.h \
		random_walk.cc \
		random_walk_test.cc \
		solution.cc \
		marauders_map.cc \
		marauders_map.h \
		marauders_map_test.cc

test:
	bazel test ...

run:
	java -jar tester.jar -exec "bazel run :solution"

cat:
	cat marauders_map.h random_walk.h random_walk.cc marauders_map.cc solution.cc > LostTreasureHunter.cpp
