
// import java.util.*;
import java.io.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class WorkerThread implements Runnable {

    final static AtomicBoolean running = new AtomicBoolean(false);

    private int id;

    public WorkerThread(int i) {
        this.id = i;
    }

    public void stop() {
        running.set(false);
    }

    public void run() {
        try {
            running.set(true);
            while(running.get()) {
                System.out.println(id);
                
                Thread.sleep(1000);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
