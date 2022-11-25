# Minitalk
A project about inter process communication (IPC) using UNIX signals.

## External functions allowed
 - `write`
 - `signal`
 - `sigemptyset`
 - `sigaction`
 - `kill`
 - `getpid`
 - `malloc`
 - `free`
 - `pause`
 - `sleep`
 - `usleep`
 - `exit`

## Signals allowed to use
 - SIGUSR1
 - SIGUSR2

## Objectives
 - The client must send a string to the server. Once the server receives the string, must print it.
