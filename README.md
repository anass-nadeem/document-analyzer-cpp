# 📄 Document Analyzer (C++)
## 📌 Project Overview

The Document Analyzer is a semester project developed in C++ that processes and analyzes text documents using fundamental data structures.
The goal of this project is to demonstrate how theoretical concepts such as queues, stacks, and maps can be applied to solve real-world document processing problems.

## 🎯 Objectives

- Load and process text documents efficiently

- Apply core data structures in a practical scenario

- Analyze document content using structured logic

- Strengthen understanding of data structure concepts through implementation

## 🛠️ Technologies Used

### Language: C++

### Concepts:

- Queue

- Stack

- Map

- File Handling

- Searching & Traversal

## ⚙️ Key Features

- Reads text files line by line

- Stores document data using appropriate data structures

- Supports keyword and concept handling

- Maintains history tracking using stack

- Modular and easy-to-understand code structure

## 🧱 Data Structures Used
Data Structure	Purpose
Queue	Store and process document lines sequentially
Stack	Maintain history of user actions
Map	Store definitions and keyword mappings
## 📂 Project Structure
document-analyzer-cpp/

│

├── main.cpp

├── document_processor.h

├── document_processor.cpp

├── query_system.h

├── analysis_tools.h

├── sample.txt

└── README.md

## ▶️ How to Run

### Clone the repository:

git clone https://github.com/anass-nadeem/document-analyzer-cpp.git


### Compile the project:

g++ main.cpp document_processor.cpp -o analyzer


### Run the program:

./analyzer

## ⚠️ Limitations

- The tool does not use AI or NLP techniques; all processing is rule-based.

- It cannot infer answers beyond the text in the document; only works with the content provided.

- Designed for plain text documents; formatted files (PDF, Word, etc.) are not supported.

- Does not perform semantic analysis or context understanding.

- Limited to single-user sequential processing; no multi-threading or concurrent access.

## 📚 Academic Context

This project was developed as part of a semester course to practice and apply Data Structures and Algorithms concepts in a real programming task.

## 👤 Author

Muhammad Anas Nadeem

Artificial Intelligence Student

## 📜 License

This project is created for educational purposes.
