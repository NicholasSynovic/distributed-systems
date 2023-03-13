/* test cases */

#include <gtest/gtest.h>
#include "encoder.h"

// TEST(encoderTests, PositiveNos) {
//     ASSERT_EQ(6, square_root(36.0));
//     ASSERT_EQ(18.0, square_root(324.0));
//     ASSERT_EQ(25.4, square_root(645.16));
//     ASSERT_EQ(0, square_root(0.0));
// }

// TEST(EncoderTests, setNumberOfSentences) {
//   ASSERT_EQ(10, setNumberOfSentences(0));
//   ASSERT_EQ(1, setNumberOfSentences(1));
// }

// TEST(EncoderTests, setMinimumWordLength) {
//   ASSERT_EQ(3, setMinimumWordLength(0));
//   ASSERT_EQ(1, setNumberOfSentences(1));
// }

// TEST(EncoderTests, setDictionaryPath) {
//   ASSERT_EQ("wordlist.txt", setDictionaryPath());
//   ASSERT_EQ("test", setDictionaryPath("test"));
// }

// TEST(EncoderTests, setOutputPath) {
//   ASSERT_EQ("stdout", setOutputPath());
//   ASSERT_EQ("test", setOutputPath("test"));
// }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
