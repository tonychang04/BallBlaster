#pragma once

#include <glm/vec2.hpp>

#include "board_player.h"
#include "game_ball.h"

namespace ballblaster {

class BallBlasterEngine {
 public:
  BallBlasterEngine(const glm::vec2 start_pixel, const glm::vec2 end_pixel);

  /**
   * Displays the container walls and the current positions of the particles.
   */
  void Display() const;

  void AdvanceOneFrame();

  void MovePlayer(int distance);

 private:
  GameBall game_ball_;

  BoardPlayer player_board_;


  glm::vec2 start_pixel_;
  glm::vec2 end_pixel_;
};
}

