
#include <ball_blaster_engine.h>

#include "cinder/Rand.h"

using glm::vec2;
namespace ballblaster {
BallBlasterEngine::BallBlasterEngine(const glm::vec2& top_left_pixel,
                                     const glm::vec2& bottom_right_pixel,
                                     int ball_speed)
    : player_board_(glm::vec2(700, 325)),
      game_ball_(glm::vec2(300, 300),
                 glm::vec2(ci::randFloat(-ball_speed, ball_speed),
                           ci::randFloat(-ball_speed, 0))) {
  frame_count_ = 0;
  top_left_pixel_ = top_left_pixel;
  bottom_right_pixel_ = bottom_right_pixel;
}
void BallBlasterEngine::Display() const {
  ci::gl::color(ci::Color("white"));
  ci::gl::drawStrokedRect(
      ci::Rectf(vec2(top_left_pixel_.y, top_left_pixel_.x),
                vec2(bottom_right_pixel_.y, bottom_right_pixel_.x)),
      kBorderLength);

  if (!enemies_.empty()) {
    for (const EnemyBlock& enemyBlock : enemies_) {
      enemyBlock.Draw();
    }
  }
  game_ball_.Draw();
  player_board_.Draw();
}

void BallBlasterEngine::AdvanceOneFrame() {
  ++frame_count_;
  if (game_ball_.IsSurviving()) {
    if (!enemies_.empty()) {
      for (EnemyBlock& enemyBlock : enemies_) {
        enemyBlock.MoveOneFrame();
      }
    }
    if (frame_count_ == kSpawnEnemyFrame) {
      enemies_.push_back(glm::vec2(
          top_left_pixel_.x + EnemyBlock::kLength,
          ci::randFloat(
              top_left_pixel_.y + EnemyBlock::kWidth + kBorderLength,
              bottom_right_pixel_.y - EnemyBlock::kWidth - kBorderLength)));
      frame_count_ = 0;
    }

    game_ball_.ProcessCollidePlayer(player_board_);
    game_ball_.ProcessCollideWall(top_left_pixel_, bottom_right_pixel_,
                                  kBorderLength);
    game_ball_.SetPosition(
        glm::vec2(game_ball_.GetPosition().x + game_ball_.GetVelocity().x,
                  game_ball_.GetPosition().y + game_ball_.GetVelocity().y));
  } else {
    // end the game
  }
}
void BallBlasterEngine::MovePlayer(int distance) {
  player_board_.move(distance);
}
}  // namespace ballblaster