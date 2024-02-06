import java.util.*;
import java.io.*;

public class Magazzino {

    private Map<String, Integer> oggetti;

    public Magazzino() {
        this.oggetti = new HashMap<String, Integer>();
    }

    public synchronized boolean doesOggettoExist(String oggetto) {
        try {
            Thread.sleep(500);
        } catch (Exception e) {
        }

        return this.oggetti.containsKey(oggetto);
    }

    public synchronized void createOggetto(String oggetto) {
        try {
            Thread.sleep(500);
        } catch (Exception e) {
        }

        this.oggetti.put(oggetto, 0);
    }

    public synchronized void addQuantity(String oggetto, int value) {
        try {
            Thread.sleep(500);
        } catch (Exception e) {
        }

        this.oggetti.put(oggetto, this.oggetti.get(oggetto) + value);
    }

    public synchronized void removeQuantity(String oggetto, int value) {
        try {
            Thread.sleep(500);
        } catch (Exception e) {
        }

        this.oggetti.put(oggetto, this.oggetti.get(oggetto) - value);
    }

    public String toString() {
        String result = "";
        for (Map.Entry<String, Integer> element : this.oggetti.entrySet()) {
            result += element.getKey() + " " + element.getValue() + "\n";
        }

        return result;
    }
}
