# 🍽️ Restaurant Management System
### CMPG104 — Data Structures & Algorithms | Spring 2026

A simulation of a restaurant's order management system built in C++.  
The system handles dine-in, takeaway, and delivery orders while managing resources (chefs, tables, scooters) using custom data structures.

---

## 📌 Project Overview

Orders flow through four states:

```
PENDING ORDER → COOKING ORDER → READY ORDER → IN-SERVICE ORDER → FINISHED
(Waiting for Chef)  (Preparing)   (Waiting for Service)  (Delivering / Eating)
```

The system supports:
- **6 order types** — ODG, ODN, OT, OVC, OVG, OVN
- **2 chef types** — Special (CS) and Normal (CN)
- **Priority-based assignment** for chefs, tables, and scooters
- **Order cancellation** for OVC orders at any stage
- **Interactive & Silent** simulation modes

---

## 🗂️ Project Structure

```
RestaurantManagement/
│
├── Actions/              # Action base class, RequestAction, CancelAction
├── DataStructures/       # Stack, Queue, PriorityQueue (lab-based)
├── Entities/             # Order, Chef, Scooter, Table classes
├── System/               # Restaurant (simulation engine) & UI
└── main.cpp              # Entry point
```

---

## 🚀 Phases

| Phase | Description | Weight | Due |
|-------|-------------|--------|-----|
| 1.1 | Data Structure Selection Report | 10% | Sat, 04-Apr |
| 1.2 | DS Implementation + Random Simulator | 30% | Sat, 11-Apr |
| 2   | Full Simulation + Input/Output Files | 60% | Fri, 01-May |

---

## 👥 Team

| Name | GitHub |
|------|--------|
| Mahmoud Fathy | [@Mahmoud-Fathy5](https://github.com/Mahmoud-Fathy5) |
| Mahmoud Taha | [@The-Teen-Programer](https://github.com/The-Teen-Programer) |
| Mohamed Medhat | [@MoMedhat74](https://github.com/MoMedhat74) |

---

## ⚙️ Build & Run

Open the solution in **Visual Studio** and build normally, or via command line:

```bash
g++ -std=c++17 -o RestaurantManagement main.cpp
./RestaurantManagement
```

The program will prompt you to choose a mode:
- **Interactive** — step-by-step simulation with full console output
- **Silent** — runs to completion and produces only the output file

---

## 📄 Input File Format

```
25 13           ← number of CN and CS chefs
3 2             ← CN speed, CS speed (dishes/timestep)
20 150          ← scooter count, scooter speed (m/timestep)
8 23            ← maintenance: orders before service, duration
20              ← total number of tables
5 3 2 4 ...     ← table count-capacity pairs
800             ← number of actions
Q ODG 7 1 15 110 4 14 Y    ← request action
X 15 2                     ← cancel action
```

---

## 📊 Output File Format

One line per finished order, sorted by finish time (descending):

```
TF  ID  TQ  TA  TR  TS  Ti  TC  Tw  Tserv
```

Followed by summary statistics: order counts, utilization rates, averages for Ti, TC, Tw, Tserv.

---

## 📏 Constraints

- ✅ Uses **only** Stack / Queue / PriorityQueue (lab-provided or derived)
- ✅ All lists hold **pointers** — objects are moved, never copied
- ❌ No global variables
- ❌ No C++ STL (no `vector`, `list`, `map`, etc.)
