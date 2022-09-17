cc_library(
    name = "snooker_scoring",
    srcs = ["SnookerScoring.cc"],
)

cc_library(
    name = "jumpy_checkers",
    srcs = ["JumpyCheckers.cc"],
)

cc_test(
    name = "jumpy_checkers_test",
    srcs = ["jumpy_checkers_test.cc"],
    deps = [":jumpy_checkers",
            "@com_google_googletest//:gtest_main"],
)
