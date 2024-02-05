
buffered()
    input()
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String line = null;
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));
            System.out.println("FromInput - Inserire uno o piu' messaggi:");
            while ((line = br.readLine()) != null) {
                bw.write(line);
                bw.newLine();
                bw.flush();
            }
        } 
    output()
        try {
            String line = null;
            BufferedReader br = new BufferedReader(new InputStreamReader(pis));
            while ((line = br.readLine()) != null) {
                System.out.println("ToOutput: " + line);
            }
        }

object()
    input()
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try {
            String line = null;
            ObjectOutputStream oos = new ObjectOutputStream(pos);
            System.out.println("FromInput - Inserire uno o piu' messaggi:");
            while ((line = br.readLine()) != null) {
                Message m = new Message(line);
                oos.writeObject(m);
                oos.flush();
            }
        } 
    output()
        ObjectInputStream ois = null;
        try {
            ois = new ObjectInputStream(pis);
            while (true) {
                Message m = (Message)ois.readObject();
                if (m == null) break; // interrompi il ciclo se non ho letto niente
                System.out.println("ToOutput: " + m.getMess());
            }
        }
    message()
        public class Message implements Serializable {
        
            private String mess;
            public Message(String mess){
                this.mess = mess;
            }
            
            public String getMess(){
                return mess;
            }
            
        }

stream()
    input()
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // il thread deve continuare a leggere dallo standard input
        // per scrivere l'output sul PipedOutputStream
        try {
            String line = null;
            System.out.println("FromInput - Inserire uno o piu' messaggi:");
            while ((line = br.readLine()) != null) {
                System.out.println("From stdin: " + line);
                byte[] bytes = line.getBytes(Charset.forName("UTF-8"));
                pos.write(bytes, 0, bytes.length);
                pos.flush();
            }

    output()
        try {
            byte buffer[] = new byte[1024];
            int nread = 0;
            while ((nread = pis.read(buffer)) > 0) {
                byte message_buffer[] = Arrays.copyOfRange(buffer, 0, nread); 
                String message = new String(message_buffer, Charset.forName("UTF-8"));
                System.out.println(message);
            }
        }    