def append_candidates():
    vote_list = []
    count = 1
    while True:
        print('请输入第%d位的候选人：' % (count), end="")
        candidate = input()
        if candidate == 'finish':
            if len(vote_list) != 0:
                break
            else:
                print('请输入候选人！!')
                continue
        elif candidate == 'delete':
            if len(vote_list) != 0:
                count -= 1
                vote_list.pop()
            else:
                print('当前没有候选人，不能删除')
                print('请输入候选人！！')
        else:
            vote_list.append(candidate)
            print('添加候选人成功')
            count += 1
    return vote_list


def append_vote(vote_list):
    votes_name = []
    key_words_list = ['stop', 'delete_last', 'clear', 'menu']
    while 1:
        command = input('输入命令或指定投票给：').strip()
        if command in key_words_list:
            if command == 'stop':
                print('投票已结束')
                break
            elif command == 'delete_lase':
                votes_name.pop()
            elif command == 'clear':
                votes_name = []
            elif command == 'menu':
                print('返回菜单')
        elif command in vote_list:
            votes_name.append(command)
            print('投票%s成功' % (command))
        elif command in (str(i) for i in range(1, len(vote_list) + 1)):
            votes_name.append(vote_list[int(command) - 1])
            print('投票%s成功' % (vote_list[int(command) - 1]))
    return votes_name


def counter(votes_name):
    count_dict = {}
    for i in votes_name:
        if i in count_dict:
            count_dict[i] += 1
        else:
            count_dict[i] = 1
    return count_dict


def sort_by_value(votes, k=None):
    items = votes.items()
    backitems = [[v[1], v[0]] for v in items]
    backitems.sort(reversed=True)
    if k:
        return backitems[:k]
    else:
        return backitems


def describe(votes, temp=False):
    sum_votes = sum([v for v in votes.values()])
    if len(votes) == 0:
        mean_votes = '没有投票，无法计算平均票数'
    else:
        mean_votes = sum_votes / len(votes)
        mean_votes = float('%.2f' % mean_votes)
    if temp is True:
        print('目前总票数为：%s' % (sum_votes))
    else:
        print('总票数：%s' % str(sum_votes))
        print('平均票数：%s' % mean_votes)
    final = sorted(votes.items(), reverse=True)
    for ind, i in enumerate(final):
        if temp is True:
            print('目前的投票第%s名是%s，票数为%d，占总票数：%.2f%%' %
                  (str(ind + 1), i[0], i[1], 100 * i[1] / sum_votes))
        else:
            print('本次的投票第%s名是%s，票数为%s，占总票数：%.2f%%' %
                  (str(ind + 1), i[0], i[1], 100 * i[1] / sum_votes))


def online_voting():
    print("""
    欢迎使用在线投票系统
    使用规则介绍：
    1.启动在线投票系统之后，会出现命令解释，这是在之后的投票过程中的一些功能命令
    2.之后，系统会提醒您输入候选名单名单，例如本次投票的候选名单为（张三、李四），我们需要对其一个一个按顺序输入其名字
    3.输入完信息之后，需要按enter提交
    在线投票系统已启动""")
    print('----------------------------------------')
    print('请输入本次投票的候选人名单')
    print('如果发现候选人名单填错，可以输入delete来删除上一个填入的候选人,输入finish退出，并开始投票')
    vote_list = append_candidates()
    print('本次投票候选人名单为', end="")
    seq_vote_list = [
        str(i) + '.' + vote_list[i] for i in range(len(vote_list))
    ]
    for name in seq_vote_list:
        print('\t', name, end="")
    print()
    print("""请输入候选人名单的内容，或输入其序号，例如输入1代表投票给候选人名单的第一位
    ------------------------------------------------
    投票规则如下：
    1.stop：输入stop结束投票
    2.delete_last：删除上一条投票
    3.clear：删除所有投票
    4.menu：回到菜单选择
    ------------------------------------------------""")
    votes = append_vote(vote_list)
    votes_count = counter(votes)
    print('投票已结束')
    print('-----------------------------------------------')
    print('输出统计信息：')
    describe(votes_count)


online_voting()
