
#include <ball_blaster_engine.h>

using glm::vec2;
namespace ballblaster {
BallBlasterEngine::BallBlasterEngine(const glm::vec2& start_pixel,
                                     const glm::vec2& end_pixel)
    : player_board_(glm::vec2(700, 325)), game_ball_(glm::vec2(300,300),glm::vec2(3,3)) {
  start_pixel_ = start_pixel;
  end_pixel_ = end_pixel;
}
void BallBlasterEngine::Display() const {

  ci::gl::color(ci::Color("white"));
  ci::gl::drawStrokedRect(ci::Rectf(vec2(start_pixel_.y, start_pixel_.x),
                                    vec2(end_pixel_.y, end_pixel_.x)),
                          kBorderLength);
  player_board_.Draw();
  game_ball_.Draw();

}

void BallBlasterEngine::AdvanceOneFrame() {
  game_ball_.ProcessCollideWall(start_pixel_, end_pixel_, kBorderLength);
  game_ball_.SetPosition(glm::vec2(game_ball_.GetPosition().x + game_ball_.GetVelocity().x,
                                   game_ball_.GetPosition().y + game_ball_.GetVelocity().y));
}
void BallBlasterEngine::MovePlayer(int distance) {
  player_board_.move(distance);
}
}  // namespace ballblaster