import os

for root, dirs, files in os.walk('test_run_dir'):
    for f in files:
        print(os.path.join(root, f))
