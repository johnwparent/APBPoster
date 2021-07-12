import subprocess
import os, sys
import yaml

def generate_descriptors(wrapper, config):
    if not wrapper:
        raise RuntimeError("Wrapper is not populated")
    with open("sample_wrapper.yaml","w") as wrapper_yml:
        yaml.dump(yaml.load(wrapper),wrapper_yml)
    if not config:
        return
    else:
        with open("sample_conf.yml","w") as cnf_yml:
            yaml.dump(yaml.load(config),cnf_yml)

def cmake_variables(**kwargs):
    vars = []
    for arg in kwargs:
        vars.append("-D{}={}".format(arg,kwargs[arg]))
    return vars

def cmake_script_drive(script, args):
    invoke_cmake = ["cmake", *args, "-P", script]
    subprocess.call(invoke_cmake)

def configure_cmakelists(script,**kwargs):
    vars = cmake_variables(**kwargs)
    cmake_script_drive(script,vars)

def configure_sample_cmakelists(**kwargs):
    configure_cmakelists(
        "../CMake/FormatListFile.cmake",
        **kwargs,
        INPUT_FILE="./CMakeLists.txt.in",
        YAML_IN="sample_wrapper.yml",
        CONFIG="sample_conf.yml",
    )

def display_cmakelists(file):
    with open(file,"r",encoding="utf8") as cmakelists:
        for line in cmakelists:
            print(line)

def drive_cmake():
    subprocess.call(["cmake",".."])
    subprocess.call(["cmake", "--build", "."])

def visualize_binding_code(code_dir):
    pth = os.path.abspath("..")
    sys.path.append(pth)
    from .render_binding_code import render
    render(code_dir)
