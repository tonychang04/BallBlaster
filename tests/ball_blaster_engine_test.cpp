#include <ball_blaster_app.h>

#include <catch2/catch.hpp>
#include <glm/vec2.hpp>

TEST_CASE("Restart Game") {
  glm::vec2 top_left_pixel(100, 100);
  glm::vec2 bottom_right(750, 550);
  glm::vec2 board_position(700, 325);
  ballblaster::EnemyBlock enemyBlock(glm::vec2(150, 150));
  std::list<ballblaster::EnemyBlock> enemies;
  enemies.push_back(enemyBlock);
  glm::vec2 ball_speed(3, 4);
  glm::vec2 ball_position(300, 300);
  ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                        board_position, ball_speed,
                                        ball_position, enemies);
  engine.AdvanceOneFrame();
  engine.AdvanceOneFrame();
  engine.AdvanceOneFrame();
  engine.Restart();
  REQUIRE(engine.GetGameball().GetPosition() == ball_position);
  REQUIRE(engine.GetBoard().GetCenter() == board_position);
  REQUIRE(engine.GetEnemies().size() == 0);
}