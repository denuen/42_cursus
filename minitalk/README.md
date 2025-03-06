# minitalk

A small data exchange program using UNIX signals for communication between processes.

---

## Table of Contents

1. [What is minitalk?](#what-is-minitalk)
2. [Features](#features)
3. [How it Works](#how-it-works)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Project Structure](#project-structure)
7. [Credits](#credits)

---

## What is minitalk?  

`minitalk` is a client-server communication project that demonstrates inter-process communication using UNIX signals. The project consists of two programs: a server that listens for signals, and a client that sends messages to the server through these signals.  
This project showcases fundamental concepts of signal handling, bit manipulation, and process communication in a UNIX environment, following the coding standards of **42 School**.

---

## Features  

- Reliable communication between two processes using only UNIX signals
- Efficient transmission of characters using binary representation
- Signal handling with minimal CPU usage
- Support for messages of any length
- Error handling for process failures and signal interruptions
- Compliant with the 42 School `norminette` standards

---

## How it Works  

The communication protocol works as follows:
1. The server starts and displays its Process ID (PID)
2. The client takes the server's PID and a string to send as arguments
3. The client converts each character to binary and sends it bit by bit:
   - SIGUSR1 represents binary 0
   - SIGUSR2 represents binary 1
4. The server receives and reconstructs the message
5. Once the full message is received, the server displays it

This approach demonstrates efficient binary-level communication using only two signals.

---

## Installation  

Clone the repository:
```bash
git clone https://github.com/deunen/42_cursus.git
cd 42_cursus/minitalk
```
Build the project:
```bash
make

```

This will compile both the server and client executables.

---

## Usage  

1. Start the server in one terminal:
   ```bash
   ./server
   ```
   Note the PID displayed by the server.

2. In another terminal, send a message using the client:
   ```bash
   ./client [server_pid] "Your message here"
   ```

3. The server will receive and display the message.

---

## Project Structure  

```

minitalk/
├── client.c           # Client implementation
├── server.c           # Server implementation
├── libft/             # Custom C library used by the project
├── Makefile           # Build instructions
└── README.md          # Project documentation
```
---

## Credits  

Developed by [deunen](https://github.com/deunen) as part of the 42 School curriculum.  
Special thanks to the 42 community for guidance and inspiration.

---
