#pragma once

#include "cinder/gl/gl.h"

namespace ballblaster {
  class BoardPlayer {
   public:
    BoardPlayer(const glm::vec2& center);

    void draw() const;

   private:
    glm::vec2 center_;

    // the length and width below represents the length and width from the
    // center to the side
    const size_t kLength = 5;
    const size_t kWidth = 30;
  };


}