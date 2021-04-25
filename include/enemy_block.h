#pragma once

#include <glm/vec2.hpp>
#include "cinder/gl/gl.h"
namespace ballblaster {

  class EnemyBlock {
 public:
  void Draw() const;
  EnemyBlock(const glm::vec2& center);

  const static size_t kWidth = 35;
  static const size_t kLength = 20;

 private:
  const cinder::ColorT<float> kColor = "purple";
  glm::vec2 center_;
};
}


