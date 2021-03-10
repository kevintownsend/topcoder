cc_binary(
    name = "LostTreasureHunter",
    srcs = ["LostTreasureHunter.cpp"],
)

genrule(
    name = "run_test",
    srcs = ["tester.jar", ":LostTreasureHunter"],
    cmd = "java -jar $(location tester.jar) -exec \"$(location LostTreasureHunter)\" > $@",
    outs = ["tester.out"],
)

cc_library(
    name = "marauders_map",
    srcs = ["marauders_map.cc"],
    hdrs = ["marauders_map.h"],
)

cc_test(
    name = "marauders_map_test",
    srcs = ["marauders_map_test.cc"],
    deps = [":marauders_map",
            "@com_google_googletest//:gtest_main"],
)

# TODO: add random solver.
cc_library(
    name = "random_walk",
    srcs = ["random_walk.cc"],
    hdrs = ["random_walk.h"],
    deps = [":marauders_map"],
)

cc_test(
    name = "random_walk_test",
    srcs = ["random_walk_test.cc"],
    deps = [":random_walk",
            "@com_google_googletest//:gtest_main"],
)

# TODO: add binary.
cc_binary(
    name = "solution",
    srcs = ["solution.cc"],
    deps = [":random_walk"],
)
