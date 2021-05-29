#ifndef ACTOR_H
#define ACTOR_H

enum ActorState {
    DONE, PENDING, ERROR
};

struct Actor {
    int identifier;
    enum ActorState state;
};
int spawn(struct Frame frame);
int sync();

#endif
