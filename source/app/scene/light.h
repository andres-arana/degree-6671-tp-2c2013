#ifndef __APP_SCENE_LIGHT_H_INCLUDED__
#define __APP_SCENE_LIGHT_H_INCLUDED__

#include "app/geometries/register.h"
#include "app/shaders/register.h"
#include <glm/glm.hpp> 

namespace app {
  namespace scene {
    class Light {
      public:
        Light(const app::geometries::Register &geometries,
            const app::shaders::Register &shaders);

        void use(
            const glm::mat4 &viewMatrix,
            const glm::mat4 &modelMatrix);

      private:
        const app::geometries::Register &geometries;
        const app::shaders::DiffuseShader &shader;
    };
  };
};

#endif
