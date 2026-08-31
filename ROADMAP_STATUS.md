# Roadmap Status Guide

> **For Agents:** Read this file at the start of every session. Do NOT re-scan the entire repo.
> **Last updated:** 2026-07-29 (folder structure v2)

---

## Current Focus

| # | Course | Type | Repo Folder | Guide | Notes |
|---|--------|------|-------------|-------|-------|
| 09 | Foundations Level 2 | Theory | `09_Foundations_Level_2/` | not created | 4 md files done |
| 10 | OOP as it Should Be (Concepts) | Mixed | `10_OOP_Concepts/` | ✅ Phase B | 5/43 videos — next: Properties (06) |

---

## Per-Course Workflow

Use this workflow in **every active course chat**. Course-specific details live in `_COURSE_GUIDE.md` inside the course folder — NOT here.

### Session Start

```
Read ROADMAP_STATUS.md + _COURSE_GUIDE.md (if exists) and continue from [course/lesson/video]
```

### Phase A — Setup (once per course)

**Input:** User sends all video titles for the course.

**Agent creates the course folder + subfolders + guide.** User does NOT need to pre-create the folder.

**Output:**

| What | Created in Phase A? |
|------|---------------------|
| Course folder `XX_Course_Name/` | Yes |
| `_COURSE_GUIDE.md` | Yes |
| Empty subfolders (`practice/`, `projects/`, `problems/`) | Yes — per course type |
| Topic md files, cpp files, problem READMEs | **No** — create-on-demand in Phase B |

The guide must contain:
1. **Topic Groups** — related videos grouped by subject
2. **File Map** — planned file paths (not created yet)
3. **Progress Table** — each video: `[ ]` pending / `[x]` done
4. **Content Type** per video: `theory` / `practice` / `project-req` / `project-sol` / `problem` / `skip`

**Rules:**
- Show the topic plan to the user and wait for approval before Phase B
- **Create-on-demand:** do NOT create empty md/cpp content files upfront
- `_COURSE_GUIDE.md` is the skeleton; real content files are created when content arrives
- If user pre-created a folder with wrong name → rename to `XX_Course_Name/` and move files into correct subfolders

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

### Phase B — Practice Videos (inline exercises)

**When:** User applies along with a theory video (e.g. Course 10 videos 02, 08).

**Agent:**
- Save user's or doctor's practice code in `practice/#NN_Topic_Task.cpp`
- Link the file in the corresponding theory md section
- Agent does NOT create practice files until user sends code or asks to save it

### Topic Grouping Rules

| Rule | Example |
|------|---------|
| Consecutive videos on same topic → one md file | Videos 02–05 → `02_Classes_And_Objects.md` |
| Inline exercise with video → `practice/` | Video 02 → `practice/#02_ClassesAndObjects_Task.cpp` |
| Requirements + Solution → `projects/` | Videos 11–12 → `projects/Calculator/` |
| End-of-course capstone project → `00_Projects/` | DVLD, future large projects |
| Homework solution → same topic or project folder | Video 36 → nested classes topic or project |
| Closing/thank you video → mark `skip`, no file | Video 43 → `[x]` in guide only |

### File Naming

- Topic files: `NN_Topic_Name.md` (English filenames, Arabic content)
- Practice files: `practice/#NN_Topic_Task.cpp`
- Course projects: `projects/ProjectName/`
- Problem folders: `problems/#NN_ProblemName/`
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

## Course Folder Structures (by type)

### Type 1: Problems-Only (e.g. 05, 07, 08)

**Phase A creates:**
```
08_Algorithms_Level_4/
├── _COURSE_GUIDE.md
└── problems/                     ← empty folder, ready
```

**Phase B creates (one folder per problem):**
```
08_Algorithms_Level_4/
├── _COURSE_GUIDE.md
└── problems/
    ├── #01_NumberToText/
    │   ├── README.md             ← explanation (Problem Description + Logic Breakdown)
    │   └── #01_NumberToText.cpp  ← solution code
    ├── #02_LeapYear/
    │   ├── README.md
    │   └── #02_LeapYear.cpp
    └── ...
```

**Per-problem README.md format:**
```markdown
<div dir="rtl">

# 🧩 Problem #01: Number To Text

### 📝 وصف المشكلة (Problem Description)
...

### 💡 الفكرة البرمجية (Logic Breakdown)
...

### 💻 الكود
See `#01_NumberToText.cpp`
```

**Legacy note:** Courses 05–08 already committed use one combined `.md` + cpp at root. Do NOT migrate unless user asks. **New problem courses** (and new problems added later) use the `problems/#NN_Name/` structure above.

**Workflow:** Phase A → folder + `problems/` + guide. Phase B → create problem folder on demand when user sends content.

---

### Type 2: Theory-Only (e.g. 09)

**Phase A creates:**
```
09_Foundations_Level_2/
├── _COURSE_GUIDE.md
└── (no subfolders needed)
```

**Phase B creates topic md files on demand:**
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

**Phase A creates:**
```
10_OOP_Concepts/
├── _COURSE_GUIDE.md
├── practice/                     ← empty, for inline video exercises
└── projects/                     ← empty, for course projects (Calculator, etc.)
```

**Phase B fills on demand:**
```
10_OOP_Concepts/
├── _COURSE_GUIDE.md
├── 01_What_Is_OOP.md
├── 02_Classes_And_Objects.md
├── practice/
│   ├── #02_ClassesAndObjects_Task.cpp
│   └── #08_PropertiesSetAndGetThrough_Task.cpp
└── projects/
    └── Calculator/
        ├── Requirements.md
        ├── Doctor_Solution.cpp
        ├── My_Solution.cpp        ← user-provided (optional)
        └── Solution_Notes.md
```

| Subfolder | Purpose | Examples |
|-----------|---------|----------|
| `practice/` | Small exercises done alongside a theory video | Video 02 task, Video 08 task |
| `projects/` | Course projects with Requirements/Solution videos | Calculator, String Library, Person Exercise |

**Theory:** same format as Phase B theory above.

**Workflow:**
1. Phase A → create folder + `practice/` + `projects/` + `_COURSE_GUIDE.md`
2. Theory videos → create/update md on demand
3. Practice videos → save cpp in `practice/` when user sends code
4. Project Requirements → write `projects/ProjectName/Requirements.md`, pause
5. Project Solution → doctor code + notes + optional comparison

---

## Project Placement Rules

| Type | Location | When | Examples |
|------|----------|------|----------|
| Inline practice | `XX_Course/practice/` | Exercise during a theory video | `#02_ClassesAndObjects_Task.cpp` |
| Course project | `XX_Course/projects/ProjectName/` | Project taught inside course videos (Req/Sol) | Calculator, String Library, Person Exercise |
| Portfolio / capstone | `00_Projects/XX_Name/` | Large end-of-roadmap project, outside course folder | Bank System, ATM, DVLD |

**Decision tree:**
1. Small exercise while watching a lesson? → `practice/`
2. Formal project with Requirements + Solution videos inside a course? → `projects/` inside course folder
3. Large standalone capstone at end of roadmap stage? → `00_Projects/` (NOT inside course folder)

**Course project template (`projects/`):**
```
XX_Course/projects/ProjectName/
├── Requirements.md
├── Doctor_Solution.cpp
├── My_Solution.cpp          ← optional, user-provided
└── Solution_Notes.md        ← includes comparison if My_Solution sent
```

**Portfolio project template (`00_Projects/`):**
```
00_Projects/XX_ProjectName/
├── README.md
├── [source files]
└── ...
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
