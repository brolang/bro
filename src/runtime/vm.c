#include "runtime.h"
#include "actor.h"

int eventloop() {
    while(compiler.list != result) {
        frame = set(frame_get());
        init(frame);
    }
}
