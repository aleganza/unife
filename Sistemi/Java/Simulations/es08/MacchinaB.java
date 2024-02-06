
import java.util.*;
import java.io.*;
import java.nio.*;
import java.nio.charset.Charset;

public class MacchinaB implements Runnable {

    private PipedInputStream pis;

    public MacchinaB(PipedInputStream pipe) {
        this.pis = pipe;
    }

    public void run() {
        System.out.println("ciaob");

        // buffered
        // BufferedReader br = new BufferedReader(new InputStreamReader(pis));
        // try {
        // String line;
        // while((line = br.readLine()) != null) {
        // System.out.println("Semilavorato: " + line);
        // }

        // } catch (Exception e) {
        // e.printStackTrace();
        // }

        // object
        // try {
        // ObjectInputStream ois = new ObjectInputStream(pis);

        // while(true) {
        // Message msg = (Message)ois.readObject();
        // System.out.println("Semilavorato: " + msg.getMessage());
        // }

        // } catch (Exception e) {
        // e.printStackTrace();
        // }

        // stream
        byte buffer[] = new byte[1024];
        int nread = 0;
        try {
            while ((nread = pis.read(buffer)) > 0) {
                byte message_buffer[] = Arrays.copyOfRange(buffer, 0, nread); 
                String message = new String(message_buffer, Charset.forName("UTF-8"));
                System.out.println(message);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public void stop() {
        Thread.currentThread().interrupt();
    }
}
