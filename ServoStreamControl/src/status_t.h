#pragma once

template <typename T>
class status_t {
public:
  bool isOk;
  T acc;
};
