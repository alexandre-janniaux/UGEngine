#pragma once

namespace uge {

class NonCopyable
{
  protected:
    NonCopyable () {}
    ~NonCopyable () {} 
  private: 
    NonCopyable (const NonCopyable &) = delete;
    NonCopyable& operator= (const NonCopyable &) = delete;
};

} // namespace uge