import java.io.*;

public class Message implements Serializable {

    private String msg;
    public Message(String m) {
        this.msg = m;
    }

    public String getMessage() {
        return this.msg;
    }

}
