# Java


# Build system

| | Gradle | Maven |
| - | - | - |
| Create new project | gradle init --type java-application | mvn archetype:generate |
| List available tasks | gradle tasks --all | mvn help:describe -Dcmd=install |
| Build | gradle build | mvn package |
| View ependency Tree | gradle dependencies | mvn dependency:tree |


## Maven

We can use maven to manage the Java packages.

Default local repository is located `~/.m2`

## gradle

```shell
# Show all available tasks
gradle tasks
# Publish to local repository, and you can find it under `~/.m2`
gradle publishToMavenLocal
```

There is gradle wrapper generated to make sure others can use the same gradle version.
Officials said you should keep the version control, but some doesn't like putting binary into git control.
https://stackoverflow.com/questions/43954932/should-i-gitignore-my-gradlew

## Reference

* [Gradle － (1) 從零開始](https://blog.elliot.tw/?p=427): Basic comparison between Gradle and Maven
* [Gradle － (2) Multiple Projects](https://blog.elliot.tw/?p=429): Create multiple projects 
