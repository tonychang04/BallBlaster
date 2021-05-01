
#include <ball_blaster_app.h>

#include <catch2/catch.hpp>
#include <glm/vec2.hpp>

TEST_CASE("Game ball movement") {
  glm::vec2 top_left_pixel(100, 100);
  glm::vec2 bottom_right(750, 550);
  glm::vec2 board_position(700, 325);
  glm::vec2 ball_speed(3, 4);
  glm::vec2 ball_position(300, 300);
  ballblaster::EnemyBlock enemyBlock(glm::vec2(100, 100));
  std::list<ballblaster::EnemyBlock> enemies;
  enemies.push_back(enemyBlock);

  SECTION("Movement after 1 frame without any collision") {
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.AdvanceOneFrame();
    REQUIRE(engine.GetGameball().GetPosition().x == 303);
    REQUIRE(engine.GetGameball().GetPosition().y == 304);
  }
}
