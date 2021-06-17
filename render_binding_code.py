import sys
import pprint
import argparse

def render(code):
    with open(code, 'r') as code_file:
        p = pprint.PrettyPrinter()
        p.pprint(code_file.readlines())



def main():
    args = argparse.ArgumentParser()
    args.add_argument(
        "-i",
        "--code",
        required=True,
        action="store",
        dest="code"
    )
    opts = args.parse_args(sys.argv[1:])
    render(opts.code)

if __name__ == '__main__':
    main()
