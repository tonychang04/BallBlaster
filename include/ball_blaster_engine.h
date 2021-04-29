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
  BallBlasterEngine(const glm::vec2& top_left, const glm::vec2& bottom_right,
                    int ball_speed);

  /**
   * Constructor for testing purposes.
   * @param top_left the top left pixel of the container
   * @param bottom_right the bottom right pixel of the container
   * @param board_pos the board starting position
   * @param ball_speed the speed of the ball
   * @param ball_position the starting position of the ball
   * @param enemies the list of enemies
   */
  BallBlasterEngine(const glm::vec2& top_left, const glm::vec2& bottom_right,
                    const glm::vec2& board_pos, const glm::vec2& ball_speed,
                    const glm::vec2& ball_position, const std::list<EnemyBlock>& enemies);

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

  const glm::vec2 kEndScreenPosition = glm::vec2(100, 50);
  ci::Font kEndScreenFont = ci::Font("Impact", 35);

  glm::vec2 initial_player_pos_;
  glm::vec2 initial_ball_pos_;
  int initial_ball_speed;

  size_t frame_count_;
  std::list<EnemyBlock> enemies_;
  BoardPlayer player_board_;
  GameBall game_ball_;
  glm::vec2 top_left_pixel_;
  glm::vec2 bottom_right_pixel_;
};
}  // namespace ballblaster
