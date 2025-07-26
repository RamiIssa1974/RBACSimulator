# RBACSimulator

A lightweight **Role-Based Access Control (RBAC)** simulator written in modern **C++**, demonstrating strong use of **OOP design**, **JSON persistence**, and **multithreading with mutex protection**.

> Developed by [Rami Issa](https://github.com/RamiIssa1974)

---

## 🛠 Features

- ✅ Define users, roles, and permissions
- ✅ Assign roles to users
- ✅ Check if a user has a specific permission (even across multiple roles)
- ✅ Save/load the system state to/from a JSON file
- ✅ Multi-threaded permission checks with `std::mutex` protection
- ✅ Clean and modular structure using `std::map`, `std::vector`, and `std::string`

---

## 📁 Project Structure

```plaintext
RBACSimulator/
├── AccessManager.cpp
├── AccessManager.h
├── DataStore.cpp
├── DataStore.h
├── Permission.cpp
├── Permission.h
├── Role.cpp
├── Role.h
├── User.cpp
├── User.h
├── main.cpp
├── include/
│   └── json.hpp         # nlohmann::json library (header-only)
├── .gitignore
└── README.md
```

---

## 🧪 Example Output
Thread: User 0263 HAS permission read
Thread: User 0263 HAS permission write
Thread: User 0263 DOES NOT HAVE permission admin

---

## 📦 Dependencies

- [nlohmann/json](https://github.com/nlohmann/json) (header-only)
- C++11 or higher
- Visual Studio / g++ compatible

---

## 🚀 How to Run

1. Clone this repo:
   ```bash
   git clone https://github.com/RamiIssa1974/RBACSimulator.git
   g++ -std=c++11 *.cpp -o rbac
  ./rbac


This project was created to demonstrate my ability to design real-world C++ systems, including:

Clean object-oriented modeling

Thread safety

Data persistence

Structured, testable code

📬 Contact
📧 Ram_fad@yahoo.com
📍 Kfar Qassem, Israel
🔗 LinkedIn

© 2025 Rami Issa – All rights reserved.


