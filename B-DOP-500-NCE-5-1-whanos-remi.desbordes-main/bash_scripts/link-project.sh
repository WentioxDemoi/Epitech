#!/bin/bash

if [ -z "$1" ]; then
    echo "No project name provided."
    exit 1
fi

project_name="$1"

detection=()

if [ ! -d "app" ]; then
    echo "No app folder found in the project repository."
    exit 1
fi

if [ -f "Makefile" ]; then
    detection+=("c")
fi
if [ -f "app/pom.xml" ]; then
    detection+=("java")
fi
if [ -f "package.json" ]; then
    detection+=("javascript")
fi
if [ -f "requirements.txt" ]; then
    detection+=("python")
fi
if [ -f "app/main.bf" ]; then
    detection+=("befunge")
fi

if [ ${#detection[@]} -eq 0 ]; then
    echo "No supported language found in the repository."
    exit 1
elif [ ${#detection[@]} -gt 1 ]; then
    echo "Multiple supported languages found in the repository, there must be only one."
    exit 1
fi

language=${detection[0]}

standalone_tag=""

if [ -f "Dockerfile" ]; then
    echo "Project Dockerfile detected, using base $language image."
    docker build -t whanos-"$project_name"-"$language" .
else
    echo "No project Dockerfile detected, using standalone $language image."
    standalone_tag="-standalone"
    docker build -t whanos-"$project_name"-"$language" -f "$JENKINS_HOME"/images/"$language"/Dockerfile.standalone .
fi

registry_tag=localhost:5000/"$project_name"/whanos-"$language""$standalone_tag"

docker rmi --force "$registry_tag"
docker tag whanos-"$project_name"-"$language" "$registry_tag"
docker push "$registry_tag"
docker pull "$registry_tag"
docker rmi --force whanos-"$project_name"-"$language"
