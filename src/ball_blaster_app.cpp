#include <ball_blaster_app.h>
namespace ballblaster {
  BallBlasterApp::BallBlasterApp() {
    ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void BallBlasterApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);
}

void BallBlasterApp::update() {
}
void BallBlasterApp::keyDown(cinder::app::KeyEvent event) {
}
void BallBlasterApp::mouseMove(cinder::app::MouseEvent event) {
}

}