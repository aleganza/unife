

import java.io.*;

public class ToOutput implements Runnable {

    private Thread thread;
    private PipedInputStream pis;
    public ToOutput(PipedInputStream pipe) {
        this.pis = pipe;
    }

    // re-define start to launch the thread
    public void start() {
        thread = new Thread(this);
        thread.start();
    }

    @Override
    public void run() {
        System.out.println(Thread.currentThread() + " Hello, this is ToOutput");
        try {
            String line = null;
            BufferedReader br = new BufferedReader(new InputStreamReader(pis));
            while ((line = br.readLine()) != null) {
                System.out.println("ToOutput: " + line);
            }
        } 
		catch (IOException e){
			e.printStackTrace();
		}
    }
}
