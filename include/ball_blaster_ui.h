#pragma once
#include <glm/vec2.hpp>

//#import "ball_blaster_app.h"
//#import "ball_blaster_ui.h"

namespace ballblaster {

class BallBlasterUI {
 public:
  BallBlasterUI(const glm::vec2 start_pixel, const glm::vec2 end_pixel);

  /**
  * Displays the container walls and the current positions of the particles.
  */
  void Display() const;

 private:
  glm::vec2 start_pixel_;
  glm::vec2 end_pixel_;
};
}

