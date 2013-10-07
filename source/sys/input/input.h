#ifndef __SYS_INPUT_INPUT_H_INCLUDED__
#define __SYS_INPUT_INPUT_H_INCLUDED__

#include "sys/application.h"

namespace sys {
  class Context;

  namespace input {
    class Input {
      public:

        Application &getApplication();

        unsigned int getTime();

      private:
        friend class sys::Context;

        Input(Context &context);
        Input(const Input &other);
        Input &operator=(const Input &other);

        Context &context;

        static Input *instance;
        static void onDisplay();

        static void onClose();

        static void onReshape(int width, int height);

        static void onMouse(int button, int updown, int x, int y);

        static void onMouseWheel(int wheelNumber, int direction, int x, int y);

        static void onMouseMotion(int x, int y);

        static void onSpecialKeyUp(int key, int x, int y);

        static void onKeyUp(unsigned char key, int x, int y);

        static void onSpecialKeyDown(int key, int x, int y);

        static void onKeyDown(unsigned char key, int x, int y);

        static void onIdle();
    };
  };
};

#endif
