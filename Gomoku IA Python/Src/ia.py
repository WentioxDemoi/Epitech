class Ia:

    _tab = [[]]
    _size = 0
    _x = 0
    _y = 0
    _pos = [-1, -1]

    def checkLineRight(self, number, limit):
        i = 1
        tmp = 0
        size = 0
        for i in range(5):
            if self._y + i >= self._size:
                return False
            if self._tab[self._x][self._y + i] == number:
                size += 1
            elif self._tab[self._x][self._y + i] == 0:
                if tmp == 0:
                    self._pos[0] = self._x
                    self._pos[1] = self._y + i
                tmp += 1
            else:
                return False
            if (tmp > limit):
                return False
        return True
    
    ##ici
    def checkLineLeft(self, number, limit):
        i = 1
        tmp = 0
        size = 0
        for i in range(5):
            if self._y - i < 0:
                return False
            if self._tab[self._x][self._y - i] == number:
                size += 1
            elif self._tab[self._x][self._y - i] == 0:
                if tmp == 0:
                    self._pos[0] = self._x
                    self._pos[1] = self._y - i
                tmp += 1
            else:
                return False
            if (tmp > limit):
                return False
        return True

    def checkVerticalDown(self, number, limit):
        i = 1
        tmp = 0
        size = 0
        for i in range(5):
            if self._x + i >= self._size:
                return False
            if self._tab[self._x + i][self._y] == number:
                size += 1
            elif self._tab[self._x + i][self._y] == 0:
                if tmp == 0:
                    self._pos[0] = self._x + i
                    self._pos[1] = self._y
                tmp += 1
            else:
                return False
            if (tmp > limit):
                return False
        return True
    
    ##ici
    def checkVerticalUp(self, number, limit):
        i = 1
        tmp = 0
        size = 0
        for i in range(5):
            if self._x - i < 0:
                return False
            if self._tab[self._x - i][self._y] == number:
                size += 1
            elif self._tab[self._x - i][self._y] == 0:
                if tmp == 0:
                    self._pos[0] = self._x - i
                    self._pos[1] = self._y
                tmp += 1
            else:
                return False
            if (tmp > limit):
                return False
        return True

    def checkDiagonalRight(self, number, limit):
        i = 1
        tmp = 0
        size = 0
        for i in range(5):
            if self._x + i >= self._size or self._y + i >= self._size:
                return False
            if self._tab[self._x + i][self._y + i] == number:
                size += 1
            elif self._tab[self._x + i][self._y + i] == 0:
                if tmp == 0:
                    self._pos[0] = self._x + i
                    self._pos[1] = self._y + i
                tmp += 1
            else:
                return False
            if (tmp > limit):
                return False
        return True
    
    def checkDiagonalRightReverse(self, number, limit):
        i = 1
        tmp = 0
        size = 0
        for i in range(5):
            if self._x - i < 0 or self._y + i >= self._size:
                return False
            if self._tab[self._x - i][self._y + i] == number:
                size += 1
            elif self._tab[self._x - i][self._y + i] == 0:
                if tmp == 0:
                    self._pos[0] = self._x - i
                    self._pos[1] = self._y + i
                tmp += 1
            else:
                return False
            if (tmp > limit):
                return False
        return True
    
    def checkDiagonalLeft(self, number, limit):
        i = 1
        tmp = 0
        size = 0
        for i in range(5):
            if self._x + i >= self._size or self._y - i < 0:
                return False
            if self._tab[self._x + i][self._y - i] == number:
                size += 1
            elif self._tab[self._x + i][self._y - i] == 0:
                if tmp == 0:
                    self._pos[0] = self._x + i
                    self._pos[1] = self._y - i
                tmp += 1
            else:
                return False
            if (tmp > limit):
                return False
        return True
    
    def checkDiagonalLeftReverse(self, number, limit):
        i = 1
        tmp = 0
        size = 0
        for i in range(5):
            if self._x - i < 0 or self._y - i < 0:
                return False
            if self._tab[self._x - i][self._y - i] == number:
                size += 1
            elif self._tab[self._x - i][self._y - i] == 0:
                if tmp == 0:
                    self._pos[0] = self._x - i
                    self._pos[1] = self._y - i
                tmp += 1
            else:
                return False
            if (tmp > limit):
                return False
        return True




    
    def verifBrainWin(self, tab, size):
        self._tab = tab
        self._size = size
        self._x = 0
        self._y = 0
        for self._x in range(len(self._tab)):
            for self._y in range(len(self._tab[self._x])):
                if (tab[self._x][self._y] == 1):
                    if ((self.checkLineRight(1, 1) == True)):
                        return self._pos
                    if ((self.checkLineLeft(1, 1) == True)):
                        return self._pos
                    if ((self.checkVerticalDown(1, 1) == True)):
                        return self._pos
                    if ((self.checkVerticalUp(1, 1) == True)):
                        return self._pos
                    if ((self.checkDiagonalRight(1, 1) == True)):
                        return self._pos
                    if ((self.checkDiagonalRightReverse(1, 1) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeft(1, 1) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeftReverse(1, 1) == True)):
                        return self._pos

        self._pos[0] = -1
        return self._pos
    
    def initValue(self, tab, size):
        self._tab = tab
        self._size = size
        self._x = 0
        self._y = 0
        self._pos = [-1, -1]
    
    def VerifEnemyWin(self, tab, size):  # sourcery skip: low-code-quality
        self.initValue(tab, size)
        for self._x in range(len(self._tab)):
            for self._y in range(len(self._tab[self._x])):
                if (tab[self._x][self._y] == 2):
                    if ((self.checkLineRight(2, 1) == True)):
                        return self._pos
                    if ((self.checkLineLeft(2, 1) == True)):
                        return self._pos
                    if ((self.checkVerticalDown(2, 1) == True)):
                        return self._pos
                    if ((self.checkVerticalUp(2, 1) == True)):
                        return self._pos
                    if ((self.checkDiagonalRight(2, 1) == True)):
                        return self._pos
                    if ((self.checkDiagonalRightReverse(2, 1) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeft(2, 1) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeftReverse(2, 1) == True)):
                        return self._pos
        self.initValue(tab, size)
        for self._x in range(len(self._tab)):
            for self._y in range(len(self._tab[self._x])):
                if (tab[self._x][self._y] == 2):
                    if ((self.checkLineRight(2, 2) == True)):
                        return self._pos
                    if ((self.checkLineLeft(2, 2) == True)):
                        return self._pos
                    if ((self.checkVerticalDown(2, 2) == True)):
                        return self._pos
                    if ((self.checkVerticalUp(2, 2) == True)):
                        return self._pos
                    if ((self.checkDiagonalRight(2, 2) == True)):
                        return self._pos
                    if ((self.checkDiagonalRightReverse(2, 2) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeft(2, 2) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeftReverse(2, 2) == True)):
                        return self._pos
        self.initValue(tab, size)
        for self._x in range(len(self._tab)):
            for self._y in range(len(self._tab[self._x])):
                if (tab[self._x][self._y] == 2):
                    if ((self.checkLineRight(2, 3) == True)):
                        return self._pos
                    if ((self.checkLineLeft(2, 3) == True)):
                        return self._pos
                    if ((self.checkVerticalDown(2, 3) == True)):
                        return self._pos
                    if ((self.checkVerticalUp(2, 3) == True)):
                        return self._pos
                    if ((self.checkDiagonalRight(2, 3) == True)):
                        return self._pos
                    if ((self.checkDiagonalRightReverse(2, 3) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeft(2, 3) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeftReverse(2, 3) == True)):
                        return self._pos
        self._pos[0] = -1
        return self._pos
    
    def TacticWin(self, tab, size):  # sourcery skip: low-code-quality
        self.initValue(tab, size)
        for self._x in range(len(self._tab)):
            for self._y in range(len(self._tab[self._x])):
                if (tab[self._x][self._y] == 2):
                    if ((self.checkLineRight(1, 2) == True)):
                        return self._pos
                    if ((self.checkLineLeft(1, 2) == True)):
                        return self._pos
                    if ((self.checkVerticalDown(1, 2) == True)):
                        return self._pos
                    if ((self.checkVerticalUp(1, 2) == True)):
                        return self._pos
                    if ((self.checkDiagonalRight(1, 2) == True)):
                        return self._pos
                    if ((self.checkDiagonalRightReverse(1, 2) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeft(1, 2) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeftReverse(1, 2) == True)):
                        return self._pos
        self.initValue(tab, size)
        for self._x in range(len(self._tab)):
            for self._y in range(len(self._tab[self._x])):
                if (tab[self._x][self._y] == 2):
                    if ((self.checkLineRight(1, 3) == True)):
                        return self._pos
                    if ((self.checkLineLeft(1, 3) == True)):
                        return self._pos
                    if ((self.checkVerticalDown(1, 3) == True)):
                        return self._pos
                    if ((self.checkVerticalUp(1, 3) == True)):
                        return self._pos
                    if ((self.checkDiagonalRight(1, 3) == True)):
                        return self._pos
                    if ((self.checkDiagonalRightReverse(1, 3) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeft(1, 3) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeftReverse(1, 3) == True)):
                        return self._pos
        self.initValue(tab, size)
        for self._x in range(len(self._tab)):
            for self._y in range(len(self._tab[self._x])):
                if (tab[self._x][self._y] == 2):
                    if ((self.checkLineRight(1, 4) == True)):
                        return self._pos
                    if ((self.checkLineLeft(1, 4) == True)):
                        return self._pos
                    if ((self.checkVerticalDown(1, 4) == True)):
                        return self._pos
                    if ((self.checkVerticalUp(1, 4) == True)):
                        return self._pos
                    if ((self.checkDiagonalRight(1, 4) == True)):
                        return self._pos
                    if ((self.checkDiagonalRightReverse(1, 4) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeft(1, 4) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeftReverse(1, 4) == True)):
                        return self._pos
        for self._x in range(len(self._tab)):
            for self._y in range(len(self._tab[self._x])):
                if (tab[self._x][self._y] == 2):
                    if ((self.checkLineRight(1, 5) == True)):
                        return self._pos
                    if ((self.checkLineLeft(1, 5) == True)):
                        return self._pos
                    if ((self.checkVerticalDown(1, 5) == True)):
                        return self._pos
                    if ((self.checkVerticalUp(1, 5) == True)):
                        return self._pos
                    if ((self.checkDiagonalRight(1, 5) == True)):
                        return self._pos
                    if ((self.checkDiagonalRightReverse(1, 5) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeft(1, 5) == True)):
                        return self._pos
                    if ((self.checkDiagonalLeftReverse(1, 5) == True)):
                        return self._pos
        self._pos[0] = -1
        return self._pos

    def iaGomoku(self, tab, size, action):
        if (action == "BrainWin"):
            return self.verifBrainWin(tab, size)
        elif (action == "EnemyWin"):
            return self.VerifEnemyWin(tab, size)
        elif (action == "TacticWin"):
            return self.TacticWin(tab, size)