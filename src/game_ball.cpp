
#include <game_ball.h>

#include <glm/vec2.hpp>

namespace ballblaster {
GameBall::GameBall(const glm::vec2& position,const glm::vec2& velocity) {
  position_ = position;
  velocity_ = velocity;
  isSurviving = true;
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
  // if ball hits right wall and ball is moving towards right
  if ((position_.x >= end_pixel.y - (kRadius +length) &&
       (position_.x - (end_pixel.y)) *
       velocity_.x <
       0) ||
      // if ball hits left wall and ball is moving towards left
      (position_.x <= start_pixel.y + kRadius + length &&
       (position_.x - start_pixel.y) *
       velocity_.x <
       0)) {
    // negate the x velocity once it hits horizontal
    velocity_.x = -velocity_.x;
    // if the ball hits the top wall and ball is moving up
  }
  if ((position_.y >= end_pixel.x - (kRadius + length) &&
       (position_.y - (end_pixel.x)) *
       velocity_.y <
       0) ||
      // if the ball hits the bottom wall and ball is moving down
      (position_.y <= start_pixel.x + kRadius + length &&
       (position_.y - (start_pixel.x)) *
       velocity_.y <
       0)) {
    // negate the x velocity once it hits vertical
    velocity_.y = -velocity_.y;
  }
}
bool GameBall::IsSurviving() {
  return isSurviving;
}
void GameBall::ProcessCollidePlayer(const BoardPlayer& player) {
  if (position_.y >= player.GetCenter().x - player.GetLength() - kRadius && velocity_.y > 0) {
    if (position_.x  <= player.GetCenter().y + player.GetWidth() + kRadius
        && position_.x >= player.GetCenter().y - player.GetWidth() - kRadius) {
      velocity_.y = -velocity_.y;
    } else {
      isSurviving = false;
  }
}

}
}