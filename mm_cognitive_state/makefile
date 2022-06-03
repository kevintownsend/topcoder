vim:
	vim -p makefile TODO \
		BUILD \
		submission/code/src/trainer.cc \
		submission/code/src/trainer_lib.cc \
		submission/code/src/trainer_lib.h \
		submission/code/src/trainer_lib_test.cc \
		./submission/code/data/training.csv \
		./submission/code/data/testing.csv \
		./submission/code/model/dummy-model.csv \
		submission/code/src/sample/submission/trainer.py \
		submission/code/src/BUILD \
		submission/code/src/sample/submission/tester.py \
		submission/code/README.md \
		submission/code/train.sh \
		submission/code/test.sh
		#code/

test:
	bazel build trainer_lib
	bazel test trainer_lib_test

# TODO: zip submission.
run:
	bazel run trainer ./submission/code/data/training.csv ./submission/code/model/dummy-model.csv

sub: submission.zip

submission.zip: submission
	zip -r submission.zip submission
