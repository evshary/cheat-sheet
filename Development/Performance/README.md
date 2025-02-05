# Performance

Here are some notes:

* Warm up
  * We should remove the result in the first 5 seconds and the last 5 seconds. There might be some cache effect
* Use median value
  * While we are not using RTOS, there might be some outliers. Using mean value is not a good idea.
* Fix the environment
  * Use the same environment to do evalution
  * Also we need a clean environment. Refer to [the note](environment.md)
