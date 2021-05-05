
#include <ball_blaster_app.h>

#include <catch2/catch.hpp>
#include <glm/vec2.hpp>

TEST_CASE("Game ball movement") {
  glm::vec2 top_left_pixel(100, 100);
  glm::vec2 bottom_right(750, 550);
  glm::vec2 board_position(700, 325);
  ballblaster::EnemyBlock enemyBlock(glm::vec2(100, 100));
  std::list<ballblaster::EnemyBlock> enemies;
  enemies.push_back(enemyBlock);

  SECTION("Movement after 1 frame without any collision") {
    glm::vec2 ball_speed(3, 4);
    glm::vec2 ball_position(300, 300);
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.AdvanceOneFrame();
    REQUIRE(engine.GetGameball().GetPosition().x == 303);
    REQUIRE(engine.GetGameball().GetPosition().y == 304);
  }
}

TEST_CASE("Game ball collision with wall") {
  glm::vec2 top_left_pixel(100, 100);
  glm::vec2 bottom_right(750, 550);
  glm::vec2 board_position(700, 325);
  ballblaster::EnemyBlock enemyBlock(glm::vec2(100, 100));
  std::list<ballblaster::EnemyBlock> enemies;
  enemies.push_back(enemyBlock);

  SECTION("Ball collides left wall") {
    glm::vec2 ball_speed(-4, 2);
    glm::vec2 ball_position(101, 200);
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.AdvanceOneFrame();
    // negates x
    REQUIRE(engine.GetGameball().GetVelocity().x == 4);
    REQUIRE(engine.GetGameball().GetVelocity().y == 2);
  }

  SECTION("Ball collides right wall") {
    glm::vec2 ball_speed(9, 2);
    glm::vec2 ball_position(547, 300);
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.AdvanceOneFrame();
    // negates x
    REQUIRE(engine.GetGameball().GetVelocity().x == -9);
    REQUIRE(engine.GetGameball().GetVelocity().y == 2);
  }

  SECTION("Ball collides top wall") {
    glm::vec2 ball_speed(5, -7);
    glm::vec2 ball_position(150, 103);
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.AdvanceOneFrame();
    REQUIRE(engine.GetGameball().GetVelocity().x == 5);
    // negates y
    REQUIRE(engine.GetGameball().GetVelocity().y == 7);
  }

  SECTION("Ball collides top left corner") {
    glm::vec2 ball_speed(-5, -7);
    glm::vec2 ball_position(102, 103);
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.AdvanceOneFrame();
    // negates x and y
    REQUIRE(engine.GetGameball().GetVelocity().x == 5);
    REQUIRE(engine.GetGameball().GetVelocity().y == 7);
  }

  SECTION("Ball collides top right corner") {
    glm::vec2 ball_speed(5, -7);
    glm::vec2 ball_position(547, 103);
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.AdvanceOneFrame();
    // negates x and y
    REQUIRE(engine.GetGameball().GetVelocity().x == -5);
    REQUIRE(engine.GetGameball().GetVelocity().y == 7);
  }
}

TEST_CASE("Ball collide with player board") {
  glm::vec2 top_left_pixel(100, 100);
  glm::vec2 bottom_right(750, 550);
  glm::vec2 board_position(700, 325);
  ballblaster::EnemyBlock enemyBlock(glm::vec2(100, 100));
  std::list<ballblaster::EnemyBlock> enemies;
  enemies.push_back(enemyBlock);

  SECTION("Ball collided with player") {
    glm::vec2 ball_speed(4, 2);
    glm::vec2 ball_position(327, 696);
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.AdvanceOneFrame();
    // negated y
    REQUIRE(engine.GetGameball().GetVelocity().x == 4);
    REQUIRE(engine.GetGameball().GetVelocity().y == -2);
  }

  SECTION("Ball didn't collide with player") {
    glm::vec2 ball_speed(4, 2);
    glm::vec2 ball_position(470, 696);
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.AdvanceOneFrame();
    // negated y
    REQUIRE(engine.GetGameball().GetVelocity().x == 4);
    REQUIRE(engine.GetGameball().GetVelocity().y == 2);
  }
}

TEST_CASE("Ball collide with enemy") {
  glm::vec2 top_left_pixel(100, 100);
  glm::vec2 bottom_right(750, 550);
  glm::vec2 board_position(700, 325);


  SECTION("Ball collide with enemy from left") {
    glm::vec2 ball_speed(-10, -2);
    glm::vec2 ball_position(113, 128);
    ballblaster::EnemyBlock enemyBlock(glm::vec2(150, 130));
    std::list<ballblaster::EnemyBlock> enemies;
    enemies.push_back(enemyBlock);
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.AdvanceOneFrame();
    REQUIRE(engine.GetGameball().GetVelocity().x == 10);
    REQUIRE(engine.GetGameball().GetVelocity().y == -2);

  }

  SECTION("Ball collide with enemy from right") {
    glm::vec2 ball_speed(-10, -2);
    glm::vec2 ball_position(153, 128);
    ballblaster::EnemyBlock enemyBlock(glm::vec2(150, 130));
    std::list<ballblaster::EnemyBlock> enemies;
    enemies.push_back(enemyBlock);
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.AdvanceOneFrame();
    REQUIRE(engine.GetGameball().GetVelocity().x == 10);
    REQUIRE(engine.GetGameball().GetVelocity().y == -2);

  }

  SECTION("Ball collide with enemy from top") {
    glm::vec2 ball_speed(-4, 20);
    glm::vec2 ball_position(144, 90);
    ballblaster::EnemyBlock enemyBlock(glm::vec2(150, 133));
    std::list<ballblaster::EnemyBlock> enemies;
    enemies.push_back(enemyBlock);
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.AdvanceOneFrame();
    REQUIRE(engine.GetGameball().GetVelocity().x == -4);
    REQUIRE(engine.GetGameball().GetVelocity().y == -20);

  }

  SECTION("Ball collide with enemy from bottom") {
    glm::vec2 ball_speed(-4, -20);
    glm::vec2 ball_position(144, 180);
    ballblaster::EnemyBlock enemyBlock(glm::vec2(150, 133));
    std::list<ballblaster::EnemyBlock> enemies;
    enemies.push_back(enemyBlock);
    ballblaster::BallBlasterEngine engine(top_left_pixel, bottom_right,
                                          board_position, ball_speed,
                                          ball_position, enemies);
    engine.AdvanceOneFrame();
    REQUIRE(engine.GetGameball().GetVelocity().x == -4);
    REQUIRE(engine.GetGameball().GetVelocity().y == 20);
  }
}

