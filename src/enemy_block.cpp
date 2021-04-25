
#include <enemy_block.h>

#include <glm/vec2.hpp>
namespace ballblaster {

  EnemyBlock::EnemyBlock(const glm::vec2& center) {
    center_ = center;
  }
  void EnemyBlock::Draw() {
    ci::gl::color(kColor);
    ci::gl::drawSolidRect(ci::Rectf(glm::vec2(center_.y - kWidth, center_.x - kLength),
                                    glm::vec2(center_.y + kWidth, center_.x + kLength)));
  }
}