def step217():
    sum = 0
    users = True
    while 1:
        try:
            if users is True:
                print('请1号选手选择：', end="")
                num = int(input())
                if num > 3 or num < 1:
                    raise BaseException
                sum += num
                if sum == 17:
                    print('当前步数为%d，1号选手获胜' % sum)
                    break
                elif sum > 17:
                    sum -= num
                    print('所走步数大于17，请重新输入')
                    continue
                else:
                    users = False
                    print('当前步数为', sum)
            else:
                print('请2号选手选择：', end="")
                num = int(input())
                if num > 3 or num < 1:
                    raise BaseException
                sum += num
                if sum == 17:
                    print('当前步数为%d，2号选手获胜' % sum)
                    break
                elif sum > 17:
                    sum -= num
                    print('所走步数大于17，请重新输入')
                    continue
                else:
                    users = True
                    print('当前步数为', sum)
        except ValueError:
            print('请输入数字')
        except BaseException:
            print('请输入数字1~3', end="")


step217()
