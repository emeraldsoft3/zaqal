import openpyxl
wb = openpyxl.load_workbook('programs/assembly/tage_test_trace_gemini.xlsx')
sheet = wb.active
for r in range(1, 45):
    row_vals = [sheet.cell(r, c).value for c in range(1, 6)]
    print(f"Row {r:2d}: {row_vals}")
