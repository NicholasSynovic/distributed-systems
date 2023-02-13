# The commented lines are for things you may want to do in more compmlex projects
# FetchContent_MakeAvailable(googletest)

# enable_testing()

add_executable(
  encoder
  encoder.cpp
)

add_executable(
  decoder
  decoder.cpp
)

# add_executable(
  # decoderTests
  # decoderTests.cc
# )

# add_executable(
  # encoderTests
  # encoderTests.cc
# )

# target_link_libraries(
  # encoderTests
  # gtest_main
# )

# target_link_libraries(
  # decoderTests
  # gtest_main
# )

# include(GoogleTest)
# gtest_discover_tests(encoderTests)
# gtest_discover_tests(decoderTests)