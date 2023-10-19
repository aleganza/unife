public class Counter {
    int val;
    public Counter() {
        val = 0;
    }

    public int getValue() {http://www.gnome-look.org/
        return val;
    }

    public void reset() {
        val = 0;
    }

    public int inc() {
        return val++;
    }

}