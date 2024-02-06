
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {

        PipedInputStream pis = new PipedInputStream();

        try {
            PipedOutputStream pos = new PipedOutputStream(pis);

            MacchinaA a = new MacchinaA(pos);
            Thread ta = new Thread(a);

            MacchinaB b = new MacchinaB(pis);
            Thread tb = new Thread(b);

            ta.start();
            tb.start();

            try {
                Thread.sleep(2000);
            } catch (Exception e) {
            }

            a.stop();
            b.stop();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
