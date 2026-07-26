# Roadmap Status Guide

> **For Agents:** Read this file at the start of every session. Do NOT re-scan the entire repo.
> **Last updated:** 2026-07-27

---

## Current Focus

| # | Course | Type | Repo Folder | Notes |
|---|--------|------|-------------|-------|
| 09 | Foundations Level 2 | Theory | `09_Foundations_Level_2/` | 4 md files done |
| 10 | OOP as it Should Be (Concepts) | Mixed | _(not created yet)_ | Theory + practical |

---

## Course Status (3 states only)

### ✅ Completed (01–08)

| # | Official Name | Summary | Repo Folder |
|---|--------------|---------|-------------|
| 01 | Programming Foundations Level 1 | Programming mindset and how computers work | — |
| 02 | Algorithms & Problem-Solving Level 1 | First steps in algorithmic thinking and problem solving | — |
| 03 | Introduction to Programming with C++ Level 1 | Syntax, control flow, functions, structs | `03 _Introduction_to_Programming_with_CPP_Level_1/` |
| 04 | Algorithms Level 1 (Solutions) | Solutions and explanations for Level 1 problems | — |
| 05 | Algorithms & Problem-Solving Level 2 | Advanced algorithms, arrays, optimizations | `05_Algorithms_Problem_Solving_Level_2/` |
| 06 | Introduction to Programming Using C++ Level 2 | Debugging, pointers, memory, vectors, files | `06_Introduction_to_Programming_Using_CPP_Level_2/` |
| 07 | Algorithms & Problem Solving Level 3 | 2D matrices, strings, flat-file databases | `07_Algorithms_and_Problem_Solving_Level_3/` |
| 08 | Algorithms & Problem Solving Level 4 | Date/time algorithms, periods, validation | `08_Algorithms_and_Problem_Solving_Level_4/` |

### ⏳ In Progress (09–10)

| # | Official Name | Type |
|---|--------------|------|
| 09 | Foundations Level 2 | Theory |
| 10 | OOP as it Should Be (Concepts) | Mixed |

### 🔒 Not Started (11–24)

| # | Official Name |
|---|--------------|
| 11 | OOP as it Should Be (Applications) |
| 12 | Data Structures - Level 1 |
| 13 | Algorithms & Problem Solving Level 5 |
| 14 | C# - Level 1 |
| 15 | Database Level 1 - SQL (Concepts and Practice) |
| 16 | OOP As It Should Be In C# |
| 17 | Database - SQL (Projects & Practice) |
| 18 | C# & Database Connectivity (ADO.NET) |
| 19 | Full Real Project - DVLD |
| 20 | C# Programming Level 2 |
| 21 | Database Level 2 - Concepts & T-SQL |
| 22 | Data Structures Level 2 in C# |
| 23 | Algorithms Level 6 |
| 24 | Windows Services |

---

## Content Types — How to Write Docs

### Type 1: Problems-Only (e.g. 05, 07, 08)

**Folder structure:**
```
08_Algorithms_and_Problem_Solving_Level_4/
├── 08_Algorithms_Level_4.md    ← all problems in one file
├── #01_NumberToText.cpp
└── ...
```

**Per-problem format inside the MD:**
```markdown
<div dir="rtl">

## 🧩 Problem #01: Title
### 📝 وصف المشكلة (Problem Description)
...
### 💡 الفكرة البرمجية (Logic Breakdown)
...
### 💻 الكود المعتمد (Solution)
<div dir="ltr">

```cpp
...
```

</div>
```

**Workflow:** User provides video explanation → Agent adds/updates section in MD + links `.cpp` file.

---

### Type 2: Theory-Only (e.g. 09)

**Folder structure:**
```
09_Foundations_Level_2/
├── 00_Introduction.md
├── 01_Networks_And_MAN.md
└── ...
```

**Format rules:**
- `<div dir="rtl">` wrapper
- Headings: `# الفصل` / `## 📝 الدرس`
- Tables, ASCII diagrams, practical examples
- NO Problem/Solution structure
- NO `.cpp` files unless user requests

**Workflow:** User provides video content → Agent creates/updates topic MD file.

---

### Type 3: Mixed — Theory + Practical (e.g. 06, 10)

**Folder structure:**
```
06_Introduction_to_Programming_Using_CPP_Level_2/
├── 01_Debugging_Basics.md      ← theory lessons
├── 02_Misc_and_Functions.md
├── ...
├── train.cpp                   ← practice code
└── Lib.h
```

**Theory lesson format:**
- `<div dir="rtl">`
- `## 📝 الدرس`: concept explanation
- Comparison tables, tips
- May include code snippets (not numbered problems)

**+ Practical:** separate `.cpp` files or projects in `00_Projects/`

**Workflow:** Agent decides first — theory lesson (→ new md), problem (→ Problems format), or project (→ `00_Projects/`).

---

## Agent Conventions

| Rule | Value |
|------|-------|
| Language | Arabic (RTL) for explanations, LTR for code |
| Commit style | `docs(courseXX): ...` / `feat(project): ...` / `fix(...): ...` |
| Folder naming | `XX_Course_Name` or `00_Projects/XX_Name` |
| Session start | "Read ROADMAP_STATUS.md and continue from [course/lesson]" |

## Projects

| Project | Folder | Course |
|---------|--------|--------|
| Stone Paper Scissors | `00_Projects/01_Stone_Paper_Scissors/` | Early C++ |
| Math Game | `00_Projects/02_Math_Game/` | Early C++ |
| Bank System | `00_Projects/03_Bank_System/` | Algorithms L3 |
| ATM System | `00_Projects/04_ATM_System/` | Algorithms L3+ |

## Do NOT Re-Read Each Session

- Completed course folders (03, 05–08)
- Individual problem `.cpp` files
- Project source code unless actively editing
