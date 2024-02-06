import java.util.*;
import java.io.*;

public class Monitor extends Thread {

    public void run() {
        try {
            Thread.sleep(200);
        } catch (Exception e) {
        }

        Random random = new Random();
        int randId = random.nextInt(9);
        double randCpuLoad = random.nextDouble() * 100;

        ThreadLoad tl = new ThreadLoad();

        tl.add(randId, randCpuLoad);
    }
}
