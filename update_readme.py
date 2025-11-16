import os
from datetime import datetime

def count_files(folder):
    if not os.path.exists(folder):
        return 0
    return len([f for f in os.listdir(folder) if os.path.isfile(os.path.join(folder, f))])

# Folder paths
easy_path = "Easy"
medium_path = "Medium"
hard_path = "Hard"

# Count files
easy_count = count_files(easy_path)
medium_count = count_files(medium_path)
hard_count = count_files(hard_path)

total_solved = easy_count + medium_count + hard_count

# Generate table for each level
def generate_table(folder):
    if not os.path.exists(folder):
        return ""
    files = sorted(os.listdir(folder))
    table = f"### {folder} Problems\n\n"
    table += "| Problem | Link |\n"
    table += "|--------|------|\n"
    for f in files:
        name = os.path.splitext(f)[0]
        table += f"| {name} | ./{folder}/{f} |\n"
    table += "\n"
    return table

easy_table = generate_table("Easy")
medium_table = generate_table("Medium")
hard_table = generate_table("Hard")

# Final README content
readme_content = f"""
# LeetCode Solutions

Updated automatically using Python script.

## Summary
- **Total Problems Solved:** {total_solved}
- **Easy:** {easy_count}
- **Medium:** {medium_count}
- **Hard:** {hard_count}

---

## 📁 Problem Tables

{easy_table}
{medium_table}
{hard_table}

---

### ⏱ Last Updated
{datetime.now().strftime("%Y-%m-%d %H:%M:%S")}
"""

# Write to README.md
with open("README.md", "w", encoding="utf-8") as f:
    f.write(readme_content)

print("README.md updated successfully!")
