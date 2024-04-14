# Utiliser une image Node.js comme base
FROM node:latest

# Définir le répertoire de travail
WORKDIR /app

# Copier les fichiers de l'application
COPY . /app

# Installer Angular
RUN npm install -g @angular/cli

# Exposer le port 4200 (le port utilisé par Angular)
EXPOSE 8081

# Lancer l'application Angular avec la commande "ng serve"
CMD ["npm", "start"]