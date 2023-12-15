## Development Road map
### Notes and reminders
+ Somehow, some commands should access the `Servos` pointer and have permitions to change the size of it (because it
  shoud be an array of `ParallelServo*`) and interact with each objet normaly. Maybe it's C++ has a syntax that helps
  me with that issue.
+ It's important to rempember that my `auniter.sh` was touched, because I needed to import the local `src/` libraries
  with `arduino-cli` flags somehow, be aware of that...

### Todo list
+ [x] ~~**Feature**: Create a command to set the servos max/min positions and the ammount~~
+ [x] ~~**Unit testing**: Test the functions inside the `src/stringUtilities.h` file~~
+ [x] ~~**Unit testing**: Test if the `commandFactory()` function is returning the expected command class reference~~
+ [x] ~~**Development**: Create an script to easely create new test suits, based on a template file~~
