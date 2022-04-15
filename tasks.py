from invoke import task

def remove_newlines(s):
    return s.replace("\n", "")

@task
def clean(c):
    c.run("rm -rf build/")

@task
def build(c):
    c.run(remove_newlines("""
        mkdir -p build/
        && cd build/
            && cmake ..
            && make demo
    """))

@task(build)
def run(c):
    c.run("build/src/demo")
