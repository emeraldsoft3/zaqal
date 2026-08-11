import openpyxl
wb = openpyxl.load_workbook('programs/assembly/rtl_test_trace_gemini.xlsx')
ws = wb.active
for row in ws.iter_rows(min_row=2, max_row=45):
    print(f"Order {row[0].value} | {row[2].value} | x5={row[8].value} | x14={row[9].value} | PRF Commit={row[4].value}")
