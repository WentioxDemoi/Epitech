#include <iostream>
#include "Server/server.hpp"

int main(int ac, char** av)
{
  try {
    Server server(atoi(av[1]));
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
	return 0;
}