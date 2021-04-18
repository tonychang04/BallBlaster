#include <ball_blaster_app.h>
#include <glm/vec2.hpp>

namespace ballblaster {
  BallBlasterApp::BallBlasterApp(): ball_blaster_ui_(glm::vec2(100,100), glm::vec2(750,550), BoardPlayer(glm::vec2(300,300))) {
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

}