import os
import subprocess
import sys

def build_extension():
    try:
        import indexed_map
        print("Extension 'indexed_map' already built.")
    except ImportError:
        print("Building extension 'indexed_map'...")
        subprocess.check_call([sys.executable, "setup.py", "build_ext", "--inplace"])

#if __name__ == "__main__":
build_extension()
