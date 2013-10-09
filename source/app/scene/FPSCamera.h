#ifndef __APP_SCENE_FPS_CAMERA_H_INCLUDED__
#define __APP_SCENE_FPS_CAMERA_H_INCLUDED__

#include "app/shaders/register.h"
#include "app/scene/camera.h"
#include <glm/glm.hpp> 

namespace app {
  namespace scene {
    class FPSCamera : public Camera {
      public:
        FPSCamera(
            sys::Window &window,
            sys::Input &input,
            const glm::vec3 &position,
            const app::shaders::Register &shaders);

        virtual void doMouseMove(int deltaX, int deltaY);

        virtual void doKeyUp(unsigned char key);

        virtual void doKeyDown(unsigned char key);

        virtual void tick(float delta);

        virtual void use();

      private:
        const app::shaders::Register &shaders;
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
};

#endif
