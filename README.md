🚗 Vehicle Rental System 

📋 Description

A basic Object-Oriented Programming (OOP) project in C++ that simulates a simple Vehicle Rental System.

Users can view available vehicles, rent a vehicle, and view rental history. The system uses inheritance, polymorphism, and file handling.

💡 Features

View available vehicles

Rent a vehicle (Economy or Luxury)

Store rental details using file I/O

Polymorphism to handle different vehicle types

Simple CLI (Command Line Interface) based interface

🏗️ Technologies Used

C++

OOP concepts: Classes, Inheritance, Polymorphism

File Handling (ifstream/ofstream)

Vectors/Arrays

Console Input/Output

🧾 Classes Overview

Vehicle (Base class)

Attributes: ID, Brand, Model, Rent Per Day

Virtual functions for displaying info and calculating rent

EconomyCar (Derived)

Basic features, lower rent

LuxuryCar (Derived)

High-end features, premium rent

RentalRecord

Stores rental information (customer name, vehicle ID, days rented)

⚙️ How It Works

User selects a vehicle from the list.

Inputs number of days for rental.

System calculates total rent.

Rental record is saved to a file.

User can view all rental records.

🖥️ How to Run

Clone or download the project.

Compile the code using any C++ compiler,

📌 Future Improvements

Add Admin and User login

Include Date/Time handling

GUI using Qt or SFML

Vehicle availability check

Delete/Edit rental records

👨‍💻 Author

Safoora Ch
GitHub: @SafooraCh
