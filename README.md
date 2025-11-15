import os
import re

# Folders to scan
FOLDERS = ["Easy", "Medium", "Hard"]

def format_title(title):
    # Convert "TwoSum" → "Two Sum"
    return re.sub(r'(?<!^)([A-Z])', r' \1', title)

def get_leetcode_url(title):
    # Convert "Two Sum" → "two-sum"
    slug = title.lower().replace(" ", "-")
    return f"https://leetcode.com/problems/{slug}/"

def scan_folder(folder):
    rows = []
    path = f"./{folder}"

    if not os.path.isdir(path):
        return rows

    for file in os.listdir(path):
        if not file.endswith(".cpp"):
            continue

        # Filename: "1-TwoSum.cpp"
        match = re.match(r"(\d+)-([A-Za-z0-9]+)\.cpp", file)
        if not match:
            continue

        number = match.group(1)
        raw_title = match.group(2)
        title = format_title(raw_title)
        solution_path = f"./{folder}/{file}"
        leetcode_url = get_leetcode_url(title)

        rows.append({
            "number": int(number),
            "title": title,
            "url": leetcode_url,
            "solution": solution_path,
            "difficulty": folder
        })

    return rows


def generate_readme():
    all_rows = []

    for folder in FOLDERS:
        all_rows.extend(scan_folder(folder))

    # Sort by problem number
    all_rows.sort(key=lambda x: x["number"])

    # Write README.md
    with open("README.md", "w", encoding="utf-8") as f:
        f.write("# LeetCode Solutions 🧠\n")
        f.write("Automatically generated README. Updated whenever new problems are added.\n\n")

        f.write("## 🧩 Problems Solved\n\n")

        f.write("| # | Problem | Solution | Difficulty |\n")
        f.write("|---|---------|----------|------------|\n")

        for r in all_rows:
            f.write(f"| {r['number']} | [{r['title']}]({r['url']}) | [C++]({r['solution']}) | {r['difficulty']} |\n")

    print("README.md updated successfully!")


if __name__ == "__main__":
    generate_readme()
