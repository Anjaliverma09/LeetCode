import os
from datetime import datetime

# Detect files inside each folder
def get_problems(folder):
    problems = []
    if not os.path.exists(folder):
        return problems

    for file in sorted(os.listdir(folder)):
        if file.endswith(".cpp") or file.endswith(".py") or file.endswith(".java"):
            name = os.path.splitext(file)[0]  

            # Expected filename: "217-ContainsDuplicate"
            if "-" in name:
                num, title = name.split("-", 1)
            else:
                num = ""
                title = name

            title_clean = title.replace("_", " ")
            solution_link = f"./{folder}/{file}"
            problems.append((num, title_clean, solution_link))

    return problems


def generate_table(folder, difficulty):
    problems = get_problems(folder)

    table = f"### {difficulty}\n\n"
    table += "| # | Problem | Solution | Topics | Difficulty |\n"
    table += "|---|---------|----------|--------|------------|\n"

    for num, title, link in problems:
        table += f"| {num} | {title} | [C++]({link}) |  | {difficulty} |\n"

    table += "\n"
    return table


# Count problems
easy = len(get_problems("Easy"))
medium = len(get_problems("Medium"))
hard = len(get_problems("Hard"))
total = easy + medium + hard

# Shields-style badges
progress_section = f"""
## 📊 Progress

![Solved](https://img.shields.io/badge/Solved-{total}-blue)
![Easy](https://img.shields.io/badge/Easy-{easy}-green)
![Medium](https://img.shields.io/badge/Medium-{medium}-orange)
![Hard](https://img.shields.io/badge/Hard-{hard}-red)
"""

# Generate problems section
problems_section = f"""
## 📝 Problems

{generate_table("Easy", "Easy")}
{generate_table("Medium", "Medium")}
{generate_table("Hard", "Hard")}
"""

# Final README content
readme = f"""# LeetCode Solutions

Automatically generated using Python.

{progress_section}

---

{problems_section}

---

### ⏱ Last Updated
{datetime.now().strftime("%Y-%m-%d %H:%M:%S")}
"""

# Write README.md
with open("README.md", "w", encoding="utf-8") as f:
    f.write(readme)

print("README updated successfully!")
