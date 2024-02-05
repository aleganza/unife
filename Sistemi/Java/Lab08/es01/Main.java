
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {

        if (args.length == 0) {
            System.out.println("Uso: java Main.java <N>");
            System.exit(1);
        }

        int N = 0;

        try {
            N = Integer.parseInt(args[0]);

        } catch (Exception e) {
            System.out.println("N non è un intero");
            e.printStackTrace();
        }

        WorkerThread wt[] = new WorkerThread[N];
        boolean running[] = new boolean[N];

        for(int i=0; i<N; i++) {
            wt[i] = new WorkerThread(i);
            Thread thread = new Thread(wt[i]);
            thread.start();
            running[i] = true;
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(checkRunningThreads(running) > 0) {
            System.out.println("Inserire id thread da terminare");

            try {
                int id = Integer.parseInt(br.readLine());

                if(running[id]) {
                    System.out.println("Il thread sta runnando, stoppo.");
                    wt[id].stop();
                    running[id] = false;
                    
                } else {
                    System.out.println("Il thread non sta runnando");
                }

            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    
    }

    public static int checkRunningThreads(boolean running[]) {
        int runningElements = 0;

        for (boolean runs : running)
            if (runs)
                runningElements++;

        return runningElements;
    }
}
