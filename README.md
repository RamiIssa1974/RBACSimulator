# RBACSimulator

A lightweight **Role-Based Access Control (RBAC)** simulator written in modern **C++**, demonstrating strong use of **OOP design**, **JSON persistence**, and **multithreading with mutex protection**.

> Developed by [Rami Issa](https://github.com/RamiIssa1974)

---

## 🛠 Features

- ✅ Object-Oriented design: `User`, `Role`, `Permission` with clear responsibilities
- ✅ Role assignment and permission validation
- ✅ JSON save/load using `nlohmann/json`
- ✅ Thread-safe access using `std::mutex` and `std::lock_guard`
- ✅ Smart memory management with `std::shared_ptr`
- ✅ Polymorphic permission evaluation using `IPermissionEvaluator` interface
- ✅ Easy to extend: plug new permission rules without changing core logic
- ✅ Multithreaded permission checks using `std::thread`

## 💡 Design Concepts Demonstrated

- **RAII (Resource Acquisition Is Initialization)**: used in file streams, mutex management, and smart pointers
- **Polymorphism via interface**: permission logic is decoupled using a virtual evaluator strategy
- **Thread safety**: all shared data structures are protected using `std::mutex` and `lock_guard`
- **Modern C++ principles**: use of `shared_ptr`, range-based loops, auto, and STL containers
- **Clean architecture**: logic separated into small, testable components

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


