set(OPENSSL_ROOT_DIR "/home/runner/Caesar-Cipher-1-comp-339-439-ds-8/opensslInstall")
set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")
set(OPENSSL_LIBRARY_DIR "${OPENSSL_ROOT_DIR}/lib64")

add_executable(
  bloom
  bloom.cpp
)

target_include_directories(bloom PUBLIC ${OPENSSL_INCLUDE_DIR})

target_link_libraries(
  bloom
  ${OPENSSL_LIBRARY_DIR}/libssl.so.3 ${OPENSSL_LIBRARY_DIR}/libcrypto.so.3
  CLI11::CLI11
)
