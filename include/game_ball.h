#pragma once

#include <glm/vec2.hpp>

#include "board_player.h"
#include "cinder/gl/gl.h"
#include "enemy_block.h"

namespace ballblaster {
/**
 * The ball of the game.
 */
class GameBall {
 public:
  GameBall(const glm::vec2& position,const glm::vec2& velocity);

  /**
   * Drawing the ball based on it's position
   */
  void Draw() const;

  /**
   * Process whether the ball collides with the wall.
   * @param start_pixel the top left pixel of the wall
   * @param end_pixel the bottom right pixel of the wall
   * @param length the length of the container
   */
  void ProcessCollideWall(const glm::vec2& start_pixel, const glm::vec2& end_pixel, size_t length);

  /**
   * Process whether the ball collides with the player board.
   * @param player the player board
   */
  void ProcessCollidePlayer(const BoardPlayer& player);

  void ProcessCollideEnemy(std::list<EnemyBlock>& enemies);
  /**
   * Determine whether the ball is still surviving.
   * @return a boolean determining if the ball is surviving
   */
  bool IsSurviving();


  const glm::vec2& GetPosition() const;

  void SetPosition(const glm::vec2& position);

  const glm::vec2& GetVelocity() const;

  void SetVelocity(const glm::vec2& velocity);

 private:
  bool isSurviving;
  glm::vec2 position_;
  glm::vec2 velocity_;
  const cinder::ColorT<float> kColor = "blue";
  const size_t kRadius = 20;
};
}

