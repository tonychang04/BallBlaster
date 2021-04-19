#include <ball_blaster_app.h>


namespace ballblaster {
BallBlasterApp::BallBlasterApp()
    : ball_blaster_engine_(glm::vec2(100, 100), glm::vec2(750, 550)) {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void BallBlasterApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);
  ball_blaster_engine_.Display();
}

void BallBlasterApp::update() {
}

void BallBlasterApp::keyDown(cinder::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_RIGHT:
      ball_blaster_engine_.MovePlayer(kMovePixel);

      break;
    case ci::app::KeyEvent::KEY_LEFT:
      ball_blaster_engine_.MovePlayer(-kMovePixel);
      std::cout << "l";
      break;
  }
}
void BallBlasterApp::mouseMove(cinder::app::MouseEvent event) {
}

}  // namespace ballblaster