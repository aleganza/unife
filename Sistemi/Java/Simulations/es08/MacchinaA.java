
import java.util.*;
import java.io.*;
import java.nio.*;
import java.nio.charset.Charset;

public class MacchinaA implements Runnable {

    private PipedOutputStream pos;

    public MacchinaA(PipedOutputStream pipe) {
        this.pos = pipe;
    }

    public void run() {
        System.out.println("ciaoa");

        while (true) {
            System.out.println("Inserire materia prima");
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            // buffered
            // try {
            // String line;
            // BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));

            // while((line = br.readLine()) != null) {
            // bw.write(line);
            // bw.newLine();
            // bw.flush();
            // }
            // } catch (Exception e) {
            // e.printStackTrace();
            // }

            // object
            // try {
            // ObjectOutputStream oos = new ObjectOutputStream(pos);
            // String line;
            // while((line = br.readLine()) != null) {
            // Message msg = new Message(line);
            // oos.writeObject(msg);
            // oos.flush();
            // }

            // } catch (Exception e) {
            // e.printStackTrace();
            // }

            // stream
            try {
                String line;
                while ((line = br.readLine()) != null) {
                    // byte[] bytes = line.getBytes(Charset.forName("UTF-8"));
                    byte[] bytes = line.getBytes("UTF-8");
                    pos.write(bytes, 0, bytes.length);
                    pos.flush();
                    
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public void stop() {
        Thread.currentThread().interrupt();
    }
}
