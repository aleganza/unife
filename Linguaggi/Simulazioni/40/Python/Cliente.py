
from Noleggio import Noleggio

class Cliente:
    
    def __init__(self, nomeCognome):
        self.nomeCognome = nomeCognome
        self.noleggi = []
        
    def addNoleggio(self, i):
        self.noleggi.append(i)
        
    def __str__(self):
        return self.nomeCognome + " " + str(len(self.noleggi)) + " ".join([str(v) for v in self.noleggi])

    
    