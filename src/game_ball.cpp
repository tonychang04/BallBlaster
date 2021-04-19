
#include <game_ball.h>

#include <glm/vec2.hpp>

namespace ballblaster {
GameBall::GameBall(const glm::vec2& position,const glm::vec2& velocity) {
  position_ = position;
  velocity_ = velocity;
}
void GameBall::Draw() const {
  std::cout << position_.x;
  std::cout << kRadius;
  ci::gl::color(ci::Color("blue"));
  ci::gl::drawSolidCircle(position_, kRadius);

  //ci::gl::drawSolidCircle(glm::vec2(300,300), 30);
}
const glm::vec2& GameBall::GetPosition() const {
  return position_;
}

void GameBall::SetPosition(const glm::vec2& position) {
  if (position[0] < 0 || position[1] < 0) {
    throw std::invalid_argument("This is not a valid position");
  }
  position_ = position;
}

const glm::vec2& GameBall::GetVelocity() const {
  return velocity_;
}

void GameBall::SetVelocity(const glm::vec2& velocity) {
  velocity_ = velocity;
}

}