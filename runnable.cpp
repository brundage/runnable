#include "runnable.h"

Runnable::Runnable() {
  nextRunnable = headRunnable;
  headRunnable = this;
  start();
}


static void Runnable::setupAll() {
  for( Runnable *r = headRunnable; r; r = r->nextRunnable ) {
    r->setup();
  }
}


static void Runnable::runAll() {
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
