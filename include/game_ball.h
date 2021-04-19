#pragma once

#include "cinder/gl/gl.h"
#include <glm/vec2.hpp>

namespace ballblaster {
class GameBall {
 public:
  GameBall();

  glm::vec2 GetPosition() const;

  void SetPosition(const glm::vec2& position);

  glm::vec2 GetVelocity() const;

  void SetVelocity(const glm::vec2& velocity);

  size_t GetRadius() const;


 private:
  glm::vec2 position_;
  glm::vec2 velocity_;
  const cinder::ColorT<float> color_ = "white";
  const size_t radius_ = 10;
};
}

