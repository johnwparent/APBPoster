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

def configure_cmakelists():
    pass

def drive_cmake():
    subprocess.call(["cmake",".."])
    subprocess.call(["cmake", "--build", "."])

def visualize_binding_code(code_dir):
    pth = os.path.abspath("..")
    sys.path.append(pth)
    from render_binding_code import render
    render(code_dir)
