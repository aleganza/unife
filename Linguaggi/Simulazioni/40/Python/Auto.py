
from Veicolo import Veicolo

class Auto(Veicolo):
    
    def __init__(self, codice, targa, modello, marca, costo, cilindrata, capienza):
        super().__init__(codice, targa, modello, marca, costo)
        self.cilindrata = cilindrata
        self.capienza = capienza
        
    def __str__(self):
        return "automobile" + "\t" + super().__str__() + str(self.cilindrata)+"\t"+str(self.capienza) + "\t-\t-\t-"
        