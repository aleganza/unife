public class CounterDec {
    Counter c;

    public CounterDec() {
        c = new Counter();
    }

    public int dec() {
        int val = c.getValue();
        return val--;
    }
}