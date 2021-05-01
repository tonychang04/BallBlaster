#include <ball_blaster_app.h>

#include <catch2/catch.hpp>
#include <glm/vec2.hpp>

TEST_CASE("Player movement") {
  glm::vec2 top_left_pixel(100, 100);
  glm::vec2 bottom_right(750, 550);
  glm::vec2 ball_speed(3, 4);
  glm::vec2 ball_position(300, 300);
  glm::vec2 board_position(700, 325);
  ballblaster::EnemyBlock enemyBlock(glm::vec2(100, 100));
  std::list<ballblaster::EnemyBlock> enemies;
  enemies.push_back(enemyBlock);

  SECTION("Move Player to right without restrictions") {
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.MovePlayer(2);
    REQUIRE(engine.GetBoard().GetCenter().x == 700);
    REQUIRE(engine.GetBoard().GetCenter().y == 327);
  }

  SECTION("Move Player to left without restrictions") {
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.MovePlayer(-2);
    REQUIRE(engine.GetBoard().GetCenter().x == 700);
    REQUIRE(engine.GetBoard().GetCenter().y == 323);
  }

  SECTION("Move Player to right with restriction") {
    glm::vec2 board_position2(700, 549);
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position2, ball_speed,
                                          ball_position, enemies);
    engine.MovePlayer(3);
    REQUIRE(engine.GetBoard().GetCenter().x == 700);
    REQUIRE(engine.GetBoard().GetCenter().y == 549);
  }

  SECTION("Move Player to left with restriction") {
    glm::vec2 board_position2(700, 101);
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position2, ball_speed,
                                          ball_position, enemies);
    engine.MovePlayer(-3);
    REQUIRE(engine.GetBoard().GetCenter().x == 700);
    REQUIRE(engine.GetBoard().GetCenter().y == 101);
  }
}