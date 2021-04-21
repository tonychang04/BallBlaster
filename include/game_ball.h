#pragma once

#include <glm/vec2.hpp>

#include "board_player.h"
#include "cinder/gl/gl.h"

namespace ballblaster {
class GameBall {
 public:
  GameBall(const glm::vec2& position,const glm::vec2& velocity);

  void Draw() const;

  const glm::vec2& GetPosition() const;

  void SetPosition(const glm::vec2& position);

  const glm::vec2& GetVelocity() const;

  void SetVelocity(const glm::vec2& velocity);

  void ProcessCollideWall(const glm::vec2& start_pixel, const glm::vec2& end_pixel, size_t length);



  void ProcessCollidePlayer(const BoardPlayer& player);

  bool IsSurviving();

 private:
  bool isSurviving;
  glm::vec2 position_;
  glm::vec2 velocity_;
  const cinder::ColorT<float> kColor = "blue";
  const size_t kRadius = 20;
};
}

