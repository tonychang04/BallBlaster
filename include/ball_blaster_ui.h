#pragma once

#include <glm/vec2.hpp>

#include "ball_blaster_app.h"
#include "board_player.h"

namespace ballblaster {

class BallBlasterUI {
 public:
  BallBlasterUI(const glm::vec2 start_pixel, const glm::vec2 end_pixel,
                BoardPlayer playerBoard);

  /**
  * Displays the container walls and the current positions of the particles.
  */
  void Display() const;

 private:
  BoardPlayer player_board_;
  glm::vec2 start_pixel_;
  glm::vec2 end_pixel_;
};
}

