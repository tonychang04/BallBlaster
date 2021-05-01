#include <enemy_block.h>

namespace ballblaster {

  EnemyBlock::EnemyBlock(const glm::vec2& center) {
    center_ = center;
  }
  void EnemyBlock::Draw() const {
    ci::gl::color(kColor);
    ci::gl::drawSolidRect(ci::Rectf(glm::vec2(center_.y - kWidth, center_.x - kLength),
                                    glm::vec2(center_.y + kWidth, center_.x + kLength)));
  }

  void EnemyBlock::MoveOneUpdate() {
      center_.x = center_.x + kSpeed;
  };
void EnemyBlock::SetCenter(const glm::vec2& center) {
  if (center[0] < 0 || center[1] < 0) {
    throw std::invalid_argument("This is not a valid position");
  }
  center_ = center;
}

const glm::vec2& EnemyBlock::GetCenter() const {
  return center_;
}
}