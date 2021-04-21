#pragma once

#include "cinder/gl/gl.h"

namespace ballblaster {
/**
 * The board of the player. Responsible for the drawing and the moving
 */
  class BoardPlayer {
   public:
    BoardPlayer(const glm::vec2& center);

    /**
     * Draw the player board.
     */
    void Draw() const;

    /**
     * Move the player board based on given distance
     * @param distance the distance that the board needs to move
     */
    void move(int distance);

    size_t GetLength() const;

    size_t GetWidth() const;

    const glm::vec2& GetCenter() const;

   private:
    const cinder::ColorT<float> kColor  = "gray";
    glm::vec2 center_;

    // the length and width below represents the length and width from the
    // center to the side
    const size_t kLength = 5;
    const size_t kWidth = 50;
  };


}