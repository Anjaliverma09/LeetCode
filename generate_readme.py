import os

# Folders to scan
DIFFICULTIES = ["Easy", "Medium", "Hard"]

README_PATH = "README.md"

def parse_filename(filename):
    """
    Converts 1-TwoSum.cpp → number=1, title=Two Sum, slug=two-sum
    """
    name = filename.replace(".cpp", "")
    parts = name.split("-", 1)
    number = parts[0]
    title_raw = parts[1]

    # Convert "TwoSum" → "Two Sum"
    title = ""
    for ch in title_raw:
        if ch.isupper() and title:
            title += " "
        title += ch

    # Create slug for LeetCode URL: "Two Sum" → "two-sum"
    slug = title.lower().replace(" ", "-")

    return number, title, slug


def generate_table():
    rows = []
    for diff in DIFFICULTIES:
        folder = os.path.join(diff)
        if not os.path.exists(folder):
            continue

        for file in os.listdir(folder):
            if not file.endswith(".cpp"):
                continue

            num, title, slug = parse_filename(file)

            row = f"| {num} | [{title}](https://leetcode.com/problems/{slug}/) | [C++]({diff}/{file}) | {diff} |"
            rows.append((int(num), row))

    # Sort rows by problem number
    rows.sort(key=lambda x: x[0])

    return [r[1] for r in rows]


def update_readme():
    rows = generate_table()

    content = f"""# LeetCode Solutions 🧠

Automatically generated README from script.

## 🧩 Problems Table

| # | Problem | Solution | Difficulty |
|---|---------|----------|------------|
"""

    for row in rows:
        content += row + "\n"

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(content)

    print("README.md updated successfully!")


if __name__ == "__main__":
    update_readme()
