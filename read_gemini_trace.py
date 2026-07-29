import openpyxl

wb = openpyxl.load_workbook('/home/emerald/zaqal/programs/assembly/tage_test_trace_gemini.xlsx')
ws = wb.active

for row in ws.iter_rows(values_only=True):
    order, pc, insn = row[0], row[1], row[2]
    tage = row[14]
    if insn and ('beq' in str(insn) or 'bne' in str(insn)):
        print(f"Order {order}: PC={pc} ({insn}) -> TAGE={tage}")
