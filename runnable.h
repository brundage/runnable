#ifndef RUNNABLE_H
#define RUNNABLE_H

class Runnable {

  public:
    static void runAll();
    static void setupAll();

    Runnable();
    bool isRunning();
    void start();
    void stop();

  private:
    static Runnable *headRunnable;
    Runnable *nextRunnable;

    virtual void run() = 0;
    virtual void setup() = 0;

    bool running;

};

#endif
