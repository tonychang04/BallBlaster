#include <ball_blaster_app.h>

using ballblaster::BallBlasterApp;

void prepareSettings(BallBlasterApp::Settings* settings) {
  settings->setResizable(false);
}

CINDER_APP(BallBlasterApp, ci::app::RendererGl, prepareSettings);