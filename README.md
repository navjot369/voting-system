# Voting System in C
A voting system in C for students to gather opinions, conduct polls, and collect feedback.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Folder Structure](#folder-structure)
- [Installation and Usage](#installation-and-usage)
- [Contributing](#contributing)
- [Contact](#contact)

## Introduction

This project is a mini voting system implemented in C, designed for students to gather opinions on various topics. It provides a simple yet effective way to conduct polls, make decisions, and collect feedback from members or participants.

## Features

- Multiple votes by single user
- Real-time vote counting
- Result display using infographics
- Easy-to-use CLI based menu system
- Anonymous Voting, no user registration required
- Secure Voting, uses database to verify voter's identity

## Folder Structure

```bash
.
├── README.md
├── main.c
├── run.sh
├── Voting.a
├── graphics
│   └── graphs.c
├── include
│   ├── AnonymousVoting.h
│   ├── InitialiseVoting.h
│   ├── OpenVoting.h
│   ├── clearScreen.h
│   ├── getResult.h
│   ├── graphs.h
│   ├── printOptions.h
│   └── takeVote.h
├── utils
│   ├── clearScreen.c
│   ├── getResult.c
│   ├── printOptions.c
│   └── takeVote.c
├── votersRecord
│   ├── data
│   │   └── data.txt
│   ├── enterRecord.c
└── voting
    ├── AnonymousVoting.c
    ├── InitialiseVoting.c
    └── OpenVoting.c
```

## Installation and Usage

1. Clone the repository:
   ```
   git clone https://github.com/navjot369/voting-system.git
   ```
2. Navigate to the project directory:
   ```
   cd voting-system
   ```
3. For Linux or macOS:
   ```
   ./run.sh
   ```
   For Windows:
   ```
   ./run.bat
   ```
    Follow the on-screen prompts to continue


## Contributing

Contributions to improve the voting system are welcome. Please follow these steps:

1. Fork the repository
2. Create a new branch (`git checkout -b feature-branch`)
3. Make your changes and commit (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin feature-branch`)
5. Create a new Pull Request

## Contact

For any queries or suggestions, please open an issue in the GitHub repository.
