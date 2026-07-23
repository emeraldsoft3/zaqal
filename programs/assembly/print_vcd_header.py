def print_header():
    vcd_path = 'programs/vcd/Lithium.vcd'
    with open(vcd_path, 'r') as f:
        for i in range(200):
            line = f.readline()
            if not line:
                break
            print(line.strip())

if __name__ == '__main__':
    print_header()
