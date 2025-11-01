
# CPU Scheduling Algorithms Simulator (C Program)

This project simulates **Operating System CPU scheduling algorithms**.
It helps understand how processes are scheduled in OS based on burst time, arrival time, and priority.

---

## ✅ Algorithms Implemented

| Algorithm   | Type           | Description                                                               |
| ----------- | -------------- | ------------------------------------------------------------------------- |
| FCFS        | Non-preemptive | Executes processes in arrival order                                       |
| SJF         | Non-preemptive | Picks the shortest burst time first                                       |
| Priority    | Non-preemptive | Executes process with highest priority (lowest number = highest priority) |
| Round Robin | Preemptive     | Executes processes in time slices (Time Quantum)                          |

---

## 🎯 Program Features

* Accepts arrival time, burst time & priority
* Calculates:

  * Waiting Time
  * Turnaround Time
* Prints Average Waiting & Turnaround Time
* Displays **Gantt Chart** for each algorithm
* Menu-based selection

---

## 📥 Input Format

```
Enter number of processes: 4
Enter Arrival  Burst  Priority
0 5 2
1 3 1
2 8 4
3 6 3
```

---

## 🖥️ Output Sample

```
===== FCFS Scheduling =====
P1: Waiting=0  Turnaround=5
P2: Waiting=4  Turnaround=7
P3: Waiting=5  Turnaround=13
P4: Waiting=10 Turnaround=16

Gantt Chart:
| P1 | P2 | P3 | P4 |

Avg Waiting: 4.75
Avg Turnaround: 10.25
```

---

## ▶️ How to Compile & Run

### 🪟 Windows (MinGW/GCC)

```
gcc scheduling.c -o scheduling
./scheduling
```

### 🐧 Linux / macOS

```
gcc scheduling.c -o scheduling
./scheduling
```

---

## 📂 Files

| File           | Description           |
| -------------- | --------------------- |
| `scheduling.c` | Main program file     |
| `README.md`    | Project documentation |

---

## 📘 Concepts Covered

* CPU Scheduling
* Waiting Time & Turnaround Time
* Gantt Chart Representation
* Preemptive & Non-Preemptive Scheduling
* Time Quantum (Round Robin)

---

## 🚀 Future Enhancements

* Preemptive SJF (SRTF)
* Preemptive Priority Scheduling
* Graphical Gantt Chart
* Support for more processes

---
