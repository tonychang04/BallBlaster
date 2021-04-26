#include <ball_blaster_app.h>


namespace ballblaster {
BallBlasterApp::BallBlasterApp()
    : ball_blaster_engine_(glm::vec2(100, 100), glm::vec2(750, 550), 8) {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void BallBlasterApp::setup() {

  texture = ci::gl::Texture2d::create(ci::loadImage(kBackgroundFilePath));
}
void BallBlasterApp::draw() {
  ci::gl::color(ci::Color("blue"));
  ci::gl::draw(texture);
  ball_blaster_engine_.Display();
}

void BallBlasterApp::update() {
  ball_blaster_engine_.AdvanceOneFrame();
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
      break;
  }
}


}  // namespace ballblaster