#include "runtime.h"
#include "../codegen/codegen.h"

int frames = 0;
struct Frame* framePointer;  
int frame_insert(struct Frame frame) {
    if(framePointer ==  NULL)
        framePointer = &frame;
    else {
        while(framePointer->next != NULL) {
            framePointer = framePointer->next;
        }
        framePointer->next = &frame;
    }
    ++frames;
}

int frame_hasnext() {
    if(frames != 0)
        return 0;
    else
        return 1;
}

struct Frame frame_get() {
    if(framePointer == NULL)
        printf("no frames");
    else {
        struct Frame* temp = framePointer;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        return *temp;
    }
}

int execute_expression(struct CodegenExpression block) {
   struct Frame frame;

}

int execute_block(struct CodegenBlock block) {

}