#include <ball_blaster_app.h>

namespace ballblaster {
BallBlasterApp::BallBlasterApp()
    : ball_blaster_engine_(glm::vec2(100, 100), glm::vec2(750, 550), 5) {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
  isStarted_ = false;
}

void BallBlasterApp::setup() {
  texture = ci::gl::Texture2d::create(ci::loadImage(kBackgroundFilePath));
  cinder::audio::SourceFileRef sourceFile =
      ci::audio::load(cinder::loadFile(kSoundFilePath));
  music = ci::audio::Voice::create(sourceFile);
  // music->start();
}
void BallBlasterApp::draw() {
  ci::gl::color(kTextureColor);
  ci::gl::draw(texture);
  ball_blaster_engine_.Display();
  if (!isStarted_) {
    ci::gl::drawString("Press s to start game", glm::vec2(100, 50),
                       ci::Color("white"), ci::Font("Impact", 35));
  }
}

void BallBlasterApp::update() {
  if (isStarted_) {
    ball_blaster_engine_.AdvanceOneFrame();
  }
}

void BallBlasterApp::keyDown(cinder::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_RIGHT:
      ball_blaster_engine_.MovePlayer(kMovePixel);
      break;
    case ci::app::KeyEvent::KEY_LEFT:
      ball_blaster_engine_.MovePlayer(-kMovePixel);
      break;
    case ci::app::KeyEvent::KEY_r:
      ball_blaster_engine_.Restart();
      music->stop();
      music->start();
      break;
    case ci::app::KeyEvent::KEY_s:
      isStarted_ = true;
      break;
  }
}

}  // namespace ballblaster