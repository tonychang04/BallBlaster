#pragma once

#include "cinder/gl/gl.h"
namespace ballblaster {

  class EnemyBlock {
 public:
  void Draw() const;
  EnemyBlock(const glm::vec2& center);



  /**
   * Move enemy to the next update.
   */
  void MoveOneUpdate();

  void SetCenter(const glm::vec2& center);

  const glm::vec2& GetCenter() const;

  const static size_t kWidth = 35;
  const static size_t kLength = 20;

 private:

  const size_t kSpeed = 1;
  const cinder::ColorT<float> kColor = "purple";
  glm::vec2 center_;
};
}


