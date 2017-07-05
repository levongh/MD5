#pragma once

#include <array>
#include <cstdint>
#include <string>

using Hash128 = std::basic_string<unsigned char>;

constexpr const int BLOCK_SIZE = 64;

class MD5
{
public:
  MD5();

  std::string toString() const;
  Hash128 shortened();

  MD5& finalize();
  MD5& update(const char* in, size_t inputLen);
  MD5& update(const unsigned char* in, size_t inputLen);

private:
  void transform(const uint8_t block[BLOCK_SIZE]);

private:
  bool m_finalized;
  uint8_t m_buffer[BLOCK_SIZE];
  uint8_t m_digest[16];

  uint32_t m_state[4];
  uint32_t m_low;
  uint32_t m_high;
};

