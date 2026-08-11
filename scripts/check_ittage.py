import openpyxl
wb = openpyxl.load_workbook('programs/assembly/rtl_test_trace_gemini.xlsx')
ws = wb.active
for row in ws.iter_rows(min_row=2, max_row=45):
    if 'jalr' in str(row[2].value):
        print(f"Order {row[0].value} | {row[2].value} | ITTAGE RTL: {row[18].value}")
