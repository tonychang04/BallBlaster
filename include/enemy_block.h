#pragma once

#include "cinder/gl/gl.h"
namespace ballblaster {

  class EnemyBlock {
 public:
  void Draw() const;
  EnemyBlock(const glm::vec2& center);

  const static size_t kWidth = 35;
  static const size_t kLength = 20;

  /**
   * Move enemy to the next update.
   */
  void MoveOneUpdate();

  void SetCenter(const glm::vec2& center);

  const glm::vec2& GetCenter() const;
 private:

  const size_t kSpeed = 1;
  const cinder::ColorT<float> kColor = "purple";
  glm::vec2 center_;
};
}


