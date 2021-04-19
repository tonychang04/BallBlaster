
#include <game_ball.h>

#include <glm/vec2.hpp>

namespace ballblaster {
glm::vec2 GameBall::GetPosition() const {
  return position_;
}

void GameBall::SetPosition(const glm::vec2& position) {
  if (position[0] < 0 || position[1] < 0) {
    throw std::invalid_argument("This is not a valid position");
  }
  position_ = position;
}

glm::vec2 GameBall::GetVelocity() const {
  return velocity_;
}

void GameBall::SetVelocity(const glm::vec2& velocity) {
  velocity_ = velocity;
}

size_t GameBall::GetRadius() const {
  return radius_;
}
}