# update_readme.py
# Safe, emoji-free. Generates README.md and a progress bar chart (assets/progress.png).
# Requires: Python 3, matplotlib (Action will install it)

import os
import json
from datetime import datetime

README_PATH = "README.md"
TOPICS_FILE = "topics.json"
ASSETS_DIR = "assets"
GRAPH_PATH = os.path.join(ASSETS_DIR, "progress.png")
FOLDERS = ["Easy", "Medium", "Hard"]

# --- Helpers ---
def ensure_assets_dir():
    if not os.path.exists(ASSETS_DIR):
        os.makedirs(ASSETS_DIR)

def count_files(folder):
    if not os.path.exists(folder):
        return 0
    return len([f for f in os.listdir(folder) if os.path.isfile(os.path.join(folder, f))])

def load_topics():
    if os.path.exists(TOPICS_FILE):
        with open(TOPICS_FILE, "r", encoding="utf-8") as f:
            return json.load(f)
    return {}

def slug_from_filename(filename):
    parts = filename.split("-", 1)
    if len(parts) != 2:
        return None
    slug = parts[1].rsplit(".", 1)[0].strip().replace(" ", "-").lower()
    # make it URL-friendly: remove characters that break
    return "".join(ch for ch in slug if ch.isalnum() or ch == "-" )

def generate_table(folder, topics_map):
    if not os.path.exists(folder):
        return ""
    files = sorted([f for f in os.listdir(folder) if os.path.isfile(os.path.join(folder, f))])
    table = f"### {folder} Problems ({len(files)})\n\n"
    table += "| # | Problem | Topics | Link |\n"
    table += "|---:|---------|--------|------|\n"
    for f in files:
        name = os.path.splitext(f)[0]           # "1-Two-Sum"
        num = name.split("-", 1)[0] if "-" in name else "-"
        topics = topics_map.get(f, [])
        topics_str = ", ".join(topics) if topics else "-"
        slug = slug_from_filename(f)
        if slug:
            link = f"https://leetcode.com/problems/{slug}/"
            link_md = f"[LeetCode]({link})"
        else:
            link_md = "-"
        table += f"| {num} | {name} | {topics_str} | {link_md} |\n"
    table += "\n"
    return table

# --- Graph generation (matplotlib) ---
def generate_progress_graph(easy, medium, hard, out_path):
    try:
        import matplotlib
        matplotlib.use("Agg")
        import matplotlib.pyplot as plt
    except Exception as e:
        print("matplotlib not available:", e)
        return False

    labels = ["Easy", "Medium", "Hard"]
    counts = [easy, medium, hard]

    plt.figure(figsize=(6,3))
    bars = plt.bar(labels, counts)
    plt.title("LeetCode Progress")
    plt.ylabel("Solved problems")
    plt.grid(axis='y', linestyle='--', linewidth=0.4, alpha=0.7)

    # add value labels on bars
    for bar in bars:
        h = bar.get_height()
        plt.text(bar.get_x() + bar.get_width()/2.0, h + 0.1, f"{int(h)}", ha='center', va='bottom', fontsize=9)

    plt.tight_layout()
    plt.savefig(out_path, dpi=150)
    plt.close()
    return True

# --- Main README generation ---
def generate_readme():
    topics_map = load_topics()

    easy_count = count_files("Easy")
    medium_count = count_files("Medium")
    hard_count = count_files("Hard")
    total = easy_count + medium_count + hard_count
    templates_count = count_files("Templates")

    easy_table = generate_table("Easy", topics_map)
    medium_table = generate_table("Medium", topics_map)
    hard_table = generate_table("Hard", topics_map)

    ensure_assets_dir()
    graph_ok = generate_progress_graph(easy_count, medium_count, hard_count, GRAPH_PATH)

    last_update = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    # Build README content
    readme = f"""# LeetCode Solutions

> Auto-generated — updates on each push.

## Summary
- **Total problems solved:** {total}  
- **Easy:** {easy_count}  
- **Medium:** {medium_count}  
- **Hard:** {hard_count}  
- **Templates:** {templates_count}

_Last updated: {last_update}_

"""

    if graph_ok:
        readme += f"\n![Progress]({GRAPH_PATH})\n\n"

    readme += "## Problems by Difficulty\n\n"
    readme += easy_table
    readme += medium_table
    readme += hard_table

    readme += "\n---\n"
    readme += "## Connect\n\n"
    readme += "- GitHub: https://github.com/Anjaliverma09\n"
    readme += "- LeetCode: https://leetcode.com/anjaliverma09\n"
    readme += "- LinkedIn: https://linkedin.com/in/anjaliverma09\n"

    # write file
    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(readme)

    print("README and graph generated.")
    return True

if __name__ == "__main__":
    generate_readme()
