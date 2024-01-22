
from Veicolo import Veicolo

class Furgone(Veicolo):
    
    def __init__(self, codice, targa, modello, marca, costo, categoria, posti, vano):
        super().__init__(codice, targa, modello, marca, costo)
        self.categoria = categoria
        self.posti = posti
        self.vano = vano
        
    def __str__(self):
        return "commerciale\t"+super().__str__() + "-\t-\t-\t"  +str(self.categoria)+"\t" +str(self.posti) +"\t"+str(self.vano)
        