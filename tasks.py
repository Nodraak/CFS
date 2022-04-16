from invoke import task

TARGETS = ["Linux", "RTEMS"]

def remove_newlines(s):
    return s.replace("\n", "")

@task
def clean(c):
    c.run("rm -rf build/")

@task
def build(c, target):
    assert target in TARGETS, "%s is not valid" % target

    c.run(remove_newlines(f"""
        mkdir -p build/{target}/
        && cd build/{target}/
            && cmake -D CFS_TARGET="{target}" ../..
            && make demo
    """), pty=True)

@task
def run(c, target):
    assert target in TARGETS, "%s is not valid" % target

    build(c, target)

    c.run(f"build/{target}/src/demo")
