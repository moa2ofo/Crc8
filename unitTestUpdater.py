import subprocess

def run_git_diff():
    try:
        result = subprocess.run(
            ["sh", "-c", "git diff HEAD~1 HEAD"],
            capture_output=True,
            text=True,
            check=True
        )
        print(result.stdout)
    except Exception as e:
        print("Error:", e)

run_git_diff()
