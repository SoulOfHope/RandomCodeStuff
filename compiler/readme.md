DO NOT RUN THINGS FROM INSIDE THE COMPILER DIRECTORY, be outside of it

Just run "./compiler/setup" and you should be set to use compile, execute and 
interpret. Do compiler for some info

IF IT DOESNT RUN:
do "chmod u+x compiler/perms" then do "./compiler/perms"
Try again after that.

AFTER INSTALLING RUN: source $HOME/.bashrc

The install is silent, any interuptions is likely an error. Run it once, it appends to
 the end of .bashrc, and doesnt care if the stuff is already there, so running setup 
 multiple times will just clog your .bashrc file and will also yoink all your storage.