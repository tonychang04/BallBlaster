
#include <ball_blaster_engine.h>

using glm::vec2;
namespace ballblaster {
BallBlasterEngine::BallBlasterEngine(const glm::vec2 start_pixel,
                             const glm::vec2 end_pixel) : player_board_(glm::vec2(700,325)) {
  start_pixel_ = start_pixel;
  end_pixel_ = end_pixel;
}
void BallBlasterEngine::Display() const {
  ci::gl::color(ci::Color("white"));
  ci::gl::drawStrokedRect(ci::Rectf(vec2(start_pixel_.y, start_pixel_.x),
                                    vec2(end_pixel_.y, end_pixel_.x)), 5);
  player_board_.draw();
}

void BallBlasterEngine::AdvanceOneFrame() {
  game_ball_.SetPosition(game_ball_.GetPosition() + game_ball_.GetVelocity());
}
void BallBlasterEngine::MovePlayer(int distance) {
  player_board_.move(distance);
}
}  // namespace ballblaster