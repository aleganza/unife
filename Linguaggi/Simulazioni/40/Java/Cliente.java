import java.util.*;

public class Cliente {
    protected String nomeCognome;
    protected List<Noleggio> noleggi;

    public Cliente(String nomeCognome) {
        this.nomeCognome = nomeCognome;
        this.noleggi = new LinkedList<Noleggio>();
    }

    public void addNoleggio(String targa, int giorni, double costo) {
        this.noleggi.add(new Noleggio(targa, giorni, costo));
    }

    public double getCostoTotale() {
        double costoTotale = 0;
        for(Noleggio noleggio : this.noleggi) {
            costoTotale += noleggio.getCostoNoleggio();
        }

        return costoTotale;
    }

    public String toString() {
        return this.nomeCognome + " "+ this.getCostoTotale() + " " + noleggi.size() + " " + noleggi;
    }
}
