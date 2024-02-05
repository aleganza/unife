

import java.io.*;

public class FromInput implements Runnable {

    private Thread thread;
    private PipedOutputStream pos;

    public FromInput(PipedOutputStream pipe) {
        this.pos = pipe;
    }

    public void start() {
        thread = new Thread(this);
        thread.start();
    }

    @Override
    public void run() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line = null;
        try {
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(this.pos));
            System.out.println("FromInput - Inserire uno o piu' messaggi:");

            line = br.readLine();
            while (line != null) {
                bw.write(line);
                bw.newLine();
                bw.flush();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
