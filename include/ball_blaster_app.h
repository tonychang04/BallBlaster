#pragma once

#include "ball_blaster_engine.h"
#include "cinder/audio/Voice.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace ballblaster {

/**
 * Class for the app of the game.
 */
class BallBlasterApp:public ci::app::App{
 public:
  BallBlasterApp();

  /**
   * Draw the figure of the visualization.
   */
  void draw() override;

  /**
   * Update the frame of the visualization.
   */
  void update() override;

  /**
   * Detects the user key button input.
   * @param event the input of the user
   */
  void keyDown(cinder::app::KeyEvent event) override;

  /**
   * Set up that is called once before the start of the game
   */
  void setup() override;




private:

  const std::string kBackgroundFilePath = "assets/background.jpg";
  const std::string kSoundFilePath = "assets/music.mp3";

  BallBlasterEngine ball_blaster_engine_;
  bool isStarted_;

  ci::audio::VoiceRef music;
  const cinder::ColorT<float> kTextureColor  = "blue";
  ci::gl::Texture2dRef texture;

  const size_t kMovePixel = 8;
  const size_t kWindowSize = 775;
};
};
