#include <ball_blaster_app.h>


namespace ballblaster {
BallBlasterApp::BallBlasterApp()
    : ball_blaster_ui_(glm::vec2(100, 100), glm::vec2(750, 550)) {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void BallBlasterApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);
  ball_blaster_ui_.Display();
}

void BallBlasterApp::update() {
}
void BallBlasterApp::keyDown(cinder::app::KeyEvent event) {
}
void BallBlasterApp::mouseMove(cinder::app::MouseEvent event) {
}

}  // namespace ballblaster