import openpyxl
wb = openpyxl.load_workbook('programs/assembly/rtl_test_trace_gemini.xlsx')
ws = wb.active
for row in ws.iter_rows(min_row=2, max_row=45):
    if str(row[0].value) in ['39', '40', '41']:
        print(f"Order {row[0].value} | {row[2].value} | x4={row[7].value} | x17={row[11].value}")
