

FROM maven:3.8.7-eclipse-temurin-17-focal AS build
COPY src /home/app/src
COPY pom.xml /home/app
RUN mvn -f /home/app/pom.xml clean package

#
# Package stage
#
FROM openjdk:17-jdk-slim-buster
#openjdk:8-jdk-alpine
COPY --from=build /home/app/target/area-0.0.1-SNAPSHOT.jar /usr/local/lib/demo.jar
EXPOSE 8080
ENTRYPOINT ["java","-jar","/usr/local/lib/demo.jar"]

# FROM maven:3.8.7-eclipse-temurin-17-focal

# WORKDIR /app

# # Copy the pom.xml file to the container
# COPY pom.xml .

# # Download all dependencies

# #RUN mvn dependency:go-offline

# # Copy the rest of the project files to the container
# COPY . .

# # Build the project using maven
# RUN mvn clean install -U
# RUN mvn compile
# RUN mvn package

# RUN ls && sleep 5
# RUN ls/app/ && sleep 5

# # Make port 8080 available to the world outside this container
# EXPOSE 8080

# RUN mvn -v && sleep 5

# FROM openjdk:8-jdk-alpine

# RUN ls && sleep 5

# ADD target/area-0.0.1-SNAPSHOT.jar area-0.0.1-SNAPSHOT.jar

# # Run the jar file
# CMD ["java", "-jar", "target/area-0.0.1-SNAPSHOT.jar"]







# # Utilisez une image de base avec Java 1.8 préinstallé

# FROM maven:3.8.3-openjdk-17

# # Copie de la source de l'application dans l'image
# WORKDIR /app
# #-------> #docker pull openjdk:19-alpine
# # Copy the pom.xml file to the container
# COPY pom.xml .

# # Download all dependencies

# #RUN mvn dependency:go-offline

# # Copy the rest of the project files to the container
# COPY . .

# # Build the project using maven
# RUN mvn clean install -U
# RUN mvn compile
# RUN mvn package
# RUN ls && sleep 10
# # Commande à exécuter lorsque le conteneur est lancé
# CMD ["java", "-jar", "target/spring-boot-area-0.0.1-SNAPSHOT.jar"]



# #FROM openjdk:8-jdk-alpine


#WORKDIR /app
#-------> #docker pull openjdk:19-alpine
# Copy the pom.xml file to the container
#COPY pom.xml .

# Download all dependencies

#RUN mvn dependency:go-offline

# Copy the rest of the project files to the container
#COPY . .

# Build the project using maven

#RUN mvn clean install -U
#RUN mvn compile
#RUN mvn package


# Make port 8080 available to the world outside this container
#EXPOSE 8080
#
# Run the jar file
#CMD ["java", "-jar", "target/spring-boot-area-0.0.1-SNAPSHOT.jar"]

