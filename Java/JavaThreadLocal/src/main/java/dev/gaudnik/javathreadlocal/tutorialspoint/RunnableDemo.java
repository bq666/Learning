package dev.gaudnik.javathreadlocal.tutorialspoint;

class RunnableDemo implements Runnable {

    private Thread thread;
    private String threadName;

    RunnableDemo(String threadName) {
        this.threadName = threadName;
    }

    @Override
    public void run() {
        System.out.println("Running " + threadName);
        try {
            for (int i = 0; i < 4; i++) {
                System.out.println("Thread: " + threadName + ", " + i);
                Thread.sleep(50);
            }
        } catch (InterruptedException e){
            System.out.println("Thread " + threadName + " interrupted.");
        }
        System.out.println("Thread " + threadName + " exiting.");
    }

   public void start() {
       System.out.println("Starting " + threadName);
       if (thread == null) {
           thread = new Thread(this, threadName);
           thread.start();
       }
   }

    public static void main(String[] args) {
        var R1 = new RunnableDemo("Thread-1");
        R1.start();
        var R2 = new RunnableDemo("Thread-2");
        R2.start();
    }
}
