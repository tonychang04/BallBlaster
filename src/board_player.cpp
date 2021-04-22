

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
}