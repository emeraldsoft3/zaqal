import sys
sys.path.append('programs/assembly')
from generate_golden_trace_gemini import generate_golden_trace

trace = generate_golden_trace(limit=1000)

print('--- TAGE Activity ---')
tage_t0_alloc = None
tage_t1_alloc = None
tage_t0_hit = None
tage_t1_hit = None

for row in trace:
    if 'beq' in row['instruction'] or 'bne' in row['instruction']:
        tage = row['tage']
        if 'T0' in tage and 'US=0, CTR=3' in tage and tage_t0_alloc is None:
            tage_t0_alloc = row
        if 'T0' in tage and ('CTR=4' in tage or 'CTR=2' in tage or 'US=1' in tage) and tage_t0_hit is None:
            tage_t0_hit = row
        if 'T1' in tage and 'US=0' in tage and tage_t1_alloc is None:
            tage_t1_alloc = row
        if 'T1' in tage and 'US=1' in tage and tage_t1_hit is None:
            tage_t1_hit = row

print(f"First T0 Allocation : Order {tage_t0_alloc['order'] if tage_t0_alloc else 'None'} at PC {tage_t0_alloc['pc'] if tage_t0_alloc else 'None'}")
print(f"First T0 Update/Hit : Order {tage_t0_hit['order'] if tage_t0_hit else 'None'} at PC {tage_t0_hit['pc'] if tage_t0_hit else 'None'}")
print(f"First T1 Allocation : Order {tage_t1_alloc['order'] if tage_t1_alloc else 'None'} at PC {tage_t1_alloc['pc'] if tage_t1_alloc else 'None'}")
print(f"First T1 Update/Hit : Order {tage_t1_hit['order'] if tage_t1_hit else 'None'} at PC {tage_t1_hit['pc'] if tage_t1_hit else 'None'}")

print('\n--- ITTAGE Activity ---')
ittage_t0_alloc = None
ittage_t1_alloc = None
ittage_t0_hit = None
ittage_t1_hit = None

for row in trace:
    if 'jalr' in row['instruction']:
        ittage = row['ittage']
        if 'T0' in ittage and 'US=0' in ittage and ittage_t0_alloc is None:
            ittage_t0_alloc = row
        if 'T0' in ittage and ('US=1' in ittage or 'US=2' in ittage) and ittage_t0_hit is None:
            ittage_t0_hit = row
        if 'T1' in ittage and 'US=0' in ittage and ittage_t1_alloc is None:
            ittage_t1_alloc = row
        if 'T1' in ittage and 'US=1' in ittage and ittage_t1_hit is None:
            ittage_t1_hit = row

print(f"First T0 Allocation : Order {ittage_t0_alloc['order'] if ittage_t0_alloc else 'None'} at PC {ittage_t0_alloc['pc'] if ittage_t0_alloc else 'None'}")
print(f"First T0 Update/Hit : Order {ittage_t0_hit['order'] if ittage_t0_hit else 'None'} at PC {ittage_t0_hit['pc'] if ittage_t0_hit else 'None'}")
print(f"First T1 Allocation : Order {ittage_t1_alloc['order'] if ittage_t1_alloc else 'None'} at PC {ittage_t1_alloc['pc'] if ittage_t1_alloc else 'None'}")
print(f"First T1 Update/Hit : Order {ittage_t1_hit['order'] if ittage_t1_hit else 'None'} at PC {ittage_t1_hit['pc'] if ittage_t1_hit else 'None'}")
