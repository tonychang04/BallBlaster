#include <ball_blaster_engine.h>

#include "cinder/Rand.h"

using glm::vec2;
namespace ballblaster {
BallBlasterEngine::BallBlasterEngine(const glm::vec2& top_left_pixel,
                                     const glm::vec2& bottom_right_pixel,
                                     int ball_speed)
    : player_board_(glm::vec2(700, 325)),
      game_ball_(
          glm::vec2(300, 300),
          glm::vec2(ci::randFloat(-ball_speed, ball_speed), -ball_speed)) {
  initial_player_pos_ = player_board_.GetCenter();
  initial_ball_pos_ = game_ball_.GetPosition();
  initial_ball_speed = ball_speed;
  player_score_ = 0;
  high_score_ = 0;
  frame_count_ = 0;
  top_left_pixel_ = top_left_pixel;
  bottom_right_pixel_ = bottom_right_pixel;
}

BallBlasterEngine::BallBlasterEngine(const glm::vec2& top_left,
                                     const glm::vec2& bottom_right,
                                     const glm::vec2& board_position,
                                     const glm::vec2& ball_speed,
                                     const glm::vec2& ball_position,
                                     const std::list<EnemyBlock>& enemies)
    : player_board_(board_position), game_ball_(ball_position, ball_speed) {
  initial_player_pos_ = board_position;
  initial_ball_pos_ = ball_position;
  initial_ball_speed = ball_speed.x;
  top_left_pixel_ = top_left;
  bottom_right_pixel_ = bottom_right;
  frame_count_ = 0;
  player_score_ = 0;
  for (const EnemyBlock& enemy : enemies) {
    enemies_.push_back(enemy);
  }
}
void BallBlasterEngine::Display() const {
  // the game loses then display the end message
  if (!game_ball_.IsSurviving()) {
    ci::gl::drawString(kEndScreenMessage, kEndScreenPosition,
                       kEndMessageColor, kEndScreenFont);
  }
  ci::gl::color(kContainerColor);
  ci::gl::drawStrokedRect(
      ci::Rectf(vec2(top_left_pixel_.y, top_left_pixel_.x),
                vec2(bottom_right_pixel_.y, bottom_right_pixel_.x)),
      kBorderLength);

  // write out the score and highest score
  ci::gl::drawString(kScoreMessage + std::to_string(player_score_),
                     kScoreLocation, kScoreMessageColor, kScoreFont);
  ci::gl::drawString(kHighScoreMessage + std::to_string(high_score_),
                     kHighScoreLocation, kHighScoreMessageColor, kHighScoreScoreFont);

  // if enemies is not empty then draw the enemies
  if (!enemies_.empty()) {
    for (const EnemyBlock& enemyBlock : enemies_) {
      enemyBlock.Draw();
    }
  }
  //draw the player board and the game ball
  game_ball_.Draw();
  player_board_.Draw();
}

void BallBlasterEngine::AdvanceOneFrame() {
  ++frame_count_;
  // if the player is still surviving
  if (game_ball_.IsSurviving()) {
    // if there is enemy
    if (!enemies_.empty()) {
      // loop through the enemy
      std::list<EnemyBlock>::iterator enemy_iterator;
      for (enemy_iterator = enemies_.begin(); enemy_iterator != enemies_.end();
           ++enemy_iterator) {
        enemy_iterator->MoveOneUpdate();
        if (enemy_iterator->GetCenter().x + enemy_iterator->kLength +
                kBorderLength >
            bottom_right_pixel_.x) {
          // let the enemy block disappear
          enemies_.erase(enemy_iterator);
        }
      }
    }
    if (frame_count_ == kSpawnEnemyFrame) {
      enemies_.push_back(glm::vec2(
          top_left_pixel_.x + EnemyBlock::kLength + kBorderLength,
          ci::randFloat(
              top_left_pixel_.y + EnemyBlock::kWidth + kBorderLength,
              bottom_right_pixel_.y - EnemyBlock::kWidth - kBorderLength)));
      frame_count_ = 0;
      ++player_score_;
    }

    // store a temporary current_enemies variable
    size_t current_enemies = enemies_.size();
    game_ball_.ProcessCollideEnemy(enemies_);
    // if the enemy size changes after process collide enemy,
    // then add the player score because that means
    // the ball collided with enemy
    if (current_enemies != enemies_.size()) {
      ++player_score_;
    }

    // if board collided enemy, then the game lses
    if (player_board_.HasCollideEnemy(enemies_)) {
      game_ball_.SetSurviving(false);
    }

    game_ball_.ProcessCollidePlayer(player_board_);
    game_ball_.ProcessCollideWall(top_left_pixel_, bottom_right_pixel_,
                                  kBorderLength);
    game_ball_.SetPosition(
        glm::vec2(game_ball_.GetPosition().x + game_ball_.GetVelocity().x,
                  game_ball_.GetPosition().y + game_ball_.GetVelocity().y));
  } else {
    // if the player loses, then check the score against the highest score
    if (player_score_ > high_score_) {
      high_score_ = player_score_;
    }
  }
}
void BallBlasterEngine::MovePlayer(int distance) {
  // can only move player when game is still going on
  if (game_ball_.IsSurviving()) {
    // if player didn't reach out of the container
    if (!(player_board_.GetCenter().y + player_board_.GetWidth() + distance +
                  kBorderLength >
              bottom_right_pixel_.y &&
          distance > 0) &&
        (!(player_board_.GetCenter().y - player_board_.GetWidth() + distance -
                   kBorderLength <
               top_left_pixel_.y &&
           distance < 0))) {
      player_board_.move(distance);
    }
  }
}

void BallBlasterEngine::Restart() {
  game_ball_.SetPosition(initial_ball_pos_);
  player_board_.SetCenter(initial_player_pos_);
  game_ball_.SetVelocity(
      glm::vec2(ci::randFloat(-initial_ball_speed, initial_ball_speed),
                -initial_ball_speed));
  enemies_.clear();
  game_ball_.SetSurviving(true);
  frame_count_ = 0;
  player_score_ = 0;
}

const GameBall& BallBlasterEngine::GetGameball() const {
  return game_ball_;
}

const BoardPlayer& BallBlasterEngine::GetBoard() const {
  return player_board_;
}

const std::list<EnemyBlock>& BallBlasterEngine::GetEnemies() const {
  return enemies_;
}

const size_t& BallBlasterEngine::GetScore() const {
  return player_score_;
}
}  // namespace ballblaster