cc_binary(
    name = "lines",
    srcs = ["Lines.cpp"],
)

genrule(
    name = "run_test",
    srcs = ["tester.jar", ":lines"],
    cmd = "java -jar $(location tester.jar) -novis -exec \"$(location lines)\" > $@",
    outs = ["tester.out"],
)

cc_test(
    name = "lines_test",
    srcs = ["lines_test.cc"],
    deps = [
        ":lines",
        "@com_google_googletest//:gtest_main",
        ],
)
