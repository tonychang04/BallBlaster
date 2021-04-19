

#include <board_player.h>

#include <glm/vec2.hpp>
namespace ballblaster {
 BoardPlayer::BoardPlayer(const glm::vec2& center) {
    center_ = center;
 }

  void BoardPlayer::draw() const {
    ci::gl::color(ci::Color("white"));
    ci::gl::drawStrokedRect(ci::Rectf(glm::vec2(center_.y - kWidth, center_.x - kLength),
                                      glm::vec2(center_.y + kWidth, center_.x + kLength)));
  }

  void BoardPlayer::move(int distance) {
    center_.y = center_.y + distance;
  }
}