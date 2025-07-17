import os
import re
import sys


SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
EXAMPLES_DIR = os.path.abspath(os.path.join(SCRIPT_DIR, "../examples"))

# Required header pattern
HEADER_PATTERN = re.compile(
    r'/\*\*\s*\n\s*\* Title: .+\n\s*\* Description: .+\n\s*',
    re.MULTILINE
)

def check_file_structure(filepath):
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()

    lines = content.splitlines()

    errors = []

    # 1. Check header comment
    if not HEADER_PATTERN.search(content):
        errors.append("Missing or malformed header comment")

    # 2. Check includes
    includes = [line for line in lines if line.strip().startswith("#include")]
    if not any('"alpha.h"' in line for line in includes):
        errors.append('Missing #include "alpha.h"')
    if any("Arduino.h" in line for line in includes):
        errors.append("Do not include Arduino.h")

    # 3. Check for structure markers
    expected_markers = [
        "void setup()",
        "void loop()",
    ]

    missing = [marker for marker in expected_markers if marker not in content]
    for m in missing:
        errors.append(f"Missing section: {m}")

    return errors

def check_examples_structure():
    all_errors = {}

    for sketch_dir in os.listdir(EXAMPLES_DIR):
        sketch_path = os.path.join(EXAMPLES_DIR, sketch_dir)
        if not os.path.isdir(sketch_path):
            continue

        ino_path = os.path.join(sketch_path, sketch_dir + ".ino")
        if not os.path.isfile(ino_path):
            continue

        errors = check_file_structure(ino_path)
        if errors:
            all_errors[ino_path] = errors

    return all_errors

def main():
    if not os.path.isdir(EXAMPLES_DIR):
        print(f"❌ '{EXAMPLES_DIR}' directory not found.")
        sys.exit(1)

    errors = check_examples_structure()

    if not errors:
        print("✅ All sketches follow the required structure.")
    else:
        print("❌ Structural issues found:\n")
        for file, issues in errors.items():
            print(f"{file}:")
            for err in issues:
                print(f"  - {err}")
            print()
        sys.exit(1)

if __name__ == "__main__":
    main()
