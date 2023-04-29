# highjack-port
### (Linux & MacOs)

Highjack-Port is a tool written in C, designed to kill a process that is currently listening on a specified port.

## Get started

Clone the repo or download:
```bash
$ git clone https://github.com/nou-man/highjack-port.git
```
Compile the C file:
```
gcc highjack.c -o highjack
```
or use the existing binary:

### usage
for running in current directory
```
./highjack [port_number]
```
#### Adding the executable to the /bin for global access
Linux
```
sudo cp /path/to/executable/highjack /usr/bin/
```
Mac
```

```
run after adding executable in bin.
```
highjack [port_number]
```

## Purpose:
I have a friend who is into web development and sometimes when he had to host in his localhost, ports would be sometimes pre occupied with some unhandled services running from old tests, so everytime he had to run some series of commands and manually had to check for the process that has occupied the port, and remember the PID of the process and kill them using kill command.

what he had to run:
```
lsof -n -i :[port_number]
```
 would show
```
COMMAND    PID USER   FD   TYPE  DEVICE SIZE/OFF NODE NAME
nc      265938 hero    3u  IPv4 1891870      0t0  TCP *:3000 (LISTEN)
```
then run 
```
kill 265938
```

### Example

```
hero@kali:~$ highjack 3000
Preparing to kill the process with pid : 265938 ....
PID: 265938 has been killed

```
The 3000 port was occupied, so using the highhjack the port is highjacked by you now.

