
class Noleggio:
    
    def __init__(self, targa, giorni):
        self.targa = targa
        self.giorni = giorni
        
    def __str__(self):
        return "(" + str(self.targa) + str(self.giorni) + ")"
