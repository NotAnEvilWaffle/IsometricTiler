import os
import sys

# Set your namespace
NAMESPACE = "naggl"

def wrap_namespace(file_path):
    with open(file_path, "r") as f:
        lines = f.readlines()

    new_lines = []
    namespace_added = False
    last_include_index = -1

    # Find the last include
    for i, line in enumerate(lines):
        new_lines.append(line)
        if line.startswith("#include"):
            last_include_index = i

    # Insert namespace after the last include
    if last_include_index != -1:
        new_lines.insert(last_include_index + 1, f"\nnamespace {NAMESPACE} {{\n")
        namespace_added = True

    if namespace_added:
        new_lines.append("}\n")  # Close the namespace at the end

    with open(file_path, "w") as f:
        f.writelines(new_lines)

def process_files(path):
    if os.path.isfile(path):
        wrap_namespace(path)
        print(f"Processed {path}")
    elif os.path.isdir(path):
        for root, _, files in os.walk(path):
            for file in files:
                if file.endswith(".cpp") or file.endswith(".h"):
                    file_path = os.path.join(root, file)
                    wrap_namespace(file_path)
                    print(f"Processed {file_path}")
    else:
        print("Error: Path does not exist.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python wrap_namespace.py <path/to/file_or/directory>")
        sys.exit(1)

    path = sys.argv[1]
    process_files(path)

