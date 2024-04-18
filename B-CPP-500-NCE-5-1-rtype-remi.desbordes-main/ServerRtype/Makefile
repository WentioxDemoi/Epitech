SRC    =	main.cpp 																\
			Server/server.cpp 														\
			Server/ToolsServer/tools.cpp 											\
			Components/Player/Player.cpp	 										\
			Components/Lobby/Lobby.cpp												\
			Components/Fire/Fire.cpp 												\
			Components/Enemy/Enemy.cpp 											\
			GameEntity/Player/PlayerEntity.cpp 										\
			GameEntity/Lobby/LobbyEntity.cpp 										\
			GameEntity/Fire/FireEntity.cpp 											\
			GameEntity/Enemy/EnemyEntity.cpp 										\

NAME   =	r-type_server

RM     =	rm -f

all    :	$(NAME)

$(NAME):
	g++ $(SRC) -I /opt/homebrew/Cellar/boost/1.79.0_2/include/ -o $(NAME) -L /opt/homebrew/Cellar/boost/1.79.0_2/lib -lboost_serialization -lpthread -std=c++11

clean  :	
		$(RM) $(NAME)

fclean :	clean
		rm -f *~

re     :	fclean all

.PHONY :	all clean fclean re