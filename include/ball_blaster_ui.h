#pragma once
#import "ball_blaster_app.h"
namespace ballblaster {

class BallBlasterUI {
 public:
  BallBlasterUI(const glm::vec2 start_pixel, const glm::vec2 end_pixel);

  /**
  * Displays the container walls and the current positions of the particles.
  */
  void Display() const;
}
}

