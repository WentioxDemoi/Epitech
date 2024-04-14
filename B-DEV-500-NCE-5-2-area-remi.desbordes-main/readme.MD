# AREA APPLICATION

The goal of this project is to allow users to trigger reactions thanks to specific actions (Action/REAction).
An action is triggered when a specific condition is met. A reaction is triggered when an action is triggered.

The project is composed of 2 parts:
- The server: the server is the core of the project. It is responsible for the management of the actions and reactions.
- The client: the client is the interface of the project. It is responsible for the management of the users and the configuration of the actions and reactions.

The client allows the user to select any action available that will trigger any reaction.

## Available Services

The user can access to the services by "subscribing" to them in the App (by selecting them in the service page).
Here is the list of the services available, and their actions/reactions:

### OpenWeather service (using OpenWeather API)
- Actions:
  - If the indicated coordinates' current temperature reaches the indicated temperature
  - If the indicated coordinates' max temperature of the day reaches the indicated temperature
  - If the indicated coordinates' min temperature of the day reaches the indicated temperature
  - If the indicated coordinates' current humidity reaches the indicated humidity
  - If the indicated coordinates' current pressure reaches the indicated pressure
  - If the indicated coordinates' sea level is of the indicated value
  - If the indicated coordinates' ground level is of the indicated value
- Reactions:
  - None

### Github service (using Github API)
- Actions:
  - If a new repository is created in the application's organization
  - If a new repository is deleted in the application's organization
- Reactions:
  - Create a new reposistory with a specified name in the application's account
  - Delete a repository with a specified name in the application's account
  - Create a new branch with a specified name in the application's repository
  - Delete a branch with a specified name in the application's repository

### Chuck Norris joke service (using Chuck Norris API)
- Actions:
  - None
- Reactions:
  - None
  This service is used for an other one. The API is used to get a random joke, and the joke is sent to the user via email with an other service.

### Spring Boot Mail service (using Spring Boot Mail & Gmail API)
- Actions:
  - None
- Reactions:
  - Send an email to the user with a a Chuck Norris joke

### Timer service (using real time)
- Actions:
  - If the current minute is a multiple of 5
- Reactions:
  - None

## Project Compilation

Docker is used to compile the project.
To compile the project, you must have Docker installed and launched on your computer.
Then, run the following commands in the root of the project (where the docker-compose.yml file is located):

docker-compose build
docker-compose up

URLs:
Server: http://localhost:8080/
Web application: http://localhost:8081/
