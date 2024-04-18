R-TYPE
------
The R-type is a project for the Epitech's Third year. The goal is to create a 
game, the R-type, but this time, with a network architecture. 

```
The project is composed of 2 parts:
- The server
- The client
More explanation following.
```

Composition of the Server
------

The server manages the game in itself, and the communication between the 
clients. It is composed of 2 parts:
- The Network, that is managed with the UDP Protocol (User Data Protocol).
- A Managing system, that manages the game, the players, the enemies, and the 
  level.

The Server is the central part of the game, since it manages the game.

Composition of the Client
------
The Client is the part that the player will use to play the game. It is 
composed of 2 parts:
- The Connection to the server, that is managed with the UDP Protocol (User 
  Data Protocol).
- The Game, which is managed with the SFML library, and display the game as 
  the data sent by the server

Commands to compile and execute the Client and Server on Linux
------
```
compilation:
solution 1: ./build_linux.sh
solution2: mkdir build; cd build; cmake ..; make
for execution:
go to Server folder and execute ./r-type_server [network port]
go to Client folder and execute ./r-type_client 
```

Commands to play the game
------
```
You will have the User and Technical documentation on this site: https://antoinerovini0.wixsite.com/r-type
To play the game, when you have connected, you move your ship with the ZQSD keys, and you shoot with the Space Bar.
```