folder("Projects") {
    description("Folder for projects.")
}

folder("Whanos base images") {
    description("Folder for Whanos base images.")
}

freeStyleJob("Whanos base images/whanos-c") {
    steps {
        shell("docker build $JENKINS_HOME/images/c -f $JENKINS_HOME/images/c/Dockerfile.base -t whanos-c")
    }
}

freeStyleJob("Whanos base images/whanos-java") {
    steps {
        shell("docker build $JENKINS_HOME/images/java -f $JENKINS_HOME/images/java/Dockerfile.base -t whanos-java")
    }
}

freeStyleJob("Whanos base images/whanos-javascript") {
    steps {
        shell("docker build $JENKINS_HOME/images/javascript -f $JENKINS_HOME/images/javascript/Dockerfile.base -t whanos-javascript")
    }
}

freeStyleJob("Whanos base images/whanos-python") {
    steps {
        shell("docker build $JENKINS_HOME/images/python -f $JENKINS_HOME/images/python/Dockerfile.base -t whanos-python")
    }
}

freeStyleJob("Whanos base images/whanos-befunge") {
    steps {
        shell("docker build $JENKINS_HOME/images/befunge -f $JENKINS_HOME/images/befunge/Dockerfile.base -t whanos-befunge")
    }
}

freeStyleJob("Whanos base images/Build all base images") {
    publishers {
        downstream([
            "Whanos base images/whanos-c",
            "Whanos base images/whanos-java",
            "Whanos base images/whanos-javascript",
            "Whanos base images/whanos-python",
            "Whanos base images/whanos-befunge",
        ], "SUCCESS")
    }
}

freeStyleJob("link-project") {
    parameters {
        stringParam("GIT_REPOSITORY_URL", null, "Git URL of the repository to clone.")
        stringParam("PROJECT_NAME", null, "Project name.")
    }
    steps {
        dsl {
            text('''
                freeStyleJob("Projects/$PROJECT_NAME") {
                    scm {
                        git {
                            remote {
                                name("origin")
                                url("$GIT_REPOSITORY_URL")
                            }
                        }
                    }
                    triggers {
                        scm("* * * * *")
                    }
                    wrappers {
                        preBuildCleanup()
                    }
                    steps {
                        shell("$JENKINS_HOME/link-project.sh $PROJECT_NAME")
                    }
                    wrappers {
                        preBuildCleanup()
                    }
                }
            ''')
        }
    }
}
