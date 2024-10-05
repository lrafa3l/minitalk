# Minitalk

## Overview
This is a program that simulate a communication between a client and a server. The server will receive messages from the client using UNIX signals.

## Requirements

### Server

- The server must be started first.
- After launching, the server should print its Process ID (PID).
- The server must be capable of receiving strings from multiple clients sequentially without needing to restart.
- Upon receiving a string, the server must print it quickly. (Displaying 100 characters should not take more than 1 second.)

### Client

- The client requires two parameters to run.
  - The PID of the server.
  - The string to send.
- The client must send the provided string to the server.

## Usage

To run the communication program, follow these steps:

### 1. Compile the Program

Simply run:

```bash
make
```
### 2. Start the Server
First, start the server in a terminal window. The server will print its Process ID (PID), which the client needs to send messages.

``` bash
./server
```
#### Output:

``` arduino
Server PID: 12345
```
### 3. Start the Client

``` bash
./client <PID> "Your message here"
```

## Example:

``` bash
./client 164481 "Hello World"
```
4. View the Output
After sending the message, the server will display the received string in its terminal, like that:
&nbsp;
![client](https://github.com/user-attachments/assets/11371d61-75ea-4023-a627-e735f66d6311)
&nbsp;
![server](https://github.com/user-attachments/assets/34d1ccc7-aaa9-44ce-9aaf-a289c7174318)
