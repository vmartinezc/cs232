RAM_SIZE = 1024


class RAM:
    def __init__(self, size=RAM_SIZE):
        self._minAddr = 0
        self._maxAddr = RAM_SIZE - 1
        self._memory = []   # a list of values.  Could be #s or instructions.
        for i in range(size):
            self._memory.append(0)

    def __getitem__(self, addr):
        return self._memory[addr]

    def __setitem__(self, addr, val):
        self._memory[addr] = val

    def is_legal_addr(self, addr):
        return self._minAddr <= addr <= self._maxAddr

class MMU:
    def __init__(self, ram):
        self.ram = ram
        self.reloc = 0
        self.limit = 0
        
    def get_ram_value(self, addr):
        return self.ram.__getitem__(addr)
    
    def set_ram_value(self, addr, value):
        return self.ram.__setitem__(addr,value)
    
    
    
    
    
        
