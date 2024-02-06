
import java.util.*;
import java.io.*;

public class ThreadLoad {

    private Map<Integer, Double> data;

    public ThreadLoad() {
        this.data = new HashMap<Integer, Double>();
    }

    public synchronized void add(int id, double cpuLoad) {
        this.data.put(id, cpuLoad);
    }

    public synchronized int getMaxCpuLoad() {
        int maxId = -1;
        double maxCpuLoad = 0.0;

        for (Map.Entry<Integer, Double> element : this.data.entrySet()) {
            if (element.getValue() > maxCpuLoad) {
                maxCpuLoad = element.getValue();
                maxId = element.getKey();
            }
        }

        return maxId;
    }

    public synchronized double getCpuLoad(int id) {
        return this.data.get(id);
    }
}
