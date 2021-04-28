#pragma once

#include <glm/vec2.hpp>

#include "board_player.h"
#include "enemy_block.h"
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

  /**
   * Restart the game engine.
   */
  void Restart();

 private:

  const size_t kSpawnEnemyFrame = 100;
  const size_t kBorderLength = 5;

  size_t player_score_;
  std::string kScoreMessage = "Score: ";
  const glm::vec2 kScoreLocation = glm::vec2(600, 300);
  ci::Font kScoreFont = ci::Font("Helvetica Neue", 30);

  glm::vec2 initial_player_pos_;
  glm::vec2 initial_ball_pos_;
  int initial_ball_speed;

  size_t frame_count_;
  std::list <EnemyBlock> enemies_;
  BoardPlayer player_board_;
  GameBall game_ball_;
  glm::vec2 top_left_pixel_;
  glm::vec2 bottom_right_pixel_;
};
}

