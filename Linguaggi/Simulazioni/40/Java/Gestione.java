import java.io.*;
import java.util.*;

public class Gestione {

    static List<Veicolo> veicoli = new LinkedList<Veicolo>();
    static List<Cliente> clienti = new LinkedList<Cliente>();

    static Map<Integer, String> codiceTarga = new HashMap<Integer, String>();
    static Map<Integer, Double> codiceCosto = new HashMap<Integer, Double>();
    static Map<Integer, Double> codiceCostoTot = new HashMap<Integer, Double>();

    public static void main(String[] args) {

        try {
            BufferedReader br = new BufferedReader(new FileReader("veicoli.txt"));
            String line = br.readLine();

            while (line != null) {
                StringTokenizer tok = new StringTokenizer(line);
                int codice = Integer.parseInt(tok.nextToken());
                String tipo = tok.nextToken();
                String targa = tok.nextToken();

                line = br.readLine();
                String modello = line;

                line = br.readLine();
                String marca = line;

                line = br.readLine();
                double costo = 0;
                if (tipo.equals("auto")) {
                    tok = new StringTokenizer(line);
                    int cilindrata = Integer.parseInt(tok.nextToken());
                    double capienza = Double.parseDouble(tok.nextToken());
                    costo = Double.parseDouble(br.readLine());

                    Auto auto = new Auto(codice, targa, modello, marca, costo, cilindrata, capienza);
                    veicoli.add(auto);
                } else if (tipo.equals("furgone")) {
                    String categoria = line;

                    line = br.readLine();
                    tok = new StringTokenizer(line);
                    int posti = Integer.parseInt(tok.nextToken());
                    boolean vano = Boolean.parseBoolean(tok.nextToken());
                    costo = Double.parseDouble(br.readLine());

                    Furgone furgone = new Furgone(codice, targa, modello, marca, costo, categoria, posti, vano);
                    veicoli.add(furgone);
                }

                codiceTarga.put(codice, targa);
                codiceCosto.put(codice, costo);
                codiceCostoTot.put(codice, 0.0);

                line = br.readLine();
            }
            br.close();

        } catch (IOException e) {
            System.err.println(e);
        } catch (Exception e) {
            System.err.println(e);
        }

        try {
            BufferedReader br = new BufferedReader(new FileReader("clienti.txt"));
            String line = br.readLine();

            while (line != null) {
                String nomeCognome = line;

                Cliente cliente = new Cliente(nomeCognome);

                line = br.readLine();
                StringTokenizer tok = new StringTokenizer(line);
                while (tok.hasMoreElements()) {
                    int codice = Integer.parseInt(tok.nextToken());
                    String targa = codiceTarga.get(codice);
                    double costo = codiceCosto.get(codice);

                    int giorni = Integer.parseInt(tok.nextToken());

                    codiceCostoTot.put(codice, codiceCostoTot.get(codice) + costo * giorni);

                    cliente.addNoleggio(targa, giorni, costo);
                }
                clienti.add(cliente);
                line = br.readLine();
            }
            br.close();

        } catch (IOException e) {
            System.err.println(e);
        } catch (Exception e) {
            System.err.println(e);
        }

        System.out.println(
                "tipo, targa, codice, modello, marca, costo giornaliero, cilindrata, bagagliaio, categoria, numero di posti, vano di carico");
        for (Veicolo veicolo : veicoli) {
            System.out.println(veicolo);
        }

        System.out.println("");
        for (Cliente cliente : clienti) {
            System.out.println(cliente);
        }
        
        System.out.println("");
        System.out.println(args[0] + " " + codiceCostoTot.get(Integer.parseInt(args[0])));
    }
}
