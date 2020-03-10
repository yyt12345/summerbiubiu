student = [['李敏', 15, '男', 7, 2, 3.4], ['赵四', 16, '男', 8, 1, 4.0]]
# ['李艳',15,'女',8,1,3.3],
# ['张晓',17,'女',8,3,4.2]]
student.append(['李艳', 15, '女', 8, 1, 3.3])
student.insert(0, ['张晓', 17, '女', 8, 3, 4.2])

for i in range(len(student)):
    for j in range(len(student) - 1 - i):
        if student[j][5] > student[j + 1][5]:
            temp = student[j]
            student[j] = student[j + 1]
            student[j + 1] = temp
for items in student:
    print('%s的信息是：' % (items[0]))
    print('%d岁，%s性，%d年级%d班，成绩%f' %
          (items[1], items[2], items[3], items[4], items[5]))