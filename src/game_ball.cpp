
#include <game_ball.h>

#include <glm/vec2.hpp>

namespace ballblaster {
GameBall::GameBall(const glm::vec2& position,const glm::vec2& velocity) {
  position_ = position;
  velocity_ = velocity;
}
void GameBall::Draw() const {
  ci::gl::color(kColor);
  ci::gl::drawSolidCircle(position_, kRadius);
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

void GameBall::ProcessCollideWall(const glm::vec2& start_pixel, const glm::vec2& end_pixel, size_t length) {
  // if particle hits right wall and particle is moving towards right
  if ((position_.x >= end_pixel.y - (kRadius +length) &&
       (position_.x - (end_pixel.y)) *
       velocity_.x <
       0) ||
      // if particle hits left wall and particle is moving towards left
      (position_.x <= start_pixel.y + kRadius + length &&
       (position_.x - start_pixel.y) *
       velocity_.x <
       0)) {
    // negate the x velocity once it hits horizontal
    velocity_.x = -velocity_.x;
    // if the particle hits the top wall and particle is moving up
  }
  if ((position_.y >= end_pixel.x - (kRadius + length) &&
       (position_.y - (end_pixel.x)) *
       velocity_.y <
       0) ||
      // if the particle hits the bottom wall and particle is moving down
      (position_.y <= start_pixel.x + kRadius + length &&
       (position_.y - (start_pixel.x)) *
       velocity_.y <
       0)) {
    // negate the x velocity once it hits vertical
    velocity_.y = -velocity_.y;
  }
}

void GameBall::ProcessCollidePlayer(const BoardPlayer& player) {
  std::cout << position_.y << " ";
  std::cout << player.GetCenter().x - player.GetLength() << std::endl;
  if (position_.y >= player.GetCenter().x - player.GetLength() - kRadius) {
    if (position_.x  <= player.GetCenter().y + player.GetWidth() + kRadius
        && position_.x >= player.GetCenter().y - player.GetWidth() - kRadius) {
      velocity_.y = -velocity_.y;
    }
  }
}

}