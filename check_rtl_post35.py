import openpyxl
wb = openpyxl.load_workbook('programs/assembly/rtl_test_trace_gemini.xlsx')
ws = wb.active
for row in ws.iter_rows(min_row=2, max_row=45):
    order_val = row[0].value
    if order_val is not None:
        try:
            order_int = int(order_val)
            if order_int >= 35:
                print(f"Order {order_int} | {row[2].value} | PC {row[1].value} | PRF Commit: {row[4].value} | BRU: {row[5].value} | x4: {row[7].value} | x17: {row[11].value}")
        except ValueError:
            pass
