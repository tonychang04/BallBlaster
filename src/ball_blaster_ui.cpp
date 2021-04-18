

#include <ball_blaster_app.h>
#include <ball_blaster_ui.h>

#include <glm/vec2.hpp>

using glm::vec2;
namespace ballblaster{
  BallBlasterUI::BallBlasterUI(const glm::vec2 start_pixel, const glm::vec2 end_pixel) {
    start_pixel_ = start_pixel;
    end_pixel_ = end_pixel;
  }
  void BallBlasterUI::Display() const {
    ci::gl::color(ci::Color("white"));
    ci::gl::drawStrokedRect(ci::Rectf(vec2(start_pixel_.y, start_pixel_.x),
                                      vec2(end_pixel_.y, end_pixel_.x)), 5);
  }
}