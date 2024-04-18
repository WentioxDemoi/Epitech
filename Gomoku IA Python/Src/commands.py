import sys
from .ia import Ia

ia = Ia()

class Commands:

    _tab = [[]]
    _size = 0
    _enemy_x = 0
    _enemy_y = 0
    _x = 0
    _y = 0

    def printTab(self):
        for row in self._tab:
            print(row)

    def boardUpdateBrain(self):
        self._tab[self._x][self._y] = 1
        print(f"{self._x},{self._y}")
    
    def boardUpdateBrainTmp(self):
         self._tab[self._x][self._y] = 1

    def boardUpdateEnemyTmp(self):
        self._tab[self._enemy_x][self._enemy_y] = 2
    
    def boardUpdateEnemy(self):
        self._tab[self._enemy_x][self._enemy_y] = 2

    def startCommand(self, line) -> None:
        if (len(line) != 2):
            print('ERROR')
            return
        if (line[1].isnumeric() == False):
            print('ERROR')
            return
        if (int(line[1]) < 2 or int(line[1]) > 100):
            print('ERROR')
            return
        self._size = (int(line[1]))
        self._tab = [[0 for _ in range(int(line[1]))] for _ in range(int(line[1]))]
        print('OK')

    def turnCommand(self, line) -> None:
        # sourcery skip: extract-duplicate-method
        if (len(line) != 2):
            print('ERROR')
            return
        tmp = line[1].split(",")
        if (len(tmp) != 2):
            print('ERROR')
            return
        self._enemy_x = int(tmp[0])
        self._enemy_y = int(tmp[1])
        if (self._enemy_x >= self._size or self._enemy_x < 0 or self._enemy_y >= self._size or self._enemy_y < 0):
            print('ERROR')
            return
        if (self._tab[self._enemy_x][self._enemy_y] != 0):
            print('ERROR')
            return
        self.boardUpdateEnemy()
        _pos = ia.iaGomoku(self._tab, self._size, "BrainWin")
        if (_pos[0] != -1):
            self._x = int(_pos[0])
            self._y = int(_pos[1])
            self.boardUpdateBrain()
            return
        _pos = ia.iaGomoku(self._tab, self._size, "EnemyWin")
        if (_pos[0] != -1):
            self._x = int(_pos[0])
            self._y = int(_pos[1])
            self.boardUpdateBrain()
            return
        _pos = ia.iaGomoku(self._tab, self._size, "TacticWin")
        if (_pos[0] != -1):
            self._x = int(_pos[0])
            self._y = int(_pos[1])
            self.boardUpdateBrain()
            return
        for x in range(len(self._tab)):
                for y in range(len(self._tab[x])):
                    if (self._tab[x][y] == 0):
                        self._x = x
                        self._y = y
                        self.boardUpdateBrain()
                        return
        
        
    
    def beginCommand(self, line) -> None:
        if (len(line) != 1):
            print('ERROR')
            return
        self._x = round(self._size / 2)
        self._y = round(self._size / 2)
        if (self._tab[self._x][self._y] != 0):
            for x in range(len(self._tab)):
                for y in range(len(self._tab[x])):
                    if (self._tab[x][y] == 0):
                        self._x = x
                        self._y = y
                        self.boardUpdateBrain()
                        return
        else:
            self.boardUpdateBrain()
            return


    def boardCommand(self, line) -> None:
        # sourcery skip: extract-duplicate-method
        number = 0
        if (line[0] != "BOARD"):
            print("ERROR")
        while 1:
            message = input()
            if (message == "DONE"):
                break
            tmp = message.split(",")
            self._x = int(tmp[0])
            self._y = int(tmp[1])
            self._enemy_x = int(tmp[0])
            self._enemy_y = int(tmp[1])
            if (int(tmp[2]) == 1):
                number = 1
                self.boardUpdateBrainTmp()
            else:
                number = 2
                self.boardUpdateEnemyTmp()
        if (number == 2):
            _pos = ia.iaGomoku(self._tab, self._size, "BrainWin")
            if (_pos[0] != -1):
                self._x = int(_pos[0])
                self._y = int(_pos[1])
                self.boardUpdateBrain()
                return
            _pos = ia.iaGomoku(self._tab, self._size, "EnemyWin")
            if (_pos[0] != -1):
                self._x = int(_pos[0])
                self._y = int(_pos[1])
                self.boardUpdateBrain()
                return
            _pos = ia.iaGomoku(self._tab, self._size, "TacticWin")
            if (_pos[0] != -1):
                self._x = int(_pos[0])
                self._y = int(_pos[1])
                self.boardUpdateBrain()
                return
            for x in range(len(self._tab)):
                for y in range(len(self._tab[x])):
                    if (self._tab[x][y] == 0):
                        self._x = x
                        self._y = y
                        self.boardUpdateBrain()
                        return
        if (number == 1):
            return
        #respond as a turn or begin command

    def infoCommand(self, line) -> None:
        print(f"{int(self.x)},{int (self.y)}")
        self.x += 1
        #print("2,3")

    def endCommand(self, line) -> None:
        if (len(line) != 1):
            print("ERROR : END")
        print("none")
        sys.exit(0)
    
    def aboutCommand(self, line) -> None:
        if (len(line) != 2):
            print("ERROR : ABOUT")
        print("name=pbrain, version=0.001, author=Julien Pierre Remi, country=FR")

    def restartCommand(self, line) -> None:
        #clear MAP
        print("OK")