import sys
import argparse
import os
import glob
from IPython.display import Markdown, display_markdown
cpp_md = """```cpp\n{}\n```\n<hr>"""

def render(code_dir):
    for cpp_file in glob.glob(os.sep.join(code_dir,"*.cpp")):
        with open(cpp_file, 'r') as code_file:
            code = code_file.readlines()
            cpp_file_name = os.path.basename(cpp_file)
            print("Binding Code File: %s" % cpp_file_name)
            display_markdown(Markdown(cpp_md.format(code)))


def main():
    args = argparse.ArgumentParser()
    args.add_argument(
        "-i",
        "--code_dir",
        required=True,
        action="store",
        dest="code"
    )
    opts = args.parse_args(sys.argv[1:])
    render(opts.code)

if __name__ == '__main__':
    main()
