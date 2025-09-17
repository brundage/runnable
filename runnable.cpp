#include "runnable.h"

Runnable::Runnable() : running(true) {
  nextRunnable = headRunnable;
  headRunnable = this;
}


void Runnable::setupAll() {
  for( Runnable *r = headRunnable; r; r = r->nextRunnable ) {
    r->setup();
  }
}


void Runnable::runAll() {
  for( Runnable *r = headRunnable; r; r = r->nextRunnable ) {
    if( r->isRunning() ) {
      r->run();
    }
  }
}


bool Runnable::isRunning() { return running;  }
void Runnable::start() { running = true;  }
void Runnable::stop() { running = false;  }


Runnable *Runnable::headRunnable = nullptr;
