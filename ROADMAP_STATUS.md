# Roadmap Status Guide

> **For Agents:** Read this file at the start of every session. Do NOT re-scan the entire repo.
> **Last updated:** 2026-07-29

---

## Current Focus

| # | Course | Type | Repo Folder | Guide | Notes |
|---|--------|------|-------------|-------|-------|
| 09 | Foundations Level 2 | Theory | `09_Foundations_Level_2/` | not created | 4 md files done |
| 10 | OOP as it Should Be (Concepts) | Mixed | _(not created yet)_ | not created | Theory + practical |

---

## Per-Course Workflow

Use this workflow in **every active course chat**. Course-specific details live in `_COURSE_GUIDE.md` inside the course folder — NOT here.

### Session Start

```
Read ROADMAP_STATUS.md + _COURSE_GUIDE.md (if exists) and continue from [course/lesson/video]
```

### Phase A — Setup (once per course)

**Input:** User sends all video titles for the course.

**Output:** `_COURSE_GUIDE.md` ONLY — no empty md/cpp files.

The guide must contain:
1. **Topic Groups** — related videos grouped by subject
2. **File Map** — planned file paths (not created yet)
3. **Progress Table** — each video: `[ ]` pending / `[x]` done
4. **Content Type** per video: `theory` / `project-req` / `project-sol` / `skip`

**Rules:**
- Show the topic plan to the user and wait for approval before Phase B
- **Create-on-demand:** do NOT create empty topic files upfront
- `_COURSE_GUIDE.md` is the skeleton; real files are created when content arrives

### Phase B — Theory Videos

**Input:** Content for one video (transcript/notes).

**Agent:**
1. Read `_COURSE_GUIDE.md` → find target file from File Map
2. **Create** the md file on first use, or **append** a section if multiple videos share one topic
3. Mark video `[x]` in the guide
4. **Never write content for a video the user has not sent**

**Theory lesson format (Mixed courses):**

```markdown
<div dir="rtl">

# [Topic Title]

## 📝 الدرس: [Video Title]
<!-- Video NN: [filename] -->

[Structured Arabic explanation from transcript]

### 💡 Key Concepts
- ...

### 📌 Examples
...
```

### Phase B — Project Videos (Requirements → Solution → Compare)

**Step 1 — Requirements video (`project-req`):**
- Write `projects/ProjectName/Requirements.md` only
- Mark video done in guide
- **Stop and tell user:** implement on your own, then send Solution video + doctor code (+ your code if you want comparison)

**Step 2 — User implements independently**
- Agent does NOT write `My_Solution.cpp` — that is the user's work

**Step 3 — Solution video (`project-sol`):**
- **Input:** Solution video content + `Doctor_Solution.cpp`
- **Optional input:** `My_Solution.cpp` (user's solution)
- **Agent writes:**
  - `Doctor_Solution.cpp`
  - `Solution_Notes.md` (explanation from video)
  - Comparison section in `Solution_Notes.md` if user sent their code:

```markdown
## 🔍 مقارنة: حلي vs حل الدكتور

| النقطة | حلي | الدكتور | ملاحظة |
|--------|-----|---------|--------|
| Structure | ... | ... | ... |

### ✅ اللي عملته صح
### ⚠️ اللي يختلف (مش غلط بالضرورة)
### 💡 اللي ممكن تتعلمه من حل الدكتور
```

### Topic Grouping Rules

| Rule | Example |
|------|---------|
| Consecutive videos on same topic → one md file | Videos 02–05 → `02_Classes_And_Objects.md` |
| Requirements + Solution → one project folder | Videos 11–12 → `projects/Calculator/` |
| Homework solution → same topic or project folder | Video 36 → inside nested classes topic |
| Closing/thank you video → mark `skip`, no file | Video 43 → `[x]` in guide only |

### File Naming

- Topic files: `NN_Topic_Name.md` (English filenames, Arabic content)
- Project folders: `projects/ProjectName/` (PascalCase or Snake_Case)
- Always wrap Arabic content in `<div dir="rtl">`, code in `<div dir="ltr">`

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

**Workflow:** Follow Per-Course Workflow Phase A/B. User provides video content → Agent adds/updates section in MD + links `.cpp` file.

---

### Type 2: Theory-Only (e.g. 09)

**Folder structure:**
```
09_Foundations_Level_2/
├── _COURSE_GUIDE.md
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

**Workflow:** Follow Per-Course Workflow Phase A/B. User provides video content → Agent creates/updates topic MD file on demand.

---

### Type 3: Mixed — Theory + Practical (e.g. 06, 10)

**Folder structure:**
```
10_OOP_Concepts/
├── _COURSE_GUIDE.md
├── 01_What_Is_OOP.md              ← theory (create on demand)
├── 02_Classes_And_Objects.md
├── projects/
│   └── Calculator/
│       ├── Requirements.md
│       ├── Doctor_Solution.cpp
│       ├── My_Solution.cpp        ← user-provided (optional)
│       └── Solution_Notes.md
└── train.cpp                      ← small inline practice (optional)
```

**Theory:** same format as Phase B theory above.

**Course projects:** use `projects/ProjectName/` inside the course folder — NOT `00_Projects/`.

**Workflow:**
1. Phase A → create `_COURSE_GUIDE.md` only
2. Theory videos → create/update md on demand
3. Project Requirements → write `Requirements.md`, pause for user implementation
4. Project Solution → write doctor code + notes + optional comparison

---

## Project Placement Rules

| Type | Location | Examples |
|------|----------|----------|
| Course learning projects | `XX_Course/projects/ProjectName/` | Calculator, Person Exercise, String Library |
| Portfolio / roadmap projects | `00_Projects/XX_Name/` | Bank System, ATM, DVLD |

**Rule:** If the project is taught in course videos (Requirements/Solution) → course folder. If it is a standalone portfolio milestone in README → `00_Projects/`.

**Course project template:**
```
XX_Course/projects/ProjectName/
├── Requirements.md
├── Doctor_Solution.cpp
├── My_Solution.cpp          ← optional, user-provided
└── Solution_Notes.md        ← includes comparison if My_Solution sent
```

---

## Agent Conventions

| Rule | Value |
|------|-------|
| Language | Arabic (RTL) for explanations, LTR for code |
| Commit style | `docs(courseXX): ...` / `feat(project): ...` / `fix(...): ...` |
| Folder naming | `XX_Course_Name` or `00_Projects/XX_Name` |
| Session start | "Read ROADMAP_STATUS.md + _COURSE_GUIDE.md and continue from [course/lesson]" |
| After commit | Update Current Focus notes (md files done, guide status) |

## Portfolio Projects (`00_Projects/`)

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
- Empty or not-yet-created files listed only in `_COURSE_GUIDE.md` File Map
