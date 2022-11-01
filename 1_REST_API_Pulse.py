import requests as req
import json
import math

def find_avg(data, diagnosis_name, doc_id):
    sum = 0
    cnt = 0
    j_data = json.loads(data)
    total_entries = len(j_data['data'])
    if total_entries > 0:
        for i in range(total_entries):
            if int(j_data['data'][i]['doctor']['id']) == doc_id:
                sum += j_data['data'][i]['vitals'][diagnosis_name]
                cnt += 1
    return sum, cnt


main_url = "https://jsonmock.hackerrank.com/api/medical_records"
main_data = req.get(main_url)
main_dict = json.loads(main_data.text)
total_pages = int(main_dict['total_pages'])

total_sum = 0
total_cnt = 0
for i in range(total_pages):
    url = f"{main_url}?page={i}"
    page_data = req.get(url)
    sum, cnt = find_avg(page_data.text, 'pulse', 2)
    print(f"{sum} {cnt}")    
    total_sum += sum
    total_cnt += cnt
print(f"Total Sum: {total_sum} Total Count: {total_cnt}")
print(f"Average: {total_sum/total_cnt}")
print(f"Average: {math.trunc(total_sum/total_cnt)}")
print(f"Average: {int(total_sum/total_cnt)}")
