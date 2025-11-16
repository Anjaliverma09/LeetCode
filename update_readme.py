import os
import json
from datetime import datetime

# Paths
README_PATH = "README.md"
TOPICS_FILE = "topics.json"
BASE_FOLDERS = ["Easy", "Medium", "Hard"]

# Load topics mapping
if os.path.exists(TOPICS_FILE):
    with open(TOPICS_FILE, "r", encoding="utf-8") as f:
        topics_map = json.load(f)
else:
    topics_map = {}

def count_files(folder):
    if not os.path.exists(folder):
        return 0
    return len([f for f in os.listdir(folder) if os.path.isfile(os.path.join(folder, f))])

def slug_from_filename(filename):
    # Assuming filename like "1-Two-Sum.cpp"
    parts = filename.split("-", 1)
    if len(parts) != 2:
        return None
    num, rest = parts
    slug = rest.replace(".cpp", "").replace(" ", "-").lower()
    return slug

def generate_table(folder):
    if not os.path.exists(folder):
        return ""
    files = sorted(os.listdir(folder))
    table = f"### {folder} Problems ({len(files)})\n\n"
    table += "| # | Problem | Topics | Link |\n"
    table += "|---|---------|--------|------|\n"
    for f in files:
        name = os.path.splitext(f)[0]  # e.g. "1-Two-Sum"
        num = name.split("-")[0]
        slug = slug_from_filename(f)
        topics = topics_map.get(f, [])
        topics_str = ", ".join(topics) if topics else "-"
        if slug:
            link = f"https://leetcode.com/problems/{slug}/"
        else:
            link = "-"
        table += f"| {num} | {name} | {topics_str} | [Link]({link}) |\n"
    table += "\n"
    return table

def generate_readme():
    easy_count = count_files("Easy")
    medium_count = count_files("Medium")
    hard_count = count_files("Hard")
    total = easy_count + medium_count + hard_count

    easy_table = generate_table("Easy")
    medium_table = generate_table("Medium")
    hard_table = generate_table("Hard")

    last_update = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    content = f"""# LeetCode Solutions

**Total Problems Solved**: {total}  
- Easy: {easy_count}  
- Medium: {medium_count}  
- Hard: {hard_count}  

---

{easy_table}

{medium_table}

{hard_table}

---

_Last Updated: {last_update}_  
"""

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(content)

if __name__ == "__main__":
    generate_readme()
    print("README updated with topics!")
