#include "runtime.h"
#include "actor.h"
int eventloop() {
  
    while(frame_hasnext()) {
        spawn(frame_get());
        sync();
    }

}
