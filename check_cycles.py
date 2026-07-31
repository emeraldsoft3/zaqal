import openpyxl
wb = openpyxl.load_workbook('programs/assembly/rtl_test_trace_gemini.xlsx')
ws = wb.active
for row in ws.iter_rows(min_row=2, max_row=45):
    order = row[0].value
    insn = row[2].value
    commit = row[4].value
    bru = row[5].value
    print(f"Order {order} | {insn} | PRF Commit: {commit} | BRU Cycle: {bru}")
