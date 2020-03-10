class candidate():
    def __init__(self):
        self.name=[]
        self.votes={}

    def append_vote(self,name,minus_num=1):
        votes[name]+=minus_num
    
    def delete_vote(self,name,minus_num=1):
        votes[name]-=minus_num
    
class tools():
    def status(self,votes):
        sum_votes=sum([v for v in votes.values()])
        try:
            mean_votes=sum_votes/len(votes)
            mean_votes = float('%.2f' % mean_votes)
        except:
            mean_votes = '没有投票，无法计算平均票数'
        if temp is True:
            print('目前总票数为：%s' % (sum_votes))
        else:
            print('总票数：%s' % str(sum_votes))
            print('平均票数：%s' % mean_votes)
        final=sorted(votes.items(),reverse=True)
        for ind, i in enumerate(final):
        if temp is True:
            print('目前的投票第%s名是%s，票数为%d，占总票数：%.2f%%' %
                  (str(ind + 1), i[0], i[1], 100 * i[1] / sum_votes))
        else:
            print('本次的投票第%s名是%s，票数为%s，占总票数：%.2f%%' %
                  (str(ind + 1), i[0], i[1], 100 * i[1] / sum_votes))


    
    def output_csv(self,votes):
        with open('votes.csv','w+',newline='') as f:
            csv_writter=csv.writer(f)
            for k,v in votes.items():
                csv_writter.writerow([k,v])
    
    def input_csv(self):
        vote_dict={}
        with open('vote.csv','r+',newline='') as f:
            for i in readlines():
                name=i.split(',')[0]
                num=int(i.split(',')[1])
                vote_dict[name]=num
        return vote_dict

class process():
    show_candidate(self,votes)
    candidate_name=[
        str(i)+'.'+ votes.name[i] for i in range(len(votes))
    ]


def main():
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

