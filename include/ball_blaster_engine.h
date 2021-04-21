#pragma once

#include <glm/vec2.hpp>

#include "board_player.h"
#include "game_ball.h"

namespace ballblaster {

/**
 * The main game engine of the game.
 */
class BallBlasterEngine {
 public:
  BallBlasterEngine(const glm::vec2& start_pixel, const glm::vec2& end_pixel, int ball_speed);

  /**
   * Displays the current game.
   */
  void Display() const;

  /**
   * Advance the game to next frame.
   */
  void AdvanceOneFrame();

  /**
   * Move the player board by using the engine class.
   * This method calls the 'move' method of the player board class
   * @param distance the distance that the board will move
   */
  void MovePlayer(int distance);

 private:

  const size_t kBorderLength = 5;
  BoardPlayer player_board_;
  GameBall game_ball_;
  glm::vec2 start_pixel_;
  glm::vec2 end_pixel_;
};
}

