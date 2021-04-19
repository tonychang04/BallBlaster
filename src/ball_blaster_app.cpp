#include <ball_blaster_app.h>


namespace ballblaster {
BallBlasterApp::BallBlasterApp()
    : ball_blaster_engine_(kStartPixel, kEndPixel) {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void BallBlasterApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);
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
  }
}
void BallBlasterApp::mouseMove(cinder::app::MouseEvent event) {
}

}  // namespace ballblaster