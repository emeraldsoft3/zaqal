import sys
sys.path.append('programs/assembly')
from generate_golden_trace_gemini import generate_golden_trace
trace = generate_golden_trace(limit=100)
for r in trace:
    if r['order'] == 37:
        print(f"Order {r['order']} | PC {r['pc']} | TAGE: {r['tage']}")
