import os
import re
import sys

# Customize as needed
SKETCH_DIR = "../examples"
BANNED_WORDS = ["alpha", "alpha-board", "alpha_board", "alpha board"]
MAX_WORDS = 3
VALID_NAME_REGEX = re.compile(r'^[a-z0-9]+(-[a-z0-9]+){0,2}$')  # 1 to 3 lowercase words, separated by -

def is_name_valid(name):
    # Check if name contains banned words
    for banned in BANNED_WORDS:
        if banned in name:
            return False, f"contains banned word '{banned}'"

    # Check if name matches the lowercase-hyphen rule
    if not VALID_NAME_REGEX.fullmatch(name):
        return False, "must be all lowercase, hyphen-separated, and max 3 words"

    return True, ""

def check_sketch_names(base_dir):
    issues = []
    for folder_name in os.listdir(base_dir):
        sketch_path = os.path.join(base_dir, folder_name)
        if not os.path.isdir(sketch_path):
            continue

        ino_file = os.path.join(sketch_path, folder_name + ".ino")
        if not os.path.isfile(ino_file):
            issues.append((folder_name, "missing matching .ino file"))
            continue

        valid, reason = is_name_valid(folder_name)
        if not valid:
            issues.append((folder_name, reason))

    return issues

def main():
    if not os.path.isdir(SKETCH_DIR):
        print(f"❌ '{SKETCH_DIR}' folder not found.")
        sys.exit(1)

    issues = check_sketch_names(SKETCH_DIR)

    if not issues:
        print("✅ All sketch names follow the naming conventions.")
    else:
        print("❌ Naming convention issues found:\n")
        for folder, issue in issues:
            print(f"  - {folder}: {issue}")
        sys.exit(1)

if __name__ == "__main__":
    main()
