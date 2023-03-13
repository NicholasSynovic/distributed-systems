# The commented lines are for things you may want to do in more compmlex projects
FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(cli11)

enable_testing()

add_executable(
  encoder
  encoder.cpp
)

target_link_libraries(
  encoder
  CLI11::CLI11
)

add_executable(
  decoder
  decoder.cpp
)

target_link_libraries(
  decoder
  CLI11::CLI11
)

add_executable(
  encoderTests
  encoderTests.cc
)

target_link_libraries(
  encoderTests
  gtest_main
)

add_executable(
  decoderTests
  decoderTests.cc
)

target_link_libraries(
  decoderTests
  gtest_main
)

target_link_libraries(
  decoder
  gtest_main
)

add_test(
  NAME decoderTests
  COMMAND decoder
)

include(GoogleTest)
gtest_discover_tests(encoderTests)
gtest_discover_tests(decoderTests)