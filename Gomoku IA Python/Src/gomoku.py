from .commands import Commands

commands = Commands()

class Gomoku:

    def compareCommands(self, _line) -> None:
        if (_line[0] == "START"):
            commands.startCommand(_line)
        elif (_line[0] == "TURN"):
            commands.turnCommand(_line)
        elif (_line[0] == "BEGIN"):
            commands.beginCommand(_line)
        elif (_line[0] == "BOARD"):
            commands.boardCommand(_line)
        elif (_line[0] == "RESTART"):
            commands.restartCommand(_line)
        elif (_line[0] == "END"):
            commands.endCommand(_line)
        
    def parseLine(self, _line) -> list:
        return _line.split(" ")

    def loop(self) -> None:
        while True:
            line = input()
            inputParsing = self.parseLine(line)
            self.compareCommands(inputParsing)
