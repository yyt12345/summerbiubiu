import csv
with open('student.csv', 'w', encoding='utf-8', newline='') as csvfile:
    writer = csv.writer(csvfile)
    with open('student.txt', 'r', encoding='utf-8') as f:
        for line in f.readlines():
            line_list = line.strip('\n').split('  ')
            writer.writerow(line_list)
