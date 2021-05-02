

#include <board_player.h>

#include <glm/vec2.hpp>
namespace ballblaster {
 BoardPlayer::BoardPlayer(const glm::vec2& center) {
    center_ = center;
 }

  void BoardPlayer::Draw() const {
    ci::gl::color(kColor);
    ci::gl::drawSolidRect(ci::Rectf(glm::vec2(center_.y - kWidth, center_.x - kLength),
                                      glm::vec2(center_.y + kWidth, center_.x + kLength)));
  }

  void BoardPlayer::move(int distance) {
    center_.y = center_.y + distance;
  }

  size_t BoardPlayer::GetLength() const {
    return kLength;
  }
  size_t BoardPlayer::GetWidth() const {
    return kWidth;
  }

  const glm::vec2& BoardPlayer::GetCenter() const {
    return center_;
  }

  bool BoardPlayer::HasCollideEnemy(const std::list<EnemyBlock>& enemies) {
    for (const EnemyBlock& enemy : enemies) {
      if (enemy.GetCenter().x + enemy.kLength > center_.x - kLength)
      {
        if ((center_.y + kWidth > enemy.GetCenter().y - enemy.kWidth &&
            center_.y - kWidth < enemy.GetCenter().y - enemy.kWidth) ||
            (center_.y - kWidth < enemy.GetCenter().y + enemy.kWidth &&
             center_.y + kWidth > enemy.GetCenter().y + enemy.kWidth)) {
          return true;
        }
      }
    }
    return false;
  }


void BoardPlayer::SetCenter(const glm::vec2& center) {
  if (center[0] < 0 || center[1] < 0) {
    throw std::invalid_argument("This is not a valid position");
  }
  center_ = center;
}
}