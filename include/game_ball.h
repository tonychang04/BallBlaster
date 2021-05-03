#pragma once

#include "board_player.h"
#include "cinder/gl/gl.h"
#include "enemy_block.h"

namespace ballblaster {
/**
 * The ball of the game.
 */
class GameBall {
 public:
  GameBall(const glm::vec2& position, const glm::vec2& velocity);

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
  void ProcessCollideWall(const glm::vec2& start_pixel,
                          const glm::vec2& end_pixel, size_t length);

  /**
   * Process whether the ball collides with the player board.
   * @param player the player board
   */
  void ProcessCollidePlayer(const BoardPlayer& player);

  /**
   * Process whether the ball collides the enemies.
   * @param enemies the list of enemies
   */
  void ProcessCollideEnemy(std::list<EnemyBlock>& enemies);
  /**
   * Determine whether the ball is still surviving.
   * @return a boolean determining if the ball is surviving
   */
  bool IsSurviving() const;

  const glm::vec2& GetPosition() const;

  void SetPosition(const glm::vec2& position);

  const glm::vec2& GetVelocity() const;

  void SetSurviving(bool surviving);

  void SetVelocity(const glm::vec2& velocity);


 private:
  const int kMinVelocity = 2;
  const size_t kCollisionBuffer = 15;
  bool isSurviving;
  glm::vec2 position_;
  glm::vec2 velocity_;
  const cinder::ColorT<float> kColor = "blue";
  const size_t kRadius = 20;
};
}  // namespace ballblaster
