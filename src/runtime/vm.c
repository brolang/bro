#include "runtime.h"

struct Frame {
    struct Call call;
    struct Frame* next;
};

struct Frame root;

int eventloop() {
  
    while(!isDone()) {

    }

}
