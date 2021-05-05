#include <ball_blaster_app.h>

#include <catch2/catch.hpp>
#include <glm/vec2.hpp>


TEST_CASE("Spawning enemies") {
  glm::vec2 top_left_pixel(100, 100);
  glm::vec2 bottom_right(750, 550);
  glm::vec2 ball_speed(0, 0);
  glm::vec2 ball_position(300, 300);
  glm::vec2 board_position(700, 325);
  ballblaster::EnemyBlock enemyBlock(glm::vec2(100, 100));
  std::list<ballblaster::EnemyBlock> enemies;
  ballblaster::BallBlasterEngine engines(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
  for (size_t index = 0; index < 100; ++index) {
    engines.AdvanceOneFrame();
  }
  REQUIRE(engines.GetEnemies().size() == 1);
  REQUIRE(engines.GetEnemies().front().GetCenter().x < 750);
  REQUIRE(engines.GetEnemies().front().GetCenter().x > 100);
  REQUIRE(engines.GetEnemies().front().GetCenter().y > 100);
  }

TEST_CASE("Enemies disappear mechanism") {
  glm::vec2 top_left_pixel(100, 100);
  glm::vec2 bottom_right(750, 550);
  glm::vec2 ball_speed(1, 1);
  glm::vec2 ball_position(300, 300);
  glm::vec2 board_position(700, 325);
  std::list<ballblaster::EnemyBlock> enemies;

  SECTION("Enemy is out of the container") {
    ballblaster::EnemyBlock enemyBlock(glm::vec2(729, 200));
    enemies.push_back(enemyBlock);
    ballblaster::BallBlasterEngine engines(top_left_pixel, bottom_right,
                                           board_position, ball_speed,
                                           ball_position, enemies);
    engines.AdvanceOneFrame();
    // the enemy disappeared
    REQUIRE(engines.GetEnemies().size() == 0);
  }

  SECTION("Ball hits the enemy") {
    ballblaster::EnemyBlock enemyBlock(glm::vec2(325, 325));
    enemies.push_back(enemyBlock);
    ballblaster::BallBlasterEngine engines(top_left_pixel, bottom_right,
                                           board_position, ball_speed,
                                           ball_position, enemies);
    engines.AdvanceOneFrame();
    // the enemy disappeared
    REQUIRE(engines.GetEnemies().size() == 0);
  }
}

