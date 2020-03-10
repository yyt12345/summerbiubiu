def max(a, b):
    if a > b:
        return a
    else:
        return b


def day_in_month(year, month):
    bigmonth = [1, 3, 5, 7, 8, 10, 12]
    if month in bigmonth:
        return 31
    elif month == 2:
        if year % 100 and year % 4 == 0:
            return 29
        elif year % 400 == 0:
            return 29
        else:
            return 28
    else:
        return 30


maxium = 0
for i in range(1, 6):
    print('请输入第%d个数：' % (i), end="")
    num = int(input())
    maxium = max(num, maxium)
print('最大的数是 ', maxium)

print('请输入年份：', end="")
year = int(input())
print('请输入月份：', end="")
month = int(input())
print('这个月有%d天' % (day_in_month(year, month)))
