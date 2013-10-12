#ifndef __SCENE_FPS_CAMERA_H_INCLUDED__
#define __SCENE_FPS_CAMERA_H_INCLUDED__

#include "scene/camera.h"

namespace scene {
  class FPSCamera : public Camera {
    public:
      FPSCamera(
          sys::Window &window,
          sys::Input &input,
          const glm::vec3 &position,
          const shaders::Cache &shaders);

      virtual void doMouseMove(int deltaX, int deltaY);

      virtual void doKeyUp(unsigned char key);

      virtual void doKeyDown(unsigned char key);

      virtual void tick(float delta);

      virtual glm::mat4 getViewMatrix();

    private:
      glm::vec3 position;
      float rho;
      float theta;

      bool forwards;
      bool backwards;
      bool left;
      bool right;
      bool up;
      bool down;
  };
};

#endif