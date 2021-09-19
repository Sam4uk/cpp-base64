#include "base64.h"
// #include <iostream>

#include <gtest/gtest.h>

// #define ENCODED "Закодовано: "
// #define DECODED "Декодовано: "
const std::string k_encoded{"Закодовано: "};
const std::string k_decoded{"Декодовано: "};
const std::string k_reference{"Опорний   : "};

TEST(Base64, encode_cyr) {
  const std::string s =
      "Самчук Тарас\n"
      "https://sam4uk.site\n"
      "пристрасть до даних\n";

  std::string encoded = base64_encode(
      reinterpret_cast<const unsigned char *>(s.c_str()), s.length());
  std::string decoded = base64_decode(encoded);

  ASSERT_EQ(decoded, s);

  std::cout << k_encoded << std::endl << encoded << std::endl << std::endl;
  std::cout << k_decoded << std::endl << decoded << std::endl;
}
TEST(Base64, encode_cyr_0) {
  // Test all possibilites of fill bytes (none, one =, two ==)
  // References calculated with: https://www.base64encode.org/

  std::string rest0_original = "АБВ";
  std::string rest0_reference = "0JDQkdCS";

  std::string rest0_encoded = base64_encode(
      reinterpret_cast<const unsigned char *>(rest0_original.c_str()),
      rest0_original.length());

  ASSERT_EQ(rest0_encoded, rest0_reference);

  std::string rest0_decoded = base64_decode(rest0_encoded);

  ASSERT_EQ(rest0_decoded, rest0_original);

  std::cout << k_encoded << rest0_encoded << std::endl;
  std::cout << k_reference << rest0_reference << std::endl;
  std::cout << k_decoded << rest0_decoded << std::endl << std::endl;
}
TEST(Base64, encode_cyr_1) {
  std::string rest1_original = "АБВГ";
  std::string rest1_reference = "0JDQkdCS0JM=";

  std::string rest1_encoded = base64_encode(
      reinterpret_cast<const unsigned char *>(rest1_original.c_str()),
      rest1_original.length());

  ASSERT_EQ(rest1_encoded, rest1_reference);

  std::string rest1_decoded = base64_decode(rest1_encoded);

  ASSERT_EQ(rest1_decoded, rest1_original);

  std::cout << k_encoded << rest1_encoded << std::endl;
  std::cout << k_reference << rest1_reference << std::endl;
  std::cout << k_decoded << rest1_decoded << std::endl << std::endl;
}
TEST(Base64, encode_cyr_2) {
  std::string rest2_original = "АБВГД";
  std::string rest2_reference = "0JDQkdCS0JPQlA==";

  std::string rest2_encoded = base64_encode(
      reinterpret_cast<const unsigned char *>(rest2_original.c_str()),
      rest2_original.length());

  ASSERT_EQ(rest2_encoded, rest2_reference);

  std::string rest2_decoded = base64_decode(rest2_encoded);

  ASSERT_EQ(rest2_decoded, rest2_original);

  std::cout << k_encoded << rest2_encoded << std::endl;
  std::cout << k_reference << rest2_reference << std::endl;
  std::cout << k_decoded << rest2_decoded << std::endl << std::endl;
}