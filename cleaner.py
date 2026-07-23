import sys
from pathlib import Path


def clean_dot_exe_file():
    folder = Path(__file__).resolve().parent
    deleted_files = []
    skipped_files = []
    current_python = Path(sys.executable).resolve()

    for file_path in folder.rglob("*.exe"):
        if file_path.is_file() and file_path.suffix.lower() == ".exe":
            resolved_file = file_path.resolve()

            if resolved_file == current_python:
                skipped_files.append(f"{file_path.relative_to(folder)} (currently in use)")
                continue

            try:
                file_path.unlink()
                deleted_files.append(str(file_path.relative_to(folder)))
            except PermissionError:
                skipped_files.append(f"{file_path.relative_to(folder)} (access denied)")

    return deleted_files, skipped_files



if __name__ == "__main__":
    deleted_files, skipped_files = clean_dot_exe_file()
    print(f"Deleted {len(deleted_files)} .exe file(s) from this folder.")
    if skipped_files:
        print("Skipped:")
        for file_name in skipped_files:
            print(f"- {file_name}")
