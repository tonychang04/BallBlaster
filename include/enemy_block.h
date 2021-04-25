#pragma once

#include <glm/vec2.hpp>
#include "cinder/gl/gl.h"
namespace ballblaster {

  class EnemyBlock {
 public:
  void Draw();
  EnemyBlock(const glm::vec2& center);
 private:
  const cinder::ColorT<float> kColor = "pixie powder";
  size_t kLength = 10;
  size_t kWidth = 5;
  glm::vec2 center_;
};
}


